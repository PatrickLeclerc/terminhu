all: clean build run
clean:	
	rm -rf build
build: 
	mkdir build
	cd build; cmake ..; cmake --build .
run: 
	./build/colors