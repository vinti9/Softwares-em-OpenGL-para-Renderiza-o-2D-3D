# Introdução ao OpenGL

## Bibliotecas

- GLU - OpenGL Utility Library: contém várias rotinas que utilizam os comandos OpenGL de baixo nível para executar tarefas como, por exemplo, definir as matrizes para projeção e orientação da visualização, e fazer o rendering de uma superfície. Esta biblioteca é fornecida como parte de cada implementação de OpenGL, e suas funções usam o prefixo glu [Woo 1999].

- GLUT - OpenGL Utility Toolkit: é um toolkit independente de plataforma, que inclui alguns elementos GUI (Graphical User Interface), tais como menus pop-up e suporte para joystick. Esta biblioteca, escrita por Mark Kilgard, não é domínio público, mas é free. O seu principal objetivo é esconder a complexidade das APIs dos diferentes sistemas de janelas. As funções desta biblioteca usam o prefixo glut. É interessante comentar que a GLUT substitiu a GLAUX, uma biblioteca auxiliar OpenGL que havia sido criada para facilitar o aprendizado e a elaboração de programas OpenGL independente do ambiente de programação (Linux, Windows, etc.) [Woo 1999, Wright 2000].

- GLX - OpenGL Extension to the X Window System: fornecido como um "anexo" de OpenGL para máquinas que usam o X Window System. Funções GLX usam o prefixo glX. Para Microsoft Windows 95/98/NT, as funções WGL fornecem as janelas para a interface OpenGL. Todas as funções WGL usam o prefixo wgl. Para IBM/OS2, a PGL é a Presentation Manager para a interface OpenGL, e suas funções usam o prefixo pgl. Para Apple, a AGL é a interface para sistemas que suportam OpenGL, e as funções AGL usam o prefixo agl [Woo 1999]. 

## Includes

O código abaixo mostra as inclusões típicas para um programa window que usa OpenGL:

```cpp
#include <windows.h> // apenas para windows
#include <stdlib.h>
#include <gl/gl.h>
#include <gl/glu.h>
```

> Headers adequados: <gl/gl.h> e <gl/glu.h> ou <gl/glut.h>

## Tipos de Dados

- Tipo OGL: sufixo [Tipo C]
- GLbyte: b [signed char]
- GLshort: s [short]
- GLint, GLsizei: int ou long [i]
- GLloat, GLclampf: float [f]
- GLdouble, GLclampd: double [d]
- GLubyte, GLboolean: unsigned char [ub]
- GLushort: unsigned short [us]
- GLuint, GLenum, GLbitfield: unsigned long ou unsigned int [ui]

# Máquinas de Estados

 OpenGL é uma máquina de estados, conforme descrito por [Woo 1999]. É possível colocá-la em vários estados (ou modos) que não são alterados, a menos que uma função seja chamada para isto. Por exemplo, a cor corrente é uma variável de estado que pode ser definida como branco. Todos os objetos, então, são desenhados com a cor branca, até o momento em que outra cor corrente é especificada.

OpenGL mantém uma série de variáveis de estado, tais como estilo (ou padrão) de uma linha, posições e características das luzes, e propriedades do material dos objetos que estão sendo desenhados. Muitas delas referem-se a modos que podem ser habilitados ou desabilitados com os comandos glEnable() e glDisable().

Cada variável de estado possui um valor inicial (default) que pode ser alterado. As funções que utilizadas para saber o seu valor são: glGetBooleanv(), glGetDoublev(), glGetFloatv, glGetIntegerv, glGetPointerv() ou glIsEnabled(). Dependendo do tipo de dado, é possível saber qual destas funções deve ser usada [Woo 1999]. O trecho de programa a seguir mostra um exemplo da utilização destas funções.

```cpp
int luz;
glEnable(GL_LIGHTING); 	//Habilita luz - GL_LIGHTING é a variável de estado
luz = glIsEnabled(GL_LIGHTING); // retorna 1 (verdadeiro)
glDisable(GL_LIGHTING); //Desabilita luz
luz = glIsEnabled(GL_LIGHTING); // retorna 0 (falso)
```

# Makefile

Exemplo 1:

```makefile
# CC=g++
LDLIBS=-lglut -lGLEW -lGLU -lGL -lSDL2
all: 01_simple
clean:
	rm -f *.o 01_simple
.PHONY: all clean
```

Exemplo 2:

```makefile
# Variables
MESA = /usr/bin/Mesa-5.0 
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
```

Antes das linhas que contém "gcc...", não pode haver espaço em branco e sim uma marca de tabulação.

Exemplo 3:

```makefile
mygame: main.o player.o enemy.o renderer.o vecmath.o image.o mesh.o
    cc -o mygame main.o player.o enemy.o renderer.o vecmath.o image.o mesh.o -lGL -lglut -lpng -lz -lm

main.o: main.c
    cc -c main.c

player.o: player.c
    cc -c player.c

# ... and so on, and so forth ...
```

Exemplo 4: Makefile para 99% dos programas

```makefile
src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lGL -lglut -lpng -lz -lm

myprog: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) myprog
```

Exemplo 5: Diretórios com multiplos códigos

```makefile
csrc = $(wildcard src/*.c) \
       $(wildcard src/engine/*.c) \
       $(wildcard src/audio/*.c)
ccsrc = $(wildcard src/*.cc) \
        $(wildcard src/engine/*.cc) \
        $(wildcard src/audio/*.cc)
obj = $(csrc:.c=.o) $(ccsrc:.cc=.o)

LDFLAGS = -lGL -lglut -lpng -lz -lm

mygame: $(obj)
    $(CXX) -o $@ $^ $(LDFLAGS)
```

Regras coringa (Wildcar rules)

```makefile
main.o: main.c
    $(CC) $(CFLAGS) -o $@ -c $<
```

Se você deseja informar ao make, na forma genérica de regras para criar arquivos de objetos a partir de arquivos de origem em uma linguagem fictícia `foo`, comumente em arquivos com sufixo `.foo` e compilados executando `fooc -c`, você pode escrever a seguinte regra de curinga:

```makefile
%.o: %.foo
    fooc $(FOOFLAGS) -o $@ -c $<
```

