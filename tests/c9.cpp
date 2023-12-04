#include <stdio.h>
#include <string.h>
#include <iostream>

typedef struct _car
{
    char name[10];
    int price;
} car;

int main(int argv, char **argc)
{   
    printf("=====000==%d\n", sizeof(car)); //内存对齐, 16字节
    car *p = (car *) malloc(10 * sizeof(car));
    memset(p, 0, 10 * sizeof(car));

    for(int i = 0; i < 10; i++)
    {
        strncpy(p[i].name, "test12345678901234567890", 10);
        p[i].price = 100;
        printf("=====111== name=%s price=%d\n", p[i].name, p[i].price);
    }

    return 0;
}