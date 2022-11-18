# nome cartella con l'esercizio
DIR = somma

# nome file da compilare, senza estensione
PROGRAM_NAME = main

# nome file da cui compilare il generatore di input, senza estensione
INPUT_NAME = generate-input

# percorso da cui prendere i file da compilare
SRC_PATH = $(DIR)/src/

# percorso in cui mettere gli eseguibili e i file di input / output
# non cambiarlo per ora
BUILD_PATH = $(DIR)/build/


PROGRAM_SRC = $(SRC_PATH)$(PROGRAM_NAME).cpp
PROGRAM_BUILD = $(BUILD_PATH)$(PROGRAM_NAME)
INPUT_SRC = $(SRC_PATH)$(INPUT_NAME).cpp
INPUT_BUILD = $(BUILD_PATH)$(INPUT_NAME)

# compilatore, usato sia per PROGRAM che per INPUT
CC = g++

# flag del compilatore (uguali a quelli usati dal sito del prof)
CFLAGS = -DEVAL -std=gnu++11 -O2 -pipe -static -s


# controllo che build esista, genero il file di input, compilo ed eseguo
all: checkbuild $(INPUT_BUILD) exec


checkbuild:
	@if [ ! -d $(BUILD_PATH) ]; then echo "Build directory not found, creating it"; mkdir $(BUILD_PATH); fi


# tengo l'input aggiornato rispetto al file .cpp che lo genera
$(INPUT_BUILD): $(INPUT_SRC)
	@echo "Generating input..."
	$(CC) $(INPUT_SRC) -o $(INPUT_BUILD)
	./$(INPUT_BUILD) > $(BUILD_PATH)input.txt
	rm $(INPUT_BUILD)
	@echo "Generating input done\n"


# tengo il file eseguibile aggiornato rispetto al .cpp
$(PROGRAM_BUILD): $(PROGRAM_SRC)
	@echo "Compiling..."
	$(CC) $(PROGRAM_SRC) $(CFLAGS) -o $(PROGRAM_BUILD)
	@echo "Compiling done\n"


# entro nella directory in modo che il file di output del programma
# sia generato sotto la directory di build
exec: $(PROGRAM_BUILD)
	@echo "Executing $(PROGRAM_BUILD)..."
	@(cd $(BUILD_PATH); ./$(PROGRAM_NAME))
	@echo "Executing done"