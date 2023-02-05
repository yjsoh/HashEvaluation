include ../common/Makefile_common
CFLAGS += -DINPLACE
all:CCEH.so

CCEH.so:CCEH_MSB.cpp CCEH.h 
	$(CXX) $(CFLAGS) -g -fPIC -shared $< -o $@ 
clean:
	rm -f *.o *.so lsb msb
