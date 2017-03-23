main.exe: main.o Graph.o MST.o Edge.o Point.o BCJ.o
	g++ -std=c++11 main.o Graph.o MST.o Edge.o Point.o BCJ.o -o main.exe
MST.o: MST.cpp MST.h
	g++ -std=c++11 -c MST.cpp -o MST.o
Graph.o: Graph.cpp Graph.h Point.h Edge.h
	g++ -std=c++11 -c Graph.cpp -o Graph.o
Point.o: Point.cpp Point.h
	g++ -std=c++11 -c Point.cpp -o Point.o
Edge.o: Edge.cpp Edge.h
	g++ -std=c++11 -c Edge.cpp -o Edge.o
BCJ.o: BCJ.cpp BCJ.h
	g++ -std=c++11 -c BCJ.cpp -o BCJ.o
main.o: main.cpp MST.h Graph.h Point.h Edge.h
	g++ -std=c++11 -c main.cpp -o main.o
clean:
	del *.o *.exe