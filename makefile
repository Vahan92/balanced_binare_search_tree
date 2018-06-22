SOURCES := $(wildcard src/*.cpp) 
OBJECTS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
DEPENDS := $(patsubst src/%.cpp, deps/%.dep, $(SOURCES))

bin/program : $(OBJECTS) 
	@mkdir -p ./bin
	@echo " MAKING..."
	@g++ $(CFLAGS)  $^ -o $@ -std=c++11

obj/%.o : src/%.cpp
	@mkdir -p ./obj
	@g++ $(CFLAGS) -c $< -I./src -o $@ -std=c++11

deps/%.dep: src/%.cpp
	@mkdir -p ./deps
	@g++ -MM $< -MT "$@ $(patsubst deps/%.dep, obj/%.o, $@) " -o $@ -I./src -std=c++11

-include $(DEPENDS)

clean :
	@echo "clean up..."
	@rm -rf obj bin deps
	@rm -rf docs/doxygen
	@rm -f  tests/*.o tests/*.exe 

doxygen :
	@mkdir -p ./docs/doxygen
	@doxygen ./Doxyfile

html : doxygen 
	@firefox ./docs/doxygen/html/index.html

run : bin/program 
	@bin/program 
