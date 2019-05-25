CXX= g++ 
CXXFLAGS= -std=c++0x 
LDFLAGS= -lboost_data_time 

SRCS= ant.cpp main.cpp menuClass.cpp

HEADERS= ant.hpp menuClass.hpp

project1: ${SRCS} ${HEADERS}
	${CXX}${CXXFLAGS}${SRCS} -o project1

clean:
	rm *project1 

