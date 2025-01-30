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

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1)
    {
        perror("msgget");
        exit(1);
    }

    msg.msg_type = 1;
    snprintf(msg.msg_text, MSGSIZE, "Hello, World!");

    if (msgsnd(msgid, &msg, sizeof(msg.msg_text), 0) == -1)
    {
        perror("msgsnd");
        exit(1);
    }

    printf("Message Sent: %s\n", msg.msg_text);
    return 0;
}
