#ifndef __tcpstream_h__
#define __tcpstream_h__

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>

using namespace std

class tcp_stream
{
    int 	m_sd;
    string 	m_peer_ip;
    int 	m_peer_port;

public:
    friend class tcp_connector;
    friend class tcp_acceptor;

    ~tcp_stream();

    size_t send(char *buffer, size_t len);
    size_t receive(char *buffer, size_t len);

    string 	get_peer_ip();
    int 	get_peer_port();

    enum{
	connectino_closed = 0;
	connection_reset = -1;
	connection_timedout = -2
    };

private:
    bool wait_for_read_event(int timeout);

    tcp_stream(int sd, struct sockaddr_in *addr);
    tcp_stream();
    tcp_stream(const tcp_stream& stream);
};

#endif
