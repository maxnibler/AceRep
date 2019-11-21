EXDEPS  = ${OBJ}
GENDEPS = utils input screen piece pathing
CPP     = ${GENDEPS:=.cpp} main.cpp
OBJ     = ${GENDEPS:=.o} main.o
HEAD    = ${GENDEPS:=.h}
GPP     = clang++ -std=gnu++17
FLAG    = -Wall -Wextra -Wpedantic -Wold-style-cast
LINK    = -lncurses
EXEC    = game
LOG     = Files/game.log
MESS    = "generic commit"
GIT     = git commit -am
BIN     = ~/.Scripts/

all : ${EXDEPS}
	${GPP} ${LINK} -o ${EXEC} ${OBJ}

%.o : %.cpp
	${GPP} ${FLAG} -o $@ -c $<

clean :
	rm ${EXEC}
	rm ${LOG}

spotless :
	rm ${OBJ} ${EXEC}
	rm ${LOG}

ci :
	${GIT} ${MESS}

deps : ${OBJ}

test :
	./${EXEC}

debug :
	./${EXEC} -l
	cat ${LOG}

install : ${EXDEPS}
	${GPP} ${FLAG} -o ${BIN}${EXEC} ${OBJ}
