## Use these variables if SFML is not installed in a standard path.
## Also use these variables if Foxer library couldn't be installed with sudo.

# SFML-DIR = ../SFML-2.5.1

# SFML-INCLUDE = -I $(SFML-DIR)/include
# FOXER-INCLUDE = -I ../foxer/include

# FOXER-LIB-LOCATION = -L ../foxer/lib
# SFML-LIB-LOCATION = -L $(SFML-DIR)/lib

CC = g++
RM = rm -f

FLAGS =
LANGUAGE = c++17
TARGET = sample

INCLUDE = -I ./include

FOXER = -lfoxer

ODIR = ./bin
SRC = ./src

SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
X11 = -lX11
THREADED = -pthread

CPPS = $(wildcard $(SRC)/*.cpp)
OBJS = $(addprefix $(ODIR)/,$(notdir $(CPPS:.cpp=.o)))
FOXEROBJS = $(wildcard $(FOXERODIR)/*.o)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(FLAGS) $(THREADED) -std=$(LANGUAGE) ./$^ $(SFML-LIB-LOCATION) $(FOXER-LIB-LOCATION) $(SFML) $(FOXER) -o $(ODIR)/$@ $(X11)

$(ODIR)/%.o: $(SRC)/%.cpp
	$(CC) $(FLAGS) -c -std=$(LANGUAGE) $(INCLUDE) $(SFML-INCLUDE) $(FOXER-INCLUDE) ./$< -o ./$@

clean :
	$(RM) $(ODIR)/*.o $(ODIR)/$(TARGET)
