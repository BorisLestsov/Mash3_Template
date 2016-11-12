CXX			= g++
CFLAGS 		= -Wall -std=c++11 -O2
TARGET 		= Utilitylib

INCL_DIRS	= include include/GL include/VM
INCL_FLAGS	= $(patsubst %,-I %, $(INCL_DIRS))

SRC_DIR		= src
OBJ_DIR 	= obj
SOURCES		= $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS 	= $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o, $(SOURCES))

.PHONY: all clean

all:	$(TARGET)

$(TARGET): $(OBJECTS)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(INCL_FLAGS) $(CFLAGS)  -c -o $@ $<

clean:
	rm -rf obj/*