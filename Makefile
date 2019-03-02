OVERLAP=1000
NODE=2000
ENCRYPT=3

THREAD=8

CODE=./src/
OBJ=./bin/
DATA=./data/

CC=g++

bins: 
	@$(CC) -O2 -o $(OBJ)nodeSel $(CODE)nodeSel.cpp
	@$(CC) -O2 -o $(OBJ)graphSplit $(CODE)graphSplit.cpp
	@$(CC) -O2 -o $(OBJ)graphAnonymity $(CODE)graphAnonymity.cpp
	@echo "all compiled"

$(OBJ)nodeSel : $(CODE)nodeSel.cpp
	@g++ -O2 -o $(OBJ)nodeSel $(CODE)nodeSel.cpp

$(OBJ)graphSplit : $(CODE)graphSplit.cpp $(DATA)smallG.txt
	@g++ -O2 -o $(OBJ)graphSplit $(CODE)graphSplit.cpp

$(OBJ)graphAnonymity : $(CODE)graphAnonymity.cpp $(DATA)graph2.txt
	@g++ -O2 -o $(OBJ)graphAnonymity $(CODE)graphAnonymity.cpp 

graph:
	@$(OBJ)nodeSel $(NODE)
	@$(OBJ)graphSplit $(OVERLAP)
	@$(OBJ)graphAnonymity $(ENCRYPT)
	@echo "graphs built"

clean-data:
	@-rm $(DATA)g*.txt
	@-rm $(DATA)pair.txt
	@echo "data clean"

