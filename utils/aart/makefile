CXX = g++
CXXFLAGS = -std=c++11 -DDEBUGGING -Wall -Wextra -O2
all: clean aart run
clean:
	rm -f aart
aart: aart.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^
run:
	./aart "TERM"