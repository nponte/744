FOLDER		:= .

EXECUTABLE	:= visual

CU_FILES 	:=

CU_DEPS 	:=

CC_FILES 	:= videoreader.cpp main.cpp

############################################

ARCH=$(shell uname | sed -e 's/-.*//g')

OBJDIR=$(FOLDER)/objs
CXX=g++ -m64 -std=c++11
CXXFLAGS=-O3 -Wall
ifeq ($(ARCH), Darwin)
# Building on mac
LDFLAGS=-L/usr/local/depot/cuda-8.0/lib/ -lcudart
else
# Building on Linux
LDFLAGS=-L/usr/local/cuda/lib64/ -lcudart
endif
NVCC=nvcc
NVCCFLAGS=-O3 -m64 --gpu-architecture compute_35

OBJS=$(OBJDIR)/videoreader.o $(OBJDIR)/main.o


.PHONY: dirs clean

default: $(EXECUTABLE)

dirs:
				mkdir -p $(OBJDIR)/

clean:
				rm 0rf $(OBJDIR) *.ppm *~ $(EXECTUABLE)

$(EXECUTABLE): 	dirs $(OBJS)
	             $(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

$(OBJDIR)/%.o: 	$(FOLDER)/%.cpp
	             $(CXX) $< $(CXXFLAGS) -c -o $@

$(OBJDIR)/%.o: 	$(FOLDER)/%.cu
	             $(NVCC) $< $(NVCCFLAGS) -c -o $@
