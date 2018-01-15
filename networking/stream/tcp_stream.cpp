#include <arpa/inet.h>
#include "tcpstream.h"

tcp_stream::tcp_stream(int sd, struct sockaddr_in *address) : msd(sd)
{
    char ip[50];
    inet_ntop(PF_INET, (struct in_addr*)&(address->sin_addr.s_addr),
		ip, sizeof(ip)-1);
    m_peer_ip = ip;
    m_peer_port = ntohs(address->sin_port);
}

tcp_stream::~tcp_stream()
{
    close(m_sd);
}

ssize_t tcp_stream::send(const char* buffer, size_t len) 
{
    return write(m_sd, buffer, len);
}

ssize_t tcp_stream::receive(char* buffer, size_t len, int timeout) 
{
    if (timeout <= 0) return read(m_sd, buffer, len);

    if (wait_for_read_event(timeout) == true)
    {
        return read(m_sd, buffer, len);
    }
    return connection_timedout;

}

string tcp_stream::get_peer_ip() 
{
    return m_peer_ip;
}

int tcp_stream::get_peer_port() 
{
    return m_peer_port;
}

bool tcp_stream::wait_for_read_event(int timeout)
{
    fd_set sdset;
    struct timeval tv;

    tv.tv_sec = timeout;
    tv.tv_usec = 0;
    FD_ZERO(&sdset);
    FD_SET(m_sd, &sdset);
    if (select(m_sd+1, &sdset, NULL, NULL, &tv) > 0)
    {
        return true;
    }
    return false;
}
