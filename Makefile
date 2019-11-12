OBJ = main.o roll.o input.o screen.o
GPP = clang++
LINK = -lncurses
FLAG = -std=gnu++17 -Wall -Wextra -Wpedantic -Wold-style-cast
EXEC = game
MESS = "generic commit"
GIT = git commit -am

all : ${OBJ}
	${GPP} ${FLAG} ${LINK} -o ${EXEC} ${OBJ}

run:
	./${EXEC}

%.o : %.cpp
	${GPP} ${FLAG} -o $@ -c $<

clean :
	rm ${OBJ}

spotless :
	rm ${OBJ} ${EXEC}

ci :
	${GIT} ${MESS}

deps : ${OBJ}
