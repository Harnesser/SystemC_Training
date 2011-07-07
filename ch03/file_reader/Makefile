SYSC_HOME := /usr/local/src/systemc-2.2.0

TARGET := file_reader

all: $(TARGET).out run

$(TARGET).out : $(TARGET).cpp
	g++ \
		-Wall \
		-I. \
		-I$(SYSC_HOME)/include \
		-L. \
		-L$(SYSC_HOME)/lib-linux \
		-o $(TARGET).out \
		$(TARGET).cpp \
		-lsystemc \
		-lm

test:
	g++ -lm \
		-I$(SYSC_HOME)/include \
		-lsystemc \
		-L$(SYSC_HOME)/lib-linux \
		-o test.o $(TARGET).cpp

run:
	./$(TARGET).out
