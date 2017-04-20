Skew_Heap: main.o
	g++ -g -std=c++11 main.o  -o minspan
main.o: main.cpp  Kruskal.cpp
	g++ -g -std=c++11 -c main.cpp  Kruskal.cpp
Kruskal.o: Kruskal.cpp
	g++ -g -std=c++11 -c   Kruskal.cpp
skew_heap.o: skew_heap.h skew_heap.hpp
	g++ -Wall -std=c++11 -c skew_heap.hpp
Linkedlist.o: linkedlist.h linkedlist.hpp
	g++ -Wall -std=c++11 -c linkedlist.h
node.o: node.h node.hpp
	g++ -Wall -std=c++11 -c node.h
clean:
	rm *.o *.gch Skew_Heap
tar: clean
	-mkdir Ballard_Lab05
	cp * Ballard_Lab05
	tar cfzv Ballard_Lab05.tar.gz Ballard_Lab05
	-rm -rf Ballard_Lab05
