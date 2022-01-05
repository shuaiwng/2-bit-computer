CXX = g++
SRC = 2bit.cpp
OBJ = 2bit.o
EXE = 2bit 
FLAGS = -Wall


$(EXE):$(OBJ)
	$(CXX) $(OBJ) -lstdc++ -o $(EXE)
  
$(OBJ):$(SRC)
	$(CXX) $(FLAGS) -c $(SRC)

clean:
	rm $(OBJ) $(EXE)
