SYSC_HOME := /usr/local/src/systemc-2.2.0

TARGET := speed_tests
ST_DATATYPE := short

all: $(TARGET).out run

$(TARGET).out : $(TARGET).cpp
	g++ \
		-Wall \
		-D ST_DATATYPE=$(ST_DATATYPE) \
		-I. \
		-I$(SYSC_HOME)/include \
		-L. \
		-L$(SYSC_HOME)/lib-linux \
		-o $(TARGET).out \
		$(TARGET).cpp \
		-lsystemc \
		-lm

run:
	./$(TARGET).out
