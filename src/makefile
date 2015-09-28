
OPT_FLAGS = -g

CPPFLAGS = $(OPT_FLAGS) -I.

TARGETS = GSObjectTest

GS_OBJECT_TEST_O = GSTypeTag.o GSObject.o GSInteger.o GSBool.o GSCons.o \
	GSObjectTest.o

all: $(TARGETS)

GSObjectTest: $(GS_OBJECT_TEST_O)
	g++ -o GSObjectTest $(GS_OBJECT_TEST_O)

%.o: %.cpp
	g++ -c $(CPPFLAGS) $< -o $@

clean::
	-rm -vf $(TARGETS) *.o
