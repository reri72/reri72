#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

void print_err_with_exit(PGconn *conn)
{
    fprintf(stderr, "error: %s", PQerrorMessage(conn));
    PQfinish(conn);
    exit(1);
}

PGconn *dbcon(const char *conninfo)
{
    PGconn *conn = PQconnectdb(conninfo);
    if (PQstatus(conn) != CONNECTION_OK)
        print_err_with_exit(conn);

    printf("[postgresql connecct success.]\n");

    return conn;
}

PGresult *exec_query(PGconn *conn, const char *query)
{
    PGresult *res = PQexec(conn, query);
    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        PQclear(res);
        print_err_with_exit(conn);
    }

    return res;
}

int main(int argc, char *argv[])
{
    const char *conninfo = "dbname=postgres user=postgres password=wnfjdwnfjd host=localhost port=5432";
    const char *query = "select * from newtable;";
    
    PGconn *conn = dbcon(conninfo);
    PGresult *res = exec_query(conn, query);
    
    int rows = PQntuples(res);
    int cols = PQnfields(res);

    printf("== result rows [%d] ==\n", rows);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%s ", PQgetvalue(res, i, j));
        }
        printf("\n");
    }
    
    PQclear(res);
    PQfinish(conn);

    printf("[postgresql connect closed.]\n");

    return 0;
}
