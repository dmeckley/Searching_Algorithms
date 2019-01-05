search : main.o Search.o
	clang++ main.o Search.o -o search

main.o : main.cpp Search.h 
	clang++ -c main.cpp 

Search.o : Search.cpp Search.h
	clang++ -c Search.cpp 

clean : 
	rm -f *.o search