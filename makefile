all: myapp
myapp: main.o processTable.o pageTable.o pageTableEntry.o memory.o
	g++ -std=c++11 -Wall main.o processTable.o pageTable.o pageTableEntry.o memory.o -o myapp
main.o: main.cpp processTable.cpp pageTable.cpp pageTableEntry.cpp memory.cpp
	g++ -std=c++11 -c -Wall main.cpp processTable.cpp pageTable.cpp pageTableEntry.cpp memory.cpp
processTable.o: processTable.cpp pageTable.cpp
	g++ -std=c++11 -c -Wall processTable.cpp pageTable.cpp
pageTable.o: pageTable.cpp pageTableEntry.cpp
	g++ -std=c++11 -c -Wall pageTableEntry.cpp pageTable.cpp
pageTableEntry.o: pageTableEntry.cpp
	g++ -std=c++11 -c -Wall pageTableEntry.cpp
memory.o: pageTableEntry.cpp memory.cpp
	g++ -std=c++11 -c -Wall pageTableEntry.cpp memory.cpp
clean:
	rm -f *.o
