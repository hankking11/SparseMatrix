project3:	logic.o io.o operators.o project3.o
	g++ -Wall -std=c++11 io.o operators.o logic.o project3.o -o project3
project3.o:	project3.cpp operators.h SparseMatrix.h
	g++ -Wall -std=c++11 -c project3.cpp
logic.o:	logic.cpp logic.h
	g++ -Wall -std=c++11 -c logic.cpp
io.o:	io.cpp io.h 
	g++ -Wall -std=c++11 -c io.cpp
operators.o:	operators.cpp operators.h logic.h io.h SparseMatrix.h
	g++ -Wall -std=c++11 -c operators.cpp
clean:
	rm operators.o io.o logic.o project3
