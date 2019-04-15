#### Note: You must have compiled the engine.
#### To do so, go to the directory above, through console,
#### and type make.

CC = g++
RM = rm -f

FLAGS =
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
	$(CC) $(FLAGS) $(THREADED) -std=$(LANGUAGE) ./$^ $(SFML) $(GS2D) -o $(ODIR)/$@ $(X11)

$(ODIR)/%.o: $(SRC)/%.cpp
	$(CC) $(FLAGS) -c -std=$(LANGUAGE) $(INCLUDE) ./$< -o ./$@

clean :
	$(RM) $(ODIR)/*.o $(ODIR)/$(TARGET)
