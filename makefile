CCFLAGS=--std=c++11 -pedantic -Wall -Werror -ggdb3
exe: hw5_exilien_andre.o zombie_exilien.o# linkedlist_exilien.o
	g++ -o exe $(CCFLAGS) hw5_exilien_andre.o zombie_exilien.o 
hw5_exilien_andre.o: hw5_exilien_andre.cpp
	g++ -c $(CCFLAGS) -o hw5_exilien_andre.o hw5_exilien_andre.cpp

zombie_exilien.o: zombie_exilien.cpp linkedlist_exilien.hpp
	g++ -c $(CCFLAGS) -o zombie_exilien.o zombie_exilien.cpp

# linkedlist_exilien.o:linkedlist_exilien.hpp
# 	g++ -c $(CCFLAGS) -o linkedlist_exilien.o linkedlist_exilien.hpp	

clean:
	rm -f *.o  *~ exe

