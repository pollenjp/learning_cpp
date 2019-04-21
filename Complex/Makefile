SHELL = /bin/bash

OPENCV_VERSION := 4.1.0
# "static" or "shared"
OPENCV_LIBS := static

CXX := g++
CXXFLAGS = -g -Wall -std=c++11
COMPILE.cc := $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
LINK.cc    := $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH)

INC :=
LDLIBS  :=
TARGET := complex
OBJECTS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
CLEAN_LIST := ${TARGET}
CLEAN_LIST := ${CLEAN_LIST} $(addsuffix .o,${CLEAN_LIST})

#===============================================================================
#===============================================================================
#===============================================================================
# OpenCV Config
PKG_CONFIG_PATH := ${HOME}/.opencv/install/OpenCV-${OPENCV_VERSION}/${OPENCV_LIBS}/lib/pkgconfig
#=======================================
# v4.*
ifneq ($(shell echo ${OPENCV_VERSION} | grep -E "4\.[0-9]+\.[0-9]+"), )
INC := ${INC} `PKG_CONFIG_PATH=${PKG_CONFIG_PATH} pkg-config --cflags opencv4`
# Select `static` or 'shared' OPENCV LIB 
# --static : static library (.a)
ifeq (${OPENCV_LIBS}, shared)
LDLIBS := ${LDLIBS} `PKG_CONFIG_PATH=${PKG_CONFIG_PATH} pkg-config --libs opencv4`
else ifeq (${OPENCV_LIBS}, static)
LDLIBS := ${LDLIBS} `PKG_CONFIG_PATH=${PKG_CONFIG_PATH} pkg-config --static --libs opencv4`
else
ERROR_MESSAGE := 'OPENCV_LIBS' variable should be 'static' or 'shared'.
$(error "${ERROR_MESSAGE}")
endif
#=======================================
# v3.*
else ifneq ($(shell echo ${OPENCV_VERSION} | grep -E "3\.[0-9]+\.[0-9]+"), )
INC := ${INC} `PKG_CONFIG_PATH=${PKG_CONFIG_PATH} pkg-config --cflags opencv`
# Select `static` or 'shared' OPENCV LIB 
ifeq (${OPENCV_LIBS}, shared)
LDLIBS := ${LDLIBS} `PKG_CONFIG_PATH=${PKG_CONFIG_PATH} pkg-config --libs opencv`
else ifeq (${OPENCV_LIBS}, static)
LDLIBS := ${LDLIBS} `PKG_CONFIG_PATH=${PKG_CONFIG_PATH} pkg-config --static --libs opencv`
else
ERROR_MESSAGE := 'OPENCV_LIBS' variable should be 'static' or 'shared'.
$(error "${ERROR_MESSAGE}")
endif
#=======================================
# Others
else
ERROR_MESSAGE := 'OPENCV_VERSION' variable (${OPENCV_VERSION}) is not supported.
$(error "${ERROR_MESSAGE}")
endif
#===============================================================================
#===============================================================================
#===============================================================================

export

.phony : build
build :
	${MAKE} ${TARGET}

# Compile and Link

%.o : %.cpp
	${COMPILE.cc} $^ ${INC} -o $@

${TARGET} : ${OBJECTS}
	${LINK.cc} $^ ${LDLIBS} -o $@

# utils

.phony : clean
clean :
	-${RM} -rf ${CLEAN_LIST} *~ .*~ core
