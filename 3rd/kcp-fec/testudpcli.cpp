#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdio.h>

int main()
{
    //创建socket对象
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    //创建网络通信对象
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9999);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    char buf[8192];
    while(1)
    {
        printf("请输入字符串：");
        scanf("%s", &buf);
        printf("cli sendto buf=%s\n", buf);
        sendto(sockfd, &buf, sizeof(buf), 0, (struct sockaddr*)&addr, sizeof(addr));

        socklen_t len = sizeof(addr);
        recvfrom(sockfd, &buf, sizeof(buf), 0, (struct sockaddr*)&addr, &len);

        printf("cli recvfrom buf=%s\n", buf);
    }
    close(sockfd);

    return 0;
}