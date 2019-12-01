CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla -g
EXEC = biquadris
OBJECTS = main.o interface.o blinddecorator.o block.o boarddecorator.o board.o boardinfo.o cell.o cellinfo.o cellstate.o celltype.o concreteboard.o coordinate.o forcedecorator.o game.o heavydecorator.o info.o level0.o level1.o level2.o level3.o level4.o level.o observer.o state.o subject.o textdisplay.o graphicsdisplay.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

.PHONY: clean

clean:
	rm -rf ${OBJECTS} ${DEPENDS} ${EXEC}
