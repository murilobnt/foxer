### Since makefile isn't the easiest thing to comprehend, I'll comment what
### I do below :D

### And, yes, I took it from my last project. Deal. With. It.

# SECTION: VARIABLES

## The compiler / O compilador
CC = g++

## Additional flags / Flags adicionais
FLAGS =

## Language modifier / Modificador da linguagem
LANGUAGE = c++11

## The executable / O executável
TARGET = gs2d_app

## Headers' inclusion / A inclusão dos headers
INCLUDES = -I ./include

## SFML
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

## Objects directory / O diretório dos objetos
ODIR = ./bin

## Source files directory / O diretório dos arquivos fonte
SRC = ./src

## The source code files / Os arquivos do código fonte
CPPS = $(wildcard $(SRC)/*.cpp)

## Objects required by main / Os objetos requiridos pelo main
OBJS = $(addprefix $(ODIR)/,$(notdir $(CPPS:.cpp=.o)))

## Tests directory / Diretório dos testes
TDIR = ./test

## Test headers, cpps and binaries directories /
## Diretório dos cabeçalhos, cpps e binários dos testes
THDIR = $(TDIR)/headers
TCDIR = $(TDIR)/gen
TBDIR = $(ODIR)/test

## Test headers / Cabeçalhos dos testes
TH = $(wildcard $(THDIR)/*_test.hpp)

## Generated test cpps / Cpps gerados dos testes
TC = $(addprefix $(TCDIR)/,$(notdir $(TH:.hpp=.cpp)))

## Generated test binaries / Binários gerados dos testes
TB = $(addprefix $(TBDIR)/, $(notdir $(basename $(TH))))

# SECTION: GAME COMPILING

## Structure: ENTITY : DEPENDENCY
## Estrutura: ENTIDADE : DEPENDÊNCIA

## About variables: $@ refers to the ENTITY. $< refers to the first DEPENDENCY (set). $^ refers to the entire DEPENDENCY.
## Sobre variáveis: $@ refere-se à ENTIDADE. $< refere-se à primeira DEPENDÊNCIA (conjunto). $^ refere-se a DEPENDÊNCIA inteira.

## For all entries, the dependency is the target file.
## Para todas as entradas, a dependência é o arquivo executável.
all : $(TARGET)

## To satisfy the target file dependency above, we need the objects.
## Para satisfazer a dependência do arquivo executável acima, nós precisamos dos objetos.
$(TARGET) : $(OBJS)
	$(CC) $(FLAGS) -std=$(LANGUAGE) ./$^ $(SFML) -o ./bin/$@

## To satisfy the objects dependency above, we need the source code files.
## Para satisfazer a dependência dos objetos acima, nós precisamos dos arquivos do código fonte.
$(ODIR)/%.o: $(SRC)/%.cpp
	$(CC) $(FLAGS) -c $(INCLUDES) ./$< -o ./$@

## For entry "clean" (make clean), delete the objects and the executable.
## Para a entrada "clean" (make clean), delete os objetos e o executável.
clean :
	$(RM) $(ODIR)/*.o $(ODIR)/$(TARGET)

# SECTION: TESTS COMPILING

## If we have the binaries, it's all done, right?
## Se nós temos os binários, está tudo feito, né?
tests : $(TB)

## To get the binaries, we need the cpps.
## Para conseguir os binários, nós precisamos dos cpps;
$(TB) : $(TC)
	$(CC) -o $(addprefix $(TBDIR)/, $(notdir $(basename ./$<))) ./$<

## To get the cpps, we need the headers.
## Para conseguir os cpps, nós precisamos dos cabeçalhos.
$(TCDIR)/%.cpp : $(THDIR)/%.hpp
	cxxtestgen --error-printer -o ./$@ ./$<

## I guess you know what this does xD (clean tests generated files).
## Acho que você sabe o que isso faz xD (limpa os arquivos de testes gerados).
tclean :
	$(RM) $(TCDIR)/*.cpp $(TBDIR)/*_test
