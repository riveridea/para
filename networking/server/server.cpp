#include <stdio.h>
#include <stdlib.h>
#include "tcp_acceptor.h"

int main(int argc, char** argv)
{
    if (argc < 2 || argc > 4) {
        printf("usage: server <port> [<ip>]\n");
        exit(1);
    }

    tcp_stream* stream = NULL;
    tcp_acceptor* acceptor = NULL;
    if (argc == 3) {
        acceptor = new tcp_acceptor(atoi(argv[1]), argv[2]);
    }
    else {
        acceptor = new tcp_acceptor(atoi(argv[1]));
    }
    if (acceptor->start() == 0) {
        while (1) {
            stream = acceptor->accept();
            if (stream != NULL) {
                size_t len;
                char line[256];
                while ((len = stream->receive(line, sizeof(line))) > 0) {
                    line[len] = 0;
                    printf("received - %s\n", line);
                    stream->send(line, len);
                }
                delete stream;
            }
        }
    }
    exit(0);
}
