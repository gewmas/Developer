#Yuhua Mai, ym59
#Jan 28, 2013

# SRCS = $(wildcard *.c)
# HDRS = $(wildcard *.h)
# OBJS = $(patsubst %.c,%.o,$(SRCS))
CC = g++
# CCFLAGS = -pedantic --std=gnu99 -Wall -Werror
CCFLAGS = -pedantic -Wall -Werror
NAME = numberTranslator


all: $(NAME).o
	$(CC) $(NAME).o -o $(NAME)

$(NAME).o: $(NAME).cpp $(HDRS)
	$(CC) -c $<

.PHONY clean:
	rm -rf *.o *~ $(NAME) break
