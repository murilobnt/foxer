## Use these variables if SFML is not installed in a standard path.
## Also use these variables if GS2D library couldn't be installed with sudo.

# SFML-DIR = ../SFML-2.5.1

# SFML-INCLUDE = -I $(SFML-DIR)/include
# GS2D-INCLUDE = -I ../gs2d/include

# GS2D-LIB-LOCATION = -L ../gs2d/lib
# SFML-LIB-LOCATION = -L $(SFML-DIR)/lib

CC = g++
RM = rm -f

FLAGS = -O3
LANGUAGE = c++17
TARGET = sample

INCLUDE = -I ./include

GS2D = -lgs2d

ODIR = ./bin
SRC = ./src

SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
X11 = -lX11
THREADED = -pthread

CPPS = $(wildcard $(SRC)/*.cpp)
OBJS = $(addprefix $(ODIR)/,$(notdir $(CPPS:.cpp=.o)))
GS2DOBJS = $(wildcard $(GS2DODIR)/*.o)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(FLAGS) $(THREADED) -std=$(LANGUAGE) ./$^ $(SFML-LIB-LOCATION) $(GS2D-LIB-LOCATION) $(SFML) $(GS2D) -o $(ODIR)/$@ $(X11)

$(ODIR)/%.o: $(SRC)/%.cpp
	$(CC) $(FLAGS) -c -std=$(LANGUAGE) $(INCLUDE) $(SFML-INCLUDE) $(GS2D-INCLUDE) ./$< -o ./$@

clean :
	$(RM) $(ODIR)/*.o $(ODIR)/$(TARGET)
