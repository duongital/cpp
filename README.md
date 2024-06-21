# Games Cover

Cover the games that we all already know how to play!

Todo:

- [x] tic-tac-toe
- [ ] snake game
- [ ] terris

# Run local 
Visualization and Game are using Raylib engine. To run the code in local:

Option 1: Packages are managed with `CMakeLists.txt`:

```bash
cd sub_folder
mkdir build
cmake ..
make
./main
```

Option 2: Running directly from the terminal (MacOS):

```bash
brew install raylib # Raylib should be installed already
clang++ main.cpp $(pkg-config --libs --cflags raylib) -o main -std=c++11
./main
```

Option 3: Other files can be run directly from VSCode, there is a `build` folder generated with related files after the build executes successfully.

# Using GCC

Install native GCC with Homebrew: `brew install gcc --force-bottle`

Check version by openning: Finder / Cmd Shift G / `/opt/homebrew/Cellar` / gcc / *version* / *bin files*

Then we can use terminal to run GCC: `g++-14 main.cpp -o main`

