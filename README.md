# CPP in practice

To remember knowledge, and:

Cover the games that we all already know how to play!

To cover:

- [x] tic-tac-toe
- [x] snake game
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

Option 3: Other files can be run directly from VSCode, there is a `build` folder generated with related files after the build executes successfully.

## How to debug a file:

- Use `.vscode/tasks.json` to create a task `C++: g++-14`, then open a C++ file. 
- On top right, there is a play button to run or debug the program with the selected task.


# VSCode extensions:

- C/C++ IntelliSense (Microsoft)
- clangd (to have linter check)
