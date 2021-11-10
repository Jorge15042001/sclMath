CC:=g++
OUTPUT=exe
SRC_DIR := src
OBJ_DIR := build/obj
LIB_DIR := ../../build
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LIB_FILES := $(wildcard $(LIB_DIR)/*.o)


CPPFLAGS := -fsanitize=address -fno-omit-frame-pointer
CXXFLAGS := -std=c++2a


 
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p build
	mkdir -p build/obj
	$(CC)   $(CXXFLAGS)  -c -o $@ $^  $(CPPFLAGS)

$(OUTPUT): $(OBJ_FILES) 
	$(CC)  -o $@ $^   $(LIB_FILES) $(CXXFLAGS) $(CPPFLAGS)
clean :
	rm $(OUTPUT)
	rm -rf build
