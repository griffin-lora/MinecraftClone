g++-11 -Wall -I ./Library $(find Source -type d | awk '$0="-I ./"$0') -c $(find Source -name '*.cpp' -mmin -5) $1
g++-11 $(find -name '*.o') -lGL -lglut -lGLEW -lglfw -lm -lX11 -lpthread -lXi -lXrandr -ldl -o App.elf $1