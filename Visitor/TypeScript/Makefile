# created by Ghabriel Nunes <ghabriel.nunes@gmail.com> [2017]

FILES :=$(wildcard *.ts)
EXEC  :=main.js

all:
	@tsc --module amd --outFile $(EXEC) $(FILES)

run: all
	@xdg-open index.html

clean:
	@rm -f $(EXEC)
