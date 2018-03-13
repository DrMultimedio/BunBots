SOURCES := $(wildcard *.cpp)
OBJECTS := $(subst .cpp,.o,$(SOURCES))

ejecutable: $(OBJECTS)
	g++ -o $@ $^ 
	
%.o: %.cpp
	g++ -o $@ -c $^ -I/usr/include/irrlicht -l Irrlicht

info: 
	$(info$(SOURCES))
	$(info$(OBJECTS))