#include <stdio.h>                                
#include <time.h>
#include <string.h>

void getnowdatetime(void);
int getnowtime(void);

int main(void){
    getnowdatetime();
    printf("getnowtime : %d\n",getnowtime());

    return 0;
}

int getnowtime(void){
    int ltime;
    time_t clock;
    struct tm *date;
    clock = time(0);
    date = localtime(&clock);
    ltime = date->tm_hour*10000;
    ltime += date->tm_min*100;
    ltime += date->tm_sec;

    return(ltime);
}

void getnowdatetime(void){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char* datetime[20] = {0,};

    printf("getnowdatetime : %d-%d-%d %d:%d:%d\n", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}