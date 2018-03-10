# Makefile for Array test suits.
# Email: lijiansong@ict.ac.cn

# Targets
TESTS := tests

# Compiler
#CXX := clang++
CXX := g++

# Boost unit test lib
BOOST_LIB := -lboost_unit_test_framework

# Compiler flags
CXX_FLAGS := -std=c++11 -w 

# Include directories
INC := ../include/

# Rules
test: tests.o
	$(CXX) -o $(TESTS)  $+ $(BOOST_LIB)

tests.o: tests.cpp
	$(CXX) -I $(INC) $(CXX_FLAGS) -o $@ -c $<

clean:
	@rm -rf *.o
	@rm -rf $(TESTS)
