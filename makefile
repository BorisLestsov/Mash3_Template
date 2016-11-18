CXX			= g++
CFLAGS 		= -Wall -std=c++11
TARGET 		= mash3

INCL_DIRS	= Utility/include Utility/include/GL Utility/include/VM SOIL/src
INCL_FLAGS	= $(patsubst %,-I %, $(INCL_DIRS))

SRC_DIR		= source
OBJ_DIR		= obj
BIN_DIR 	= bin

SOURCES		= $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS 	= $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o, $(SOURCES))
UTIL_OBJECTS	= Utility/obj/*
SOIL_OBJECTS	= SOIL/obj/*

EXECUTABLE 	= $(BIN_DIR)/mash3

.PHONY: all clean

all:	$(TARGET)

$(TARGET): $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(MAKE) -C Utility
	$(MAKE) -C SOIL/projects/makefile
	g++ -std=c++11 $(INCL_FLAGS) $(OBJECTS) $(UTIL_OBJECTS) $(SOIL_OBJECTS) -lGL -lglut -lGLEW -o $(EXECUTABLE)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(INCL_FLAGS) $(CFLAGS) -c -o $@ $< -lGLEW -lGLU -lGL -lglut


clean:
	$(MAKE) -C Utility clean
	$(MAKE) -C SOIL/projects/makefile clean
	rm -rf obj
	rm $(EXECUTABLE)
