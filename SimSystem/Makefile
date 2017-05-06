FOLDER		:= .

EXECUTABLE	:= visual

CU_FILES 	:=

CU_DEPS 	:=

CC_FILES 	:= videoreader.cpp main.cpp renderer.cpp

############################################

ARCH=$(shell uname | sed -e 's/-.*//g')

OBJDIR=$(FOLDER)/objs
CXX=g++ -m64 -std=c++11
CVFLAGS=-I/usr/local/Cellar/opencv/2.4.13.2/include/opencv -I/usr/local/Cellar/opencv/2.4.13.2/include -L/usr/local/Cellar/opencv/2.4.13.2/lib -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_objdetect -lopencv_ocl -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab
CXXFLAGS=-O3 -Wall
LDFLAGS=
#ifeq ($(ARCH), Darwin)
# Building on mac
#LDFLAGS=-L/usr/local/depot/cuda-8.0/lib/ -lcudart
#else
# Building on Linux
#LDFLAGS=-L/usr/local/cuda/lib64/ -lcudart
#endif
NVCC=nvcc
NVCCFLAGS=-O3 -m64 --gpu-architecture compute_35

OBJS=$(OBJDIR)/videoreader.o $(OBJDIR)/main.o


.PHONY: dirs clean

default: $(EXECUTABLE)

dirs:
		mkdir -p $(OBJDIR)/

clean:
		rm -rf $(OBJDIR) *.ppm *~ $(EXECTUABLE)

$(EXECUTABLE): 	dirs $(OBJS)
	             $(CXX) $(CXXFLAGS) $(CVFLAGS) -o $@ $(OBJS) $(LDFLAGS)

$(OBJDIR)/%.o: 	$(FOLDER)/%.cpp
	             $(CXX) $< $(CXXFLAGS) $(CVFLAGS) -c -o $@

$(OBJDIR)/%.o: 	$(FOLDER)/%.cu
	             $(NVCC) $< $(NVCCFLAGS) -c -o $@
