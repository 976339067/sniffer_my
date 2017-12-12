#file start
CC := gcc
CFLAGS := -Wall -g
TARGET := target
SOURCES = $(wildcard *.c)
OBJS := $(patsubst %.c,%.o, $(SOURCES))
LIBS := -lpcap

all:$(TARGET)

%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@

%.d:%.c
	@set -e; rm -f $@; \
	$(CC) -MM  $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

sinclude $(SOURCES:.c=.d)


$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(TARGET) *.o *.d
#file end
