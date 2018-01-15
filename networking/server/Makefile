CC= g++
CFLAGS= -g -c -Wall -std=c++11
LDFLAGS= 
SRC_STREAM= ../stream
SOURCES= server.cpp $(SRC_STREAM)/tcp_stream.cpp tcp_acceptor.cpp
INCLUDES= -I../include
OBJECTS= $(SOURCES:.cpp=.o)
TARGET= server

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJECTS) $(TARGET)

