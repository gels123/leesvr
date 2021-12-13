#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
 
int main()
{
    //创建socket对象
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    //创建网络通信对象
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9999);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //绑定socket对象与通信链接
    int ret = bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    if(0 > ret)
    {
        printf("bind error\n");
        return -1;
    }
    struct sockaddr_in cli;
    socklen_t len = sizeof(cli);

    char buf[8192];
    while(1)
    {
        memset(buf, 0, sizeof(buf));
        recvfrom(sockfd, &buf, sizeof(buf), 0, (struct sockaddr*)&cli, &len);
        printf("recv data = %s\n", buf);

        sendto(sockfd, &buf, sizeof(buf), 0, (struct sockaddr*)&cli, len);
    }
    close(sockfd);
    
    return 0;
}