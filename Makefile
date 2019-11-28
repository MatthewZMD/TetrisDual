CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = a4q4
OBJECTS = main.o blinddecorator.o block.o boarddecorator.o board.o boardinfo.o cell.o cellinfo.o cellstate.o celltype.o concreteboard.o coordinate.o direction.o forcedecorator.o game.o heavydecorator.o info.o level0.o level1.o level2.o level3.o level4.o level.o observer.o state.o status.o subject.o textdisplay.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

.PHONY: clean

clean:
	rm -rf ${OBJECTS} ${DEPENDS} ${EXEC}
