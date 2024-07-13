# CPP in practice

To remember knowledge, and:

Cover the games that we all already know how to play!

To cover:

- [x] tic-tac-toe
- [ ] snake game
- [ ] terris

Code formatter with Google style and tasks are configured in `.vscode` folder.

# Run Raylib (visual + game) projects: 

Visualization and Game are using Raylib engine. To run the code in local:

Option 1: Packages are managed with `CMakeLists.txt` file:

```bash
brew install cmake
cd sub_folder
mkdir build
cmake ..
make
./main
```

Option 2 (recommended): using Clang++ to run directly from the terminal (MacOS):

```bash
brew install raylib # Raylib should be installed already
clang++ main.cpp $(pkg-config --libs --cflags raylib) -o main -std=c++11
./main
```

TODO: run or build Raylib projects with `g++-14`

Option 3: Other files can be run directly from VSCode, there is a `build` folder generated with related files after the build executes successfully.

## How to debug project:

TODO: Create a new task to run or debug with Clang++

# Run one file executable by native GCC on MacOS:

Install native GCC with Homebrew:

```bash
brew install gcc --force-bottle
g++-14 main.cpp -ld_classic -o main # -ld_classic to avoid errors and use old syntax
./main # or inline: g++-14 main.cpp -o main && ./main
```

(1) Check version (g++-14) by openning: Finder / Cmd Shift G / `/opt/homebrew/Cellar` / gcc / *version* / *bin files*

## How to debug a file:

- Use `.vscode/tasks.json` to create a task `C++: g++-14`, then open a C++ file. 
- On top right, there is a play button to run or debug the program with the selected task.


# VSCode extensions:

- C/C++ IntelliSense (Microsoft)
- clangd (to have linter check)