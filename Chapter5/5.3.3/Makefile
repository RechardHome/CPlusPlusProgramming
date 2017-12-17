INCLUDE_PATH = -I./
BUILD_DIR = ./build
CPPFLAGS = -std=c++11 -pthread

ALL_OBJ_O = $(BUILD_DIR)/TestThreadParamRet.o
TARGET = $(BUILD_DIR)/testthread_param_ret.run


CC = g++ $(INCLUDE_PATH) $(CPPFLAGS)

start:	prepare $(TARGET)

prepare:
	mkdir -p $(BUILD_DIR)

$(TARGET): $(ALL_OBJ_O)
	$(CC) -o $@  $(ALL_OBJ_O)

$(BUILD_DIR)/TestThreadParamRet.o: ./TestThreadParamRet.cpp
	$(CC) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
	rm -rf ./$(TARGET)

