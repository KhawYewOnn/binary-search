CC = g++ -std=c++11

build/use_binary_search.exe: build/heap_search.o build/normal_binary_search.o build/cache_heap_search.o build/use_binary_search.o
	cd build; $(CC) -o use_binary_search.exe heap_search.o normal_binary_search.o cache_heap_search.o use_binary_search.o

build/use_binary_search.o: src/binary_search.h src/use_binary_search.cpp
	$(CC) -c src/use_binary_search.cpp -o build/use_binary_search.o

build/heap_search.o: src/binary_search.h src/heap_search.cpp
	cd build; $(CC) -c ../src/heap_search.cpp

build/normal_binary_search.o: src/binary_search.h src/normal_binary_search.cpp
	$(CC) -c src/normal_binary_search.cpp -o build/normal_binary_search.o

build/cache_heap_search.o: src/binary_search.h src/cache_heap_search.cpp
	$(CC) -c src/cache_heap_search.cpp -o build/cache_heap_search.o

test: 
	./build/use_binary_search.exe 11 1000000 3 | column -t
	./build/use_binary_search.exe 14 1000000 3 | column -t
	./build/use_binary_search.exe 14 1000000 5 | column -t
	./build/use_binary_search.exe 17 1000000 3 | column -t
	./build/use_binary_search.exe 17 1000000 6 | column -t
	./build/use_binary_search.exe 20 1000000 3 | column -t
	./build/use_binary_search.exe 20 1000000 7 | column -t
	./build/use_binary_search.exe 23 1000000 3 | column -t
	./build/use_binary_search.exe 23 1000000 4 | column -t
	./build/use_binary_search.exe 23 1000000 6 | column -t
	./build/use_binary_search.exe 23 1000000 12 | column -t
