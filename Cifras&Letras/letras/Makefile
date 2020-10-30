INC = include
OBJ = obj
SRC = src
BIN = bin
CXX = g++ 
CPPFLAGS = -std=c++11 #-Wall -g 

all: cantidadletras letra
	./$(BIN)/cantidadletras datos/spa.txt datos/letras.txt datos/salida.txt
	./$(BIN)/letras datos/spa.txt datos/salida.txt 6 P
	
# ************ Compilación de módulos ************


$(BIN)/letras : $(OBJ)/conjuntoletras.o $(OBJ)/letras.o  $(OBJ)/diccionario.o  $(OBJ)/bolsadeletras.o 
	$(CXX) -o $(BIN)/letras $(OBJ)/conjuntoletras.o $(OBJ)/letras.o  $(OBJ)/diccionario.o  $(OBJ)/bolsadeletras.o 

$(OBJ)/letras.o : $(SRC)/letras.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/letras.o $(SRC)/letras.cpp

$(BIN)/cantidadletras : $(OBJ)/conjuntoletras.o $(OBJ)/cantidadletras.o  $(OBJ)/diccionario.o
	$(CXX) -o $(BIN)/cantidadletras $(OBJ)/conjuntoletras.o $(OBJ)/cantidadletras.o  $(OBJ)/diccionario.o

$(BIN)/bolsadeletras : $(OBJ)/conjuntoletras.o $(OBJ)/bolsadeletras.o 
	$(CXX) -o $(BIN)/bolsadeletras $(OBJ)/conjuntoletras.o $(OBJ)/bolsadeletras.o  

$(OBJ)/cantidadletras.o : $(SRC)/cantidadletras.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/cantidadletras.o $(SRC)/cantidadletras.cpp

$(OBJ)/conjuntoletras.o : $(INC)/conjuntoletras.h $(SRC)/conjuntoletras.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/conjuntoletras.o $(SRC)/conjuntoletras.cpp

$(OBJ)/diccionario.o : $(SRC)/diccionario.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/diccionario.o $(SRC)/diccionario.cpp

$(OBJ)/bolsadeletras.o : $(SRC)/bolsadeletras.cpp
	$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/bolsadeletras.o $(SRC)/bolsadeletras.cpp

# ************ Ejecución ************



cantidadletras : $(BIN)/cantidadletras
	

letra: $(BIN)/letras
	


# ************ Limpieza ************
clean : mrproper
	echo "Limpiando..."
	rm -f $(OBJ)/*.o

mrproper : clean
	rm -f $(BIN)/* doc/html/*
