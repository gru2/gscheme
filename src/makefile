
OPT_FLAGS = -g

CPPFLAGS = $(OPT_FLAGS) -I. -I../ext/gmisc

TARGETS = GSObjectTest

GS_OBJECT_TEST_O = GSTypeTag.o GSObject.o GSInteger.o GSBool.o GSCons.o \
	GSObjectTest.o GSMemoryManager.o GSParser.o \
	../ext/gmisc/InputStream.o ../ext/gmisc/ErrorReporter.o \
	../ext/gmisc/SourceCodePosition.o

GS_PARSER_TEST_O = 


all: $(TARGETS)

GSObjectTest: $(GS_OBJECT_TEST_O)
	g++ -o GSObjectTest $(GS_OBJECT_TEST_O)

%.o: %.cpp
	g++ -c $(CPPFLAGS) $< -o $@

clean::
	-rm -vf $(TARGETS) *.o
