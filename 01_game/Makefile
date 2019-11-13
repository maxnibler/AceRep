EXDEPS  = ${OBJ}
GENDEPS = roll input screen charStack
CPP     = ${GENDEPS:=.cpp} main.cpp
OBJ     = ${GENDEPS:=.o} main.o
HEAD    = ${GENDEPS:=.h}
GPP     = clang++ -std=gnu++17
FLAG    = -lncurses -Wall -Wextra -Wpedantic -Wold-style-cast
EXEC    = game
MESS    = "generic commit"
GIT     = git commit -am
BIN     = ~/.Scripts/

all : ${EXDEPS}
	${GPP} ${FLAG} -o ${EXEC} ${OBJ}

%.o : %.cpp
	${GPP} ${FLAG} -o $@ -c $<

clean :
	rm ${EXEC}

spotless :
	rm ${OBJ} ${EXEC}

ci :
	${GIT} ${MESS}

deps : ${OBJ}

test :
	./${EXEC}

install : ${EXDEPS}
	${GPP} ${FLAG} -o ${BIN}${EXEC} ${OBJ}
	source ~/.bash_profile
