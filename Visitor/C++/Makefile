FILES :=$(wildcard *.cpp)
EXEC  :=test

all:
	@g++ $(FILES) -o $(EXEC) -std=c++11

run: all
	@./$(EXEC)

clean:
	@rm -f $(EXEC)
