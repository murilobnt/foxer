# SECTION: CLEAN COMMANDS ------------------------------------------------------

CLEANENGINE = $(RM) $(BDIR)/*.o $(LDIR)/$(TARGET).a
CLEANCOVERAGE = $(RM) $(CBDIR)/*.o $(CBDIR)/*.gcno $(CBDIR)/*.gcda $(CLDIR)/$(CTARGET).a
CLEANTESTS = $(RM) $(TBDIR)/*.o $(TBDIR)/$(TTARGET)
CLEANCOVREPORT = $(RM) -r $(LCOV) $(RTARGET)

# SECTION: LIBRARY VARIABLES ---------------------------------------------------

## The compiler
CC = g++-7

## Std library
STD = -std=c++17

## Object flag
OBJ-FLAG = -c

## Headers' inclusion
INCLUDE = -I ../gs2d/include

## The target's name
TARGET = gs2d

## SFML
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

## Binaries directory
BDIR = ../gs2d/bin

## Library directory
LDIR = ../gs2d/lib

## Source files directory
SRC = ../gs2d/src

## Code coverage dir
CDIR = ../coverage

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
	$(CC) $(OBJ-FLAG) $(STD) $(INCLUDE) ./$< -o ./$@

## For entry "clean" (make clean), delete the objects and the executable.
clean :
	$(CLEANENGINE)
