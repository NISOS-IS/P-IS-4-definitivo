#Fichero: makefile

setups: setup.exe clean

setup.exe: agenda.o profesor.o alumno.o persona.o main.o funcionesAux.o
	g++ -std=c++11 *.o -o setup.exe

main.o: main.cc profesor.h agenda.h alumno.h  funcionesAux.h
	g++ -std=c++11 -c main.cc

agenda.o: agenda.cc agenda.h alumno.h funcionesAux.h
	g++ -std=c++11 -c agenda.cc

alumno.o: alumno.cc alumno.h persona.h funcionesAux.h
	g++ -std=c++11 -c alumno.cc

profesor.o: profesor.cc profesor.h persona.h funcionesAux.h
	g++ -std=c++11 -c profesor.cc

persona.o: persona.cc persona.h funcionesAux.h
	g++ -std=c++11 -c persona.cc

funcionesAux.o: funcionesAux.cc funcionesAux.h persona.h profesor.h alumno.h agenda.h
	g++ -std=c++11 -c funcionesAux.cc

clean:
	rm *.o
