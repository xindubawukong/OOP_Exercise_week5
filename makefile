main.exe: main.o Graph.o MST.o Edge.o Point.o BCJ.o
	g++ -std=c++11 main.o Graph.o MST.o Edge.o Point.o BCJ.o -o main.exe -g
MST.o: MST.cpp MST.h Graph.h BCJ.h
	g++ -std=c++11 -c MST.cpp -o MST.o -g
Graph.o: Graph.cpp Graph.h Point.h Edge.h
	g++ -std=c++11 -c Graph.cpp -o Graph.o -g
Point.o: Point.cpp Point.h
	g++ -std=c++11 -c Point.cpp -o Point.o -g
Edge.o: Edge.cpp Edge.h
	g++ -std=c++11 -c Edge.cpp -o Edge.o -g
BCJ.o: BCJ.cpp BCJ.h
	g++ -std=c++11 -c BCJ.cpp -o BCJ.o -g
main.o: main.cpp MST.h Graph.h Point.h Edge.h
	g++ -std=c++11 -c main.cpp -o main.o -g
clean:
	del *.o *.exe