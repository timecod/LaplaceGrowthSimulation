CFLAGS = -std=c++20 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lrt -lGL
comp: ./src/main.cpp
	g++ $(CFLAGS) -o ./build/program ./src/main.cpp $(LDFLAGS)

.PHONY: test clean

test: comp
	./build/program

clean:
	rm -f ./build/program

