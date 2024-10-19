a: functions.o main.o
	g++ -fno-elide-constructors -std=c++11 functions.o main.o

main.o: main.cpp functions.h
	g++ -fno-elide-constructors -std=c++11 main.cpp -c

functions.o: functions.cpp functions.h
	g++ -fno-elide-constructors -std=c++11 functions.cpp -c


clean:
	rm -f *.o
	rm -f *.out
	rm -f *.txt