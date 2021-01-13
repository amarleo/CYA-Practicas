G++ := g++
SRC_DIR := 
TARGET := greedy

SRCS := $(shell find *.cc)

FLAGS := $()

$(TARGET): $(OBJS)
	$(G++) -std=c++14 -g -Wall -o $(TARGET) $(SRCS)

.PHONY: clean
clean: 
	$(RM) $(TARGET)

-include $(DEPS)