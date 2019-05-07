#------------------------------------------------------------------------------
# Makefile for CMPS 101 Programming Assignment 2
#
#       make                   makes Lex
#       make ListClient        makes ListClient
#------------------------------------------------------------------------------

default: FindPath

List.o: List.c List.h
	gcc -c -std=c99 -Wall -g -pg List.c

Graph.o: Graph.c Graph.h List.h
	gcc -c -std=c99 -Wall -g -pg Graph.c

GraphTest.o: GraphTest.c Graph.h List.h
	gcc -c -std=c99 -Wall GraphTest.c

#GraphClient.o: ListClient.c List.h
#	gcc -c -std=c99 -Wall ListClient.c

FindPath.o: FindPath.c Graph.h List.h
	gcc -c -std=c99 -Wall -g -pg FindPath.c

GraphTest: GraphTest.o Graph.o List.o
	gcc -o GraphTest GraphTest.o Graph.o List.o

ListClient: ListClient.o List.o
	gcc -o ListClient ListClient.o List.o

FindPath: FindPath.o Graph.o List.o
	gcc -o FindPath FindPath.o Graph.o List.o

clean:
	rm -f FindPath GraphClient GraphTest *.o *~ \#*\# *.txt *.sh

pa4.sh:
	curl https://raw.githubusercontent.com/sravyapulavarthi/CMPS101-u18-Grading-Scripts/master/pa4/pa4.sh > pa4.sh
	chmod +x pa4.sh

test: pa4.sh
	./pa4.sh
