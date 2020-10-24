G++ := g++
SRC_DIR := ./src
TARGET := fibonacci

SRCS := $(shell find $(SRC_DIR) -name *.cc)

TXT := $(shell find -name *txt)

FLAGS := $()

$(TARGET): $(OBJS)
	$(G++) -std=c++14 -g -Wall -o $(TARGET) $(SRCS)

.PHONY: clean
clean: 
	$(RM) $(TARGET) $(TXT)

-include $(DEPS)