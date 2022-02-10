objdir:=obj
srcdir:=src
bindir:=bin

objects:=$(addprefix $(objdir)/,main.o init.o event.o loop.o render.o cleanup.o)

prefix:=/usr/x86_64-w64-mingw32/sys-root/mingw/

CFLAGS:=-I$(prefix)/include/SDL2 -mwindows
LIBS:=-lmingw32 -lSDL2main -lSDL2
CXX:=x86_64-w64-mingw32-g++

bin/main.exe: $(objects)
	$(CXX) -O -Wall -o$@ $^ $(LIBS)
obj/main.o: $(srcdir)/main.cpp
	$(CXX) -O -Wall -o$@ $(CFLAGS) -c $^
obj/init.o: $(srcdir)/init.cpp
	$(CXX) -O -Wall -o$@ $(CFLAGS) -c $^
obj/event.o: $(srcdir)/event.cpp
	$(CXX) -O -Wall -o$@ $(CFLAGS) -c $^
obj/loop.o: $(srcdir)/loop.cpp
	$(CXX) -O -Wall -o$@ $(CFLAGS) -c $^
obj/render.o: $(srcdir)/render.cpp
	$(CXX) -O -Wall -o$@ $(CFLAGS) -c $^
obj/cleanup.o: $(srcdir)/cleanup.cpp
	$(CXX) -O -Wall -o$@ $(CFLAGS) -c $^

.PHONY:
	clean
clean:
	-rm $(objdir)/*.* $(bindir)/*.*

run:
	./bin/main.exe