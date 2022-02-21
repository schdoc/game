objdir:=obj
srcdir:=src
bindir:=bin

#pleasedoitinthisorder:=event_handler anim cleanup entity event init loop render texture main
pleasedoitinthisorder:=$(patsubst $(srcdir)/%.cpp, %, $(wildcard $(srcdir)/*.cpp))
sources:=$(addsuffix .cpp, $(addprefix $(srcdir)/,$(pleasedoitinthisorder)))
objects:=$(patsubst $(srcdir)/%.cpp, $(objdir)/%.o, $(sources))
dlls:=$(addprefix $(bindir)/, SDL2.dll iconv.dll libstdc++-6.dll libgcc_s_seh-1.dll libwinpthread-1.dll)

prefix:=/usr/x86_64-w64-mingw32/sys-root/mingw

CFLAGS:=-O -Wall -I$(prefix)/include/SDL2 -mwindows -g
LIBS:=-lmingw32 -lSDL2main -lSDL2
CXX:=x86_64-w64-mingw32-g++

bin/main.exe: $(objects)
	$(CXX) $(CFLAGS) -o$@ $^ $(LIBS)
$(objdir)/%.o: $(srcdir)/%.cpp
	$(CXX) -o$@ $(CFLAGS) -c $<
$(objdir)/main.o: $(objdir)/event_handler.o $(objdir)/anim.o $(objdir)/entity.o


.PHONY:
	clean
clean:
	-rm $(objdir)/*.* $(bindir)/*.*
$(bindir)/%.dll: $(prefix)/bin/%.dll
	cp $< $(bindir)/
config:
	echo $(wildcard $(srcdir)/*.cpp)
	echo $(patsubst $(srcdir)/%.cpp, $(objdir)/%.o, $(sources))
run: $(dlls)
	./bin/main.exe
debug: $(dlls)
	gdb bin/main.exe
