#ifndef _MESSAGEQ_H_
#define _MESSAGEQ_H_

#define MSGSIZE 128

typedef struct message
{
    long msg_type;
    char msg_text[MSGSIZE];
} message_t;

#endif