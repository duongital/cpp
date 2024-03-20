# Games

Cover games that we all already know how to play!

During the time, I also learn and practice again several skills:

- DS and Algorithms
- OOP concepts
- Visualization and Math theories

To cover:

- [ ] snake game
- [ ] terris
- [x] tic-tac-toe

Most of sub-folders using Raylib engine with C++ wrapper. Packages are managed with CMake:

```bash
cd sub_folder
mkdir build
cmake ..
make
./binary_file
```

Or running directly from the terminal (MacOS):

```bash
brew install raylib # Raylib should be installed already
clang++ main.cpp $(pkg-config --libs --cflags raylib) -o main -std=c++11
```