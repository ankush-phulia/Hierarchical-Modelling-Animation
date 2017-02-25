compile :
	g++ -std=c++11 -I ./Managers/ -I ./Core/ -I ./Rendering/Models/ *.cpp ./Managers/*.cpp ./Core/*.cpp ./Rendering/Models/*.cpp -o main -lGL -lGLU -lglut -lGLEW


run :
	./main

clear :
	rm main
