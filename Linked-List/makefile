#makefile
CC = g++

#CC = x86_64-w64-mingw32-g++
STD11 = -std=c++11
# -static -g

IDIR = include
SDIR = src
ODIR = obj
BDIR =bin

#TARGETS tree ,list heap



all: $(BDIR)/list.exe

$(ODIR)/%.o: main.cc $(IDIR)/List.h
	$(CC) $(STD11) -c  $<  -o $@



$(BDIR)/list.exe:  $(ODIR)/main.o
	$(CC) $(STD11) -o $@ $<

.phony: clean

clean:
	rm -rf *.exe  $(ODIR)/*














# TEMPLETE FILE
#all: hello

#hello: main.o factorial.o hello.o
#    g++ main.o factorial.o hello.o -o hello

#main.o: main.cpp
#    g++ -c main.cpp

#factorial.o: factorial.cpp
#    g++ -c factorial.cpp

#hello.o: hello.cpp
#    g++ -c hello.cpp

#clean:
#    rm *o hello
