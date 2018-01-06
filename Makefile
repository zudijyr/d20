CC = c++
CXXFLAGS = -O2 -std=c++14
BIN = bin
SRC = src

d20z: main clean

main: dice.o action.o game.o dice.o character.o action.o ability.o effect.o cleave.o warrior.o
	${CC} ${CXXFLAGS} -o ${BIN}/d20z ${SRC}/main.cpp dice.o ability.o effect.o action.o character.o game.o warrior.o cleave.o

game.o: dice.o
	${CC} ${CXXFLAGS} -c ${SRC}/game/game.cpp

warrior.o:
	${CC} ${CXXFLAGS} -c ${SRC}/game/characters/warrior.cpp

cleave.o:
	${CC} ${CXXFLAGS} -c ${SRC}/game/abilities/cleave.cpp

dice.o:
	${CC} ${CXXFLAGS} -c ${SRC}/dice/dice.cpp

character.o: action.o dice.o
	${CC} ${CXXFLAGS} -c ${SRC}/character/character.cpp

action.o: ability.o
	${CC} ${CXXFLAGS} -c ${SRC}/action/action.cpp

ability.o: effect.o
	${CC} ${CXXFLAGS} -c ${SRC}/action/ability.cpp

effect.o:
	${CC} ${CXXFLAGS} -c ${SRC}/action/effect.cpp

clean:
	rm *.o

remove:
	rm ${BIN}/*
