SOURCES := $(wildcard *.cpp)
OBJECTS := $(subst .cpp,.o,$(SOURCES))
CPPFLAGS := -g
TARGET := ejecutable

$(TARGET): $(OBJECTS)
	g++ -o $@ $^ -I/usr/include/irrlicht -l Irrlicht $(CPPFLAGS)
	
%.o: %.cpp
	g++ -o $@ -c $^ -I/usr/include/irrlicht -l Irrlicht $(CPPFLAGS)

clean:
	rm $(OBJECTS) $(TARGET)

info: 
	$(info $(SOURCES))
	$(info $(OBJECTS))