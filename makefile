ROOT = .
BIN_PATH = ${ROOT}/bin
INC_PATH = ${ROOT}/include
SRC_PATH = ${ROOT}/src
CPP_STD = c++17
COMPILER = ""

ifeq($OS,Darwin)
	COMPILER += "clang++"
else
	COMPILER += "g++"
endif

tty-type-test: ${SRC_PATH}/main.cpp ${INC_PATH}/word_generator.hpp ${INC_PATH}/argparse.hpp ${INC_PATH}/display.hpp
	${COMPILER} -o ${BIN_PATH}/tty-type-test -I ${INC_PATH} -std=${CPP_STD} -lncurses ${SRC_PATH}/main.cpp 
