#include <signal.h>
#include <stdio.h>
 int main(void){
    /* using the default signal handler */
    printf("Exit main1()\n");
    raise(SIGTERM);
    printf("Exit main()\n");
    /* never reached */
    printf("=-------\n");
    return 0;
}