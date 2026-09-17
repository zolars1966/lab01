CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: app

app: main.o hello.o goodbye.o message.o
	$(CXX) $(CXXFLAGS) -o app main.o hello.o goodbye.o message.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

hello.o: hello.cpp
	$(CXX) $(CXXFLAGS) -c hello.cpp

goodbye.o: goodbye.cpp
	$(CXX) $(CXXFLAGS) -c goodbye.cpp

message.o: message.cpp
	$(CXX) $(CXXFLAGS) -c message.cpp

clean:
	rm -f *.o app