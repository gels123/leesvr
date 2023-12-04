#include <iostream>
#include "hiredis.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    redisContext *c = redisConnect("172.16.10.200", 6379);
    if (c == NULL || c->err) {
        if (c) {
            printf("Error: %s\n", c->errstr);
        } else {
            printf("Can't allocate redis context\n");
        }
        return 1;
    }

    redisReply *reply;
    reply = (redisReply *) redisCommand(c, "SET foo bar");
    printf("SET foo: %s\n", reply->str);
    freeReplyObject(reply);
    reply = (redisReply *) redisCommand(c,"GET foo");
    printf("GET foo: %s\n", reply->str);
    freeReplyObject(reply);

    /* Disconnects and frees the context */
    redisFree(c);

    return 0;
}
