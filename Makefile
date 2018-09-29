CXX = g++
RM = rm -f
CXXFLAGS = -Wall -Wno-reorder -O3

SRCS = main.cpp Node.cpp List.cpp ListDp.cpp Queue.cpp Stack.cpp
OBJS = $(subst .cpp,.o,$(SRCS))

TARGET = programa

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Node.o: Node.cpp Node.hpp
	$(CXX) $(CXXFLAGS) -c Node.cpp

List.o: List.cpp List.hpp
	$(CXX) $(CXXFLAGS) -c List.cpp

ListDp.o: ListDp.cpp ListDp.hpp
	$(CXX) $(CXXFLAGS) -c ListDp.cpp

Queue.o: Queue.cpp Queue.hpp
	$(CXX) $(CXXFLAGS) -c Queue.cpp

Stack.o: Stack.cpp Stack.hpp
	$(CXX) $(CXXFLAGS) -c Stack.cpp

clean:
	$(RM) $(OBJS)

distclean:
	$(RM) $(TARGET)