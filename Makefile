SOURCES := $(wildcard *.cpp)
OBJECTS := $(subst .cpp,.o,$(SOURCES))

ejecutable: $(OBJECTS)
	g++ -o $@ $^ -I/usr/include/irrlicht -l Irrlicht
	
%.o: %.cpp
	g++ -o $@ -c $^ -I/usr/include/irrlicht -l Irrlicht

info: 
	$(info $(SOURCES))
	$(info $(OBJECTS))