g++-11 -Wall -I ./Source -I ./Source/Entities -I ./Source/Entities/Subclasses -I ./Source/Entities/Subclasses/Actors -I ./Source/Entities/Subclasses/Actors/Subclasses -I ./Source/Entities/Subclasses/Threads -I ./Source/Entities/Subclasses/Threads/Subclasses -I ./Source/Entities/Subclasses/Graphics -c $(find Source -name '*.cpp' -mmin -5) $1
g++-11 $(find -name '*.o') -lGL -lglut -lGLEW -lglfw -lm -lX11 -lpthread -lXi -lXrandr -ldl -o App.elf