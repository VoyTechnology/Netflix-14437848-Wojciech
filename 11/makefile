# Compiler: g++ for C++
CC = g++

TARGET = rsa

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	$(CC) $(TARGET).cpp -std=c++11 -lgmp -lgmpxx -o $(TARGET)

clean:
	rm $(TARGET)
