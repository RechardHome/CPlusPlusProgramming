INCLUDE_PATH = -I./
BUILD_DIR = ./build
CPPFLAGS = -std=c++11

ALL_OBJ_O = $(BUILD_DIR)/TestThread.o
TARGET = $(BUILD_DIR)/testthread.run


CC = clang++ $(INCLUDE_PATH) $(CPPFLAGS)

start:	prepare $(TARGET)

prepare:
	mkdir -p $(BUILD_DIR)

$(TARGET): $(ALL_OBJ_O)
	$(CC) -o $@  $(ALL_OBJ_O)

$(BUILD_DIR)/TestThread.o: ./TestThread.cpp
	$(CC) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
	rm -rf ./$(TARGET)

