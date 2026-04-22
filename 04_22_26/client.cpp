#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <limits>
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

void resetStream();

int main(int argc, char *argv[])
{
    addrinfo hints;
    addrinfo *servInfo;
    char s[INET_ADDRSTRLEN];
    int rv; // return value
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if (argc != 2)
    {
        std::cerr << "Usage: ./client <server ip address>" << std::endl;
        return 1;
    }
    try
    {
        rv = getaddrinfo(argv[1], "9431", &hints, &servInfo);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}