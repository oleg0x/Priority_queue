CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra

TARGET = zzz
OBJ = priority_queue.o index_min_pq.o tests.o main.o

.PHONY: all clean  # prevent make from confusing the phony target with a file name

all: $(TARGET)

clean:
	rm -rf $(TARGET) *.o

re: clean all

priority_queue.o: priority_queue.h priority_queue.cpp
	$(CXX) $(CXXFLAGS) -c priority_queue.cpp

index_min_pq.o: index_min_pq.h index_min_pq.cpp
	$(CXX) $(CXXFLAGS) -c index_min_pq.cpp

tests.o: priority_queue.h index_min_pq.h tests.cpp
	$(CXX) $(CXXFLAGS) -c tests.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)
