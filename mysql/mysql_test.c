#include <stdio.h>
#include <stdlib.h>

#include "mysql/mysql.h"


int main(int argc, char **argv)
{
	MYSQL *conn = NULL;
	MYSQL_RES *res = NULL;
	MYSQL_ROW row;

	// Mysql 객체 초기화
	conn = mysql_init(NULL);
	if (conn == NULL)
	{
		perror("mysql_init");
		return 1;
	}

	// Mysql 서버 연결
	if ( mysql_real_connect(conn, "localhost", "root", "root", "testdb", 0, NULL, CLIENT_COMPRESS | CLIENT_FOUND_ROWS) == NULL)
	{
		fprintf(stderr, "mysql_real_connect() failed: %s\n", mysql_error(conn));
		mysql_close(conn);
		return -1;
	}

	// select 쿼리 실행
	if (mysql_query(conn, "SELECT * FROM books"))
	{
		fprintf(stderr, "query failed: %s\n", mysql_error(conn));
		mysql_close(conn);
		return -1;
	}

	// 결과 저장
	res = mysql_store_result(conn);
	if (res == NULL)
	{
		fprintf(stderr, "mysql_store_result() failed: %s\n", mysql_error(conn));
		mysql_close(conn);
		return -1;
	}

	int num_fields = mysql_num_fields(res); // 컬럼 개수 확인
	MYSQL_FIELD *fields = mysql_fetch_fields(res);  // 컬럼 메타데이터
	
	int i = 0;
	for (i = 0; i < num_fields; i++)
	{
		printf("%s(%d) \t", fields[i].name, fields[i].type);
		switch (fields[i].type)
		{
			case FIELD_TYPE_VAR_STRING:
				printf("type varchar \n");
				break;
			case FIELD_TYPE_STRING:
				printf("type string \n");
				break;
			case FIELD_TYPE_TINY:
				printf("type bool or tinyint \n");	// bool형은 tinyint(1) 로 처리되어서 정확히 판단을 못 함. 값으로 확인해야 할 듯
				break;
			case FIELD_TYPE_LONG:
				printf("type long \n");
				break;
			case FIELD_TYPE_DOUBLE:
				printf("type double \n");
				break;
			case FIELD_TYPE_DATE:
				printf("type date \n");
				break;
			case FIELD_TYPE_TIMESTAMP:
				printf("type timestamp \n");
				break;
			default:
				printf("type is unknown \n");
		}
	}
	printf("\n--------------------------------\n");

	// 실 데이터 출력
	while ((row = mysql_fetch_row(res)))
	{
		for (i = 0; i < num_fields; i++)
		{
			printf("%s \t", row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}

	// 자동 커밋 끄기
	if (mysql_autocommit(conn, 0))
	{
		fprintf(stderr, "mysql_autocommit() failed: %s\n", mysql_error(conn));
		mysql_free_result(res);
		mysql_close(conn);
		return -1;
	}

	// insert문 실행
	if (mysql_query(conn, "insert into books values('hoho', 2222, now(), true)"))
	{
		fprintf(stderr, "insert failed: %s\n", mysql_error(conn));
		// 단일 쿼리니까 mysql_rollback(conn) 는 생략.
	}
	else
	{
		mysql_commit(conn);	// 커밋 실행
	}

	// 리소스 해제
	if (res != NULL)
		mysql_free_result(res);
	
	mysql_close(conn);

	return 0;
}

