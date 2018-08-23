# SECTION: CLEAN COMMANDS ------------------------------------------------------

CLEANENGINE = $(RM) $(BDIR)/*.o $(LDIR)/$(TARGET).a
CLEANCOVERAGE = $(RM) $(CBDIR)/*.o $(CBDIR)/*.gcno $(CBDIR)/*.gcda $(CLDIR)/$(CTARGET).a
CLEANTESTS = find $(TBDIR) -type f -not -name '*.txt' -print0 | xargs -0 rm -f --
CLEANCOVREPORT = $(RM) -r $(LCOV) $(RTARGET)

# SECTION: LIBRARY VARIABLES ---------------------------------------------------

## The compiler
CC = g++

## Additional flags
FLAGS = -c

## Headers' inclusion
INCLUDE = -I ./gs2d/include

## The target's name
TARGET = gs2d

## SFML
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

## Binaries directory
BDIR = ./gs2d/bin

## Library directory
LDIR = ./gs2d/lib

## Source files directory
SRC = ./gs2d/src

## Code coverage dir
CDIR = ./coverage

CBDIR = $(CDIR)/bin

## The source code files
CPPS = $(wildcard $(SRC)/*.cpp)

## Objects required by main
OBJS = $(addprefix $(BDIR)/,$(notdir $(CPPS:.cpp=.o)))

# SECTION: LIBRARY COMPILING ---------------------------------------------------

## Structure: ENTITY : DEPENDENCY

## About variables: $@ refers to the ENTITY. $< refers to the first DEPENDENCY
## (set). $^ refers to the entire DEPENDENCY.

## For all entries, the dependency is the target file: The library.
all : $(TARGET)

## To satisfy the dependency above, we need the objects.
$(TARGET) : $(OBJS)
	ar rs $(LDIR)/$(TARGET).a ./$^

## To satisfy the objects dependency above, we need the source code files.
$(BDIR)/%.o: $(SRC)/%.cpp
	$(CC) $(FLAGS) $(INCLUDE) ./$< -o ./$@

## For entry "clean" (make clean), delete the objects and the executable.
clean :
	$(CLEANENGINE)

# SECTION: COVERAGE OBJECTS ----------------------------------------------------

CTARGET = gs2d_coverage

GCNO = $(addprefix $(CBDIR)/,$(notdir $(CPPS:.cpp=.gcno)))
COBJS = $(addprefix $(CBDIR)/,$(notdir $(CPPS:.cpp=.o)))

CLDIR = $(CDIR)/lib

coverage : $(CTARGET)

$(CTARGET) : $(COBJS)
	ar rs $(CLDIR)/$(CTARGET).a ./$^

$(CBDIR)/%.o: $(SRC)/%.cpp
	$(CC) $(FLAGS) --coverage $(INCLUDE) ./$< -o ./$@

cleancoverage :
		$(CLEANCOVERAGE)

# SECTION: TESTS VARIABLES -----------------------------------------------------

## Important: Change this to the location of Google Test on your PC.
GTDIR = ../googletest

## Google Test include
GTINCLUDE = -I $(GTDIR)/googletest/include

## Path to Google Test library
GTLIB = $(GTDIR)/libgtest.a

## Tests directory
TDIR = ./gs2d/test

## Test source files directory
TSRC = $(TDIR)/src

## Test binaries directory
TBDIR = $(BDIR)/test

## The test target file name
TTARGET = gs2d_tests

## Test source codes
TC = $(wildcard $(TSRC)/*.cpp)

## Generated test objects
TB = $(addprefix $(TBDIR)/, $(notdir $(TC:.cpp=.o)))

# SECTION: TESTS COMPILING -----------------------------------------------------

## For all entries, the dependency is the test target file.
tests : $(TTARGET)

## To get the test target file, the dependency is the binaries.
$(TTARGET) : $(TB)
	$(CC) -pthread --coverage ./$^ $(GTLIB) $(CLDIR)/$(CTARGET).a $(SFML) -o $(TBDIR)/$(TTARGET)

## To get the binaries, the dependency is the source code (and we have them).
$(TBDIR)/%.o : $(TSRC)/%.cpp
	$(CC) $(FLAGS) $(INCLUDE) $(GTINCLUDE) ./$< -o ./$@

## I guess you know what this does xD (clean tests generated files).
cleantests :
	$(CLEANTESTS)

# SECTION: CODE COVERAGE VARIABLES ---------------------------------------------

RTARGET = $(CDIR)/report

LCOV = $(CDIR)/lcov.info

creport : $(RTARGET)

$(RTARGET) : $(LCOV)
	genhtml -o ./$@ ./$<

$(LCOV) :
	lcov -t "gs2d_coverage_report" -o $(CDIR)/lcov.info -c -d $(CBDIR)/.

cleancreport :
	$(CLEANCOVREPORT)

cleaneverything :
		$(CLEANENGINE)
		$(CLEANCOVERAGE)
		$(CLEANTESTS)
		$(CLEANCOVREPORT)
