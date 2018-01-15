CC= g++
CFLAGS= -g -c -Wall 
LDFLAGS= 
SOURCES= tcpstream.cpp 
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

