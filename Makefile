CC = g++
CXXFLAGS = -std=c++11 -O3  -fpermissive -I ./Managers/ -I ./Core/ -I ./Rendering/Models/ 
GLFLAGS = -lGL -lm -lGLU -lglut -lGLEW -lSOIL

compile :
	$(CC) $(CXXFLAGS) $(GLFLAGS) *.cpp ./Managers/*.cpp ./Core/*.cpp ./Rendering/Models/*.cpp -o main

run :
	./main

clean :
	rm main
