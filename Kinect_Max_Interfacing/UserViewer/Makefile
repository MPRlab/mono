include CommonDefs.mak

BIN_DIR = ../Bin

INC_DIRS = \
	Common \
	/Users/music/kinect/NiTE-MacOSX-x64-2.2/Include \
	/Users/music/kinect/NiTE-MacOSX-x64-2.2/Redist \
	/Users/music/kinect/NiTE-MacOSX-x64-2.2/External/GL \
	/Users/music/kinect/OpenNI-MacOSX-x64-2.2/Include \
	/Users/music/kinect/OpenNI-MacOSX-x64-2.2/Redist \
	$(NITE2_INCLUDE) \
	$(NITE2_REDIST64) \
	$(OPENNI2_INCLUDE) \
	$(OPENNI2_REDIST)

SRC_FILES = *.cpp

ifeq ("$(OSTYPE)","Darwin")
	CFLAGS += -DMACOS
	LDFLAGS += -framework OpenGL -framework GLUT
else
	CFLAGS += -DUNIX -DGLX_GLXEXT_LEGACY
	USED_LIBS += glut GL
endif

LIB_DIRS += $(OPENNI2_REDIST)

USED_LIBS += OpenNI2 NiTE2

EXE_NAME = UserViewer

CFLAGS += -Wall -Wno-deprecated

include CommonCppMakefile
