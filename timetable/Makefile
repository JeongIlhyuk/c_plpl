CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = timetable
SRCS = main.cpp timetable.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = header.h timetable.h

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c main.cpp

timetable.o: timetable.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c timetable.cpp

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean