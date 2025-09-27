
CXX = g++
# CXXFLAGS = -Iinclude -Wall -std=c++17 -lhidapi-libusb
CXXFLAGS = -Iinclude -Wall -std=c++17 -lhidapi-hidraw -g
SRC = src/main.cpp src/animectl.cpp src/helpers.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = build/animectl

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
