#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "messageq.h"

int main(int argc, char **argv)
{
    key_t key;
    int msgid = -1;
    message_t msg;

    key = ftok("/tmp/mqtest", 1);
    if (key == -1)
    {
        perror("ftok");
        exit(1);
    }

    msgid = msgget(key, 0666);
    if (msgid == -1)
    {
        perror("msgget");
        msgctl(msgid, IPC_RMID, NULL);
        exit(1);
    }

    if (msgrcv(msgid, &msg, sizeof(msg.msg_text), 0, 0) == -1)
    {
        perror("msgrcv");
        msgctl(msgid, IPC_RMID, NULL);
        exit(1);
    }
    
    printf("Received Message: %s\n", msg.msg_text);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
