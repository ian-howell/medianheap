###############################################################################
# -->Makefile<--
###############################################################################

###############################################################################
#
# Programmer :  Rob Wiehage
# Modified by:  Billy Rhoades
# Assignment :  Program 4
#
# Instructor :  Dr. Michael Hilgers
# Course     :  CS236 Winter 2001
# Semester   :  Fall 2001
#
###############################################################################

###############################################################################
# This makefile will build an executable for the assignment.
###############################################################################

.PHONY: all clean coverage

CXX = /usr/bin/g++
CXXFLAGS = -g -Wall -W -pedantic-errors -std=c++11

# The following 2 lines only work with gnu make.
# It's much nicer than having to list them out,
# and less error prone.
SOURCES = $(wildcard [^(test_)]*.cpp)
TEST_SOURCES = $(wildcard [(test_)]*.cpp)
HEADERS = $(wildcard *.h)

# With Sun's make it has to be done like this, instead of
# using wildcards.
# Well, I haven't figured out another way yet.
#SOURCES = signal.cpp tokentype.cpp token.cpp tokenlist.cpp driver.cpp
#HEADERS = signal.h tokentype.h token.h tokenlist.h

# Looks like it can be done like this, but won't work for gmake.
#SOURCES:sh = ls *.cpp
#HEADERS:sh = ls *.h

OBJECTS = $(SOURCES:%.cpp=%.o)
TEST_OBJECTS = $(TEST_SOURCES:%.cpp=%.o)

default: driver

%.o: %.cpp
	@echo "Compiling $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

driver: $(OBJECTS)
	@echo "Building $@"
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@
	@echo ""
	@echo "Everything worked :-) "
	@echo ""

test: testsuite
	-@./testsuite

testsuite: ${TEST_OBJECTS}
	@${CXX} ${CXXFLAGS} $^ -o $@

coverage: CXXFLAGS = -Wall -Werror -pedantic-errors -std=c++11 -fprofile-arcs -ftest-coverage
coverage: clean testsuite
	@./testsuite
	gcov -r ${TEST_SOURCES}

clean:
	-@rm -f core
	-@rm -f driver
	-@rm -f testsuite
	-@rm -f "depend"
	-@rm -f *.gcno
	-@rm -f *.gcda
	-@rm -f *.gcov
	-@rm -f $(OBJECTS)
	-@rm -f $(TEST_OBJECTS)

# Automatically generate dependencies and include them in Makefile
depend: $(TEST_SOURCES) $(SOURCES) $(HEADERS)
	@echo "Generating dependencies"
	@$(CXX) -MM *.cpp > $@


-include depend
# Put a dash in front of include when using gnu make.
# It stops gmake from warning us that the file
# doesn't exist yet, even though it will be properly
# made and included when all is said and done.
