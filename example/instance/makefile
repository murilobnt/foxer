#### Note: You must have compiled the engine.
#### To do so, go to this project's root directory, through console,
#### and type make.

CC = g++
RM = rm -f

FLAGS = -c
STD = -std=c++17
TARGET = example

GS2DDIR = ../../gs2d

GS2DINCLUDE = -I $(GS2DDIR)/include
INCLUDE = -I ./include

GS2DLIB = $(GS2DDIR)/lib/gs2d.a
ODIR = ./bin

SRC = ./src

SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

CPPS = $(wildcard $(SRC)/*.cpp)
OBJS = $(addprefix $(ODIR)/,$(notdir $(CPPS:.cpp=.o)))
GS2DOBJS = $(wildcard $(GS2DODIR)/*.o)

all : $(TARGET)

$(TARGET) : $(OBJS) $(GS2DLIB)
	$(CC) $(STD) ./$^ $(SFML) -o $(ODIR)/$@

$(ODIR)/%.o: $(SRC)/%.cpp
	$(CC) $(FLAGS) $(STD) $(GS2DINCLUDE) $(INCLUDE) ./$< -o ./$@

clean :
	$(RM) $(ODIR)/*.o $(ODIR)/$(TARGET)
