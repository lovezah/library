CXX = g++
CXXFLAGS = -O2 -std=c++20 -DLOCAL -Wl,--stack,268435456

all: $(TARGET)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGET)