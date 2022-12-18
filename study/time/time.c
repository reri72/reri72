#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

int main(void){

    /*  time :  현재 시간 리턴  */
    /*  difftime : 두 시간의 차이 리턴  */
    time_t timetest, timedifftest;

    time(&timetest);
    printf("%d \n", timetest);

    Sleep(1000);

    time(&timedifftest);
    printf("%d \n", timedifftest);
    printf("%0.0f \n", difftime(timedifftest, timetest) );


    /*   localtime : 시간 값을 초 단위로 유형 tm의 구조로 변환   */
    time_t tnow;    struct tm* t;   // Since 1970.01.01. 00:00:00
    time(&tnow);
    t = (struct tm*) localtime(&tnow);
    
    printf("year : %d \n", t->tm_year+1900);
    printf("mon : %d \n", t->tm_mon+1);
    printf("day : %d \n", t->tm_mday);
    printf("hour : %d \n", t->tm_hour);
    printf("min : %d \n", t->tm_min);
    printf("sec : %d \n", t->tm_sec);


    /*   ctime  : 시간을 문자열로 반환   */
    time_t ctimetest;
    time(&ctimetest);
    printf("ctime : %s", ctime(&ctimetest));


    /*   asctime : tm 구조체 활용, 시간을 문자열로 반환    */
    time_t rawtime;    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("asctime: %s", asctime(timeinfo));


    /*   gmtime : UTC 형식 시간에 따른 tm 구조체를 만들어 리턴    */
    time_t gmtimetest;    time(&gmtimetest);
    printf ( "gmtime : %s\n", asctime(gmtime(&gmtimetest)) );


    /*  mktime : tm 구조체를 time_t 형식으로 변환  */
    time_t mkrawtime;
    struct tm* mktimeinfo;
    int year = 2022, month = 2, day = 14;
    char* weekday[] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                     "Thursday", "Friday", "Saturday"};

    time(&mkrawtime);

    mktimeinfo = localtime(&mkrawtime);
    mktimeinfo->tm_year = year - 1900;
    mktimeinfo->tm_mon = month - 1;
    mktimeinfo->tm_mday = day;

    mktime(mktimeinfo);
    printf("weekday : %s. tm_yday : %d \n", weekday[mktimeinfo->tm_wday], weekday[mktimeinfo->tm_yday]);

    return 0;
}
