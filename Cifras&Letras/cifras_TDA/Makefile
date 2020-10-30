INC = .
OBJ = .
SRC = .
BIN = .
CXX = g++
CPPFLAGS = #-Wall -g


all: $(BIN)/cifras


# ************ Compilación de módulos ************

$(BIN)/cifras : $(SRC)/cifras.cpp
	$(CXX) -o $(BIN)/cifras $(SRC)/cifras.cpp



# ************ Limpieza ************
run : $(BIN)/cifras
	./cifras 

clean :
	echo "Limpiando..."
	rm -f cifras

mrproper : clean
	rm -f cifras
