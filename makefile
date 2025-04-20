CXX = g++
CXXFLAGS = -Wall -g

MatrixCPP: Matrix.o driver.cpp
		$(CXX) $(CXXFLAGS) Matrix.o driver.cpp -o MatrixCPP

Matrix.o: Matrix.cpp  Matrix.h
		$(CXX) $(CXXFLAGS) -c Matrix.cpp

run:
		./MatrixCPP

val:
		valgrind ./MatrixCPP

clean:
		rm *~
		rm *.

debug1:
		gdb gdbarg1 --args ./MatrixCPP