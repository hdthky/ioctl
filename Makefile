SRCS = ioctl.c
CFLAGS = -O2 -g -static
TARGET = ioctl

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

all: $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

install:
	cp ioctl /usr/local/bin/
