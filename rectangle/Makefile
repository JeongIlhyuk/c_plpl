# 컴파일러 설정
CXX = clang++  # Mac은 보통 clang을 사용
CXXFLAGS = -std=c++11 -Wall

# 현재 디렉토리의 모든 소스 파일
SRCS = ./Point.cpp ./Rectangle.cpp ./RectangleFaultFind.cpp
OBJS = Point.o Rectangle.o RectangleFaultFind.o

# 실행 파일 이름
TARGET = rec

# 기본 타겟
all: $(TARGET)

# 실행 파일 생성 규칙
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

Point.o: Point.cpp
	$(CXX) $(CXXFLAGS) -c Point.cpp

Rectangle.o: Rectangle.cpp
	$(CXX) $(CXXFLAGS) -c Rectangle.cpp

RectangleFaultFind.o: RectangleFaultFind.cpp
	$(CXX) $(CXXFLAGS) -c RectangleFaultFind.cpp

# 청소
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean