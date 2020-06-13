# Compila programas do curso de OpenGL no ambiente Linux
# Substitua nome_do_programa pelo nome do programa ...
# ...que se está trabalhando
#
# Antes das linhas que contém "gcc...", não pode haver espaço em
# branco e sim uma marca de tabulação
#
# Prof. Marco Antonio
#

# Variables
MESA = /softs/Mesa-6.0
INCPATH = -I$(MESA)/include
LIBPATH = -L$(MESA)/lib
LIBS        = -lglut -lGLU -lGL -lm
CFLAGS  = $(INCPATH) -g
LFLAGS  = $(LIBPATH) $(LIBS)

# Main targets
nome_do_programa: nome_do_programa.o
        gcc -o nome_do_programa nome_do_programa.o $(LFLAGS)

# Source targets
nome_do_programa.o: nome_do_programa.c
        gcc -c nome_do_programa.c $(CFLAGS)

# Clean up
clean:
        rm -f *.o *~

realclean: clean
        rm -f nome_do_programa
