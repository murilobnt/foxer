## Use these variables if SFML is not installed in a standard path.
# SFML-DIR = SFML-2.5.1
# SFML-INCLUDE = -I $(SFML-DIR)/include

# SECTION: CLEAN COMMANDS ------------------------------------------------------

CLEANENGINE = $(RM) $(BDIR)/*.o $(LDIR)/$(TARGET)

# SECTION: LIBRARY VARIABLES ---------------------------------------------------

## The compiler
CC = g++

## Std library
STD = -std=c++17

## Object flag
OBJ-FLAG = -c

OPTIMIZATION = -O3

## Headers' inclusion
INCLUDE = -I ./gs2d/include

## The target's name
TARGET = libgs2d.so

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

$(TARGET) : $(LDIR)/$(TARGET)

## To satisfy the dependency above, we need the objects.
$(LDIR)/$(TARGET) : $(OBJS)
	$(CC) -shared ./$^ -o $(LDIR)/$(TARGET)

## To satisfy the objects dependency above, we need the source code files.
$(BDIR)/%.o: $(SRC)/%.cpp
	$(CC) -fPIC $(OPTIMIZATION) $(OBJ-FLAG) $(STD) $(INCLUDE) $(SFML-INCLUDE) ./$< -o ./$@

## For entry "clean" (make clean), delete the objects and the executable.
clean :
	$(CLEANENGINE)

install : $(TARGET)
	cp gs2d/lib/libgs2d.so /usr/local/lib && chmod 755 /usr/local/lib/libgs2d.so
	cp -r gs2d/include/gs2d /usr/local/include && chmod -R 755 /usr/local/include/gs2d

uninstall :
	rm /usr/local/lib/libgs2d.so
	rm -r /usr/local/include/gs2d
