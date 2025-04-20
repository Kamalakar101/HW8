CXX = g++
CXXFLAGS = -Wall -g

proj0: Matrix.o driver.cpp
		$(CXX) $(CXXFLAGS) Matrix.o driver.cpp -o MatrixCPP

solitaire.o: Matrix.cpp  Matrix.h
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