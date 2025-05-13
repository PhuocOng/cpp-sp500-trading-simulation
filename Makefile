CXX = g++
CXXFLAGS = -std=c++17 -Wall
OBJS = main.o sp500_data.o portfolio.o auth.o

all: tracker

tracker: $(OBJS)
	$(CXX) $(CXXFLAGS) -o tracker $(OBJS) -lssl -lcrypto

main.o: main.cpp auth.h
	$(CXX) $(CXXFLAGS) -c main.cpp

sp500_data.o: sp500_data.cpp sp500_data.h
	$(CXX) $(CXXFLAGS) -c sp500_data.cpp

portfolio.o: portfolio.cpp portfolio.h sp500_data.h
	$(CXX) $(CXXFLAGS) -c portfolio.cpp

auth.o: auth.cpp auth.h
	$(CXX) $(CXXFLAGS) -c auth.cpp

clean:
	rm -f *.o tracker