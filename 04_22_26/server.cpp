#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <bits/stdc++.h>

const int BACKLOG = 10;

int main(int argc, char *argv[])
{
    int sockfd;
    int clientfd;
    addrinfo hints;
    addrinfo *servInfo;
    addrinfo *p;
    int rv;      // return value
    int yes = 1; // reuse port
    socklen_t sin_size;
    sockaddr_storage their_addr;
    char s[INET_ADDRSTRLEN];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;       // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP socket
    hints.ai_flags = AI_PASSIVE;     // use my IP
    try
    {
        rv = getaddrinfo(NULL, "9431", &hints, &servInfo);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}