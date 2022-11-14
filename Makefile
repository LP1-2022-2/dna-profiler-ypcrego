all: ./bin/dna_profiler

CXX = clang++
override CXXFLAGS += -I./bin/ -I./src/ -I./include/ -g -Wno-everything

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

./bin/dna_profiler: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o "$@"

./bin/dna_profiler-debug: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -O0 $(SRCS) -o "$@"

clean:
	rm -f ./bin/dna_profiler ./bin/dna_profiler-debug