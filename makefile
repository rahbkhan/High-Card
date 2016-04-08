
all: play

clean:
	-rm cards.o play

play: cards.o
	g++ -g -o play cards.o
	
cards.o: cards.cpp
	g++ -c -g cards.cpp
