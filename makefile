main.exe: main.o Graph.o MST.o
	g++ main.o Graph.o MST.o -o main.exe
MST.o: MST.cpp MST.h
	g++ -c MST.cpp -o MST.o
Graph.o: Graph.cpp Graph.h
	g++ -c Graph.cpp -o Graph.o
main.o: main.cpp
	g++ -c main.cpp -o main.o
clean:
	del *.o *.exe