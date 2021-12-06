#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

int main()
{
    float time_use=0;
    struct timeval start;
    struct timeval end;

    gettimeofday(&start,NULL); //gettimeofday(&start,&tz);结果一样
    printf("start.tv_sec:%d\n",start.tv_sec);
    printf("start.tv_usec:%d\n",start.tv_usec);

    int i = 100000000;
    while(i--);

    gettimeofday(&end,NULL);
    printf("end.tv_sec:%d\n",end.tv_sec);
    printf("end.tv_usec:%d\n",end.tv_usec);

    time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
    printf("time_use is %.10f\n",time_use);
}