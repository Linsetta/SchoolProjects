#------------------------------------------------------------------------------
#  Makefile for CMPS 101 Programming Assignment 5
#
#  make                     makes FindComponents
#  make GraphClient         makes GraphClient
#  make clean               removes binaries
#  make checkFind           tests FindComponents for memory leaks on in3
#  make checkClient         tests GraphClient for memory leaks
#------------------------------------------------------------------------------

BASE_SOURCES   = Graph.c List.c
BASE_OBJECTS   = Graph.o List.o
HEADERS        = Graph.h List.h
COMPILE        = gcc -c -std=c99 -Wall -Werror -g -pg
LINK           = gcc -o
REMOVE         = rm -f
MEMCHECK       = valgrind --error-exitcode=123 --leak-check=full

FindComponents : FindComponents.o $(BASE_OBJECTS)
	$(LINK) FindComponents FindComponents.o $(BASE_OBJECTS)

GraphClient : GraphClient.o $(BASE_OBJECTS)
	$(LINK) GraphClient GraphClient.o $(BASE_OBJECTS)

GraphTest : GraphTest.o $(BASE_OBJECTS)
	$(LINK) GraphTest GraphTest.o $(BASE_OBJECTS)

FindComponents.o : FindComponents.c $(HEADERS)
	$(COMPILE) FindComponents.c

GraphClient.o : GraphClient.c $(HEADERS)
	$(COMPILE) GraphClient.c

$(BASE_OBJECTS) : $(BASE_SOURCES) $(HEADERS)
	$(COMPILE) $(BASE_SOURCES)

clean :
	$(REMOVE) FindComponents GraphClient FindComponents.o GraphClient.o $(BASE_OBJECTS) *~

checkFind : FindComponents
	$(MEMCHECK) FindComponents in3 junk3

checkClient : GraphClient
	$(MEMCHECK) GraphClient

test: FindComponents
	$(MEMCHECK) FindComponents in/in1 out/out1
	$(MEMCHECK) FindComponents in/in2 out/out2
	$(MEMCHECK) FindComponents in/in3 out/out3
	$(MEMCHECK) FindComponents in/in4 out/out4
	$(MEMCHECK) FindComponents in/in5 out/out5
	$(MEMCHECK) FindComponents in/in6 out/out6
	$(MEMCHECK) FindComponents in/in7 out/out7
	diff -Z out/out1 model-out/out1
	diff -Z out/out2 model-out/out2
	diff -Z out/out3 model-out/out3
	diff -Z out/out4 model-out/out4
	diff -Z out/out5 model-out/out5
	diff -Z out/out6 model-out/out6
	diff -Z out/out7 model-out/out7
