# CFLAGS = -I../include -I/usr/local/include/opencv -I/usr/local/include/opencv2 -L/usr/local/lib/ -g
# LIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_stitching -lboost_system -lboost_thread 
# CC = g++
# % : %.cpp
# 	$(CC) $(CFLAGS) -o $@ $< $(LIBS)
##################################################################################################################################
#  SECOND CHANGE(WRONG)
#CC=g++
#CFLAGS=-c -Wall
#LDFLAGS=
#SOURCES=./source/client.cpp ./source/image.cpp ./source/server.cpp
#OBJECTS=$(SOURCES:.cpp=.o)
#EXECUTABLE=hello

#all: $(SOURCES) $(EXECUTABLE)
    
#$(EXECUTABLE): $(OBJECTS) 
	#$(CC) $(LDFLAGS) $(OBJECTS) -o $@

#.cpp.o:
	#$(CC) $(CFLAGS) $< -o $@
################################################################################################################################
CC=g++

LIBS=-L/usr/local/lib -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_viz -lopencv_core

CFLAGS=-I/usr/local/include/opencv -I/usr/local/include -g

all: 
	$(CC) $(CFLAGS) ./source/client.cpp ./source/image.cpp ./source/server.cpp -o hello $(LIBS)

clean:
	rm -f main
