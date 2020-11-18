G++ := g++
SRC_DIR := ./src
TARGET := dfa_simulation

SRCS := $(shell find $(SRC_DIR) -name *.cc)

FLAGS := $()

$(TARGET): $(OBJS)
	$(G++) -std=c++14 -g -Wall -o $(TARGET) $(SRCS)

.PHONY: clean
clean: 
	$(RM) $(TARGET)

-include $(DEPS)