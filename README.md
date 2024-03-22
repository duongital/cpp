# C/C++ in General Topics

Main purpose is to cover games that we all already know how to play!

During the time, I also learn and practice again several skills:

- DS and Algorithms
- OOP concepts
- Visualization and Math theories

Games to cover:

- [ ] snake game
- [ ] terris
- [x] tic-tac-toe

Visualization and Game are using Raylib engine:

1. Packages are managed with `CMakeLists.txt`:

```bash
cd sub_folder
mkdir build
cmake ..
make
./main
```

2. Running directly from the terminal (MacOS):

```bash
brew install raylib # Raylib should be installed already
clang++ main.cpp $(pkg-config --libs --cflags raylib) -o main -std=c++11
./main
```

3. Other files can be run directly from VSCode, there is a `build` folder generated with related files after the build executes successfully.
