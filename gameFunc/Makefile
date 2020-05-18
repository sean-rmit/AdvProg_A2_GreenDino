.default: all

all: azul

clean:
	rm -f azul log.txt *.o

azul: TileBag.o Player.o BoxLid.o BrokenTiles.o Centre.o Factories.o Factory.o game.o Line.o main.o Mosaic.o pages.o PatternLines.o utils.o Wall.o LoadSaveFile.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^