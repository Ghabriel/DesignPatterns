# created by Ghabriel Nunes <ghabriel.nunes@gmail.com> [2017]

FILES :=$(wildcard *.cpp)
EXEC  :=test

all:
	@g++ $(FILES) -o $(EXEC) -std=c++11

run: all
	@./$(EXEC)

clean:
	@rm -f $(EXEC)
