CFLAGS = -I../include -I/usr/local/include/opencv -I/usr/local/include/opencv2 -I/usr/local/include/boost asio
LIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_stitching -lboost_system -lboost_thread 
CC = g++
hello=server.o client.o image.o
all:$(hello)
$(hello):%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)
