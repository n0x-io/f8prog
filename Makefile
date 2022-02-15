## Compiler settings
CC			= cc
CFLAGS  	= -Wall -Werror -g -std=c99 -lcjson
LDFLAGS 	=

## Project settings
TARGET		= f8prog		## name of the application

## Paths
SRC 	= $(wildcard src/*.c)
OFILES  = $(patsubst src%, build%, $(patsubst src/%.c, build/%.o, $(SRC)))


$(TARGET): ./build $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(TARGET) $(LDFLAGS)

%.o: ../src/%.c 
	$(CC) $(CFLAGS) -c $^ -o $@
 
./build:
	mkdir -p $@

clean:
	rm -rf $(OFILES) 
	rm -f $(TARGET) 
	rm -rf ./build

test: $(TARGET)
	./$(TARGET)

options:
	@echo $(TARGET) build options:
	@echo "CFLAGS	= ${CFLAGS}"
	@echo "LDFLAGS	= ${LDFLAGS}"
	@echo "CC		= ${CC}"

.PHONY: options clean test
