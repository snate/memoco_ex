CC = g++
CPPFLAGS = -g -Wall -O2 -std=c++11
LDFLAGS =

OBJ = TSPPopulation.o TSPSelector.o TSPRecombinator.o TSPReplacer.o TSPSolver.o main.o

%.o: %.cpp
		$(CC) $(CPPFLAGS) -c $^ -o $@

main: $(OBJ)
		$(CC) $(CPPFLAGS) $(OBJ) -o main
		
clean:
		rm -rf $(OBJ) main

.PHONY: clean
