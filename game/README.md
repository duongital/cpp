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

Note: `pkg-config --libs --cflags raylib` is shortcut to include raylib
libraries.

Option 3: Other files can be run directly from VSCode, there is a `build` folder
generated with related files after the build executes successfully.

# Build for web:

- [snake game](./snake/web/)

Step 1: install emcc

```bash
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh
```

we can run `emcc` now but remember to source sh file everytime openning a new
terminal.

Step 2 (once):

- clone Raylib source code and build `libraylib.a` file
- copy `shell.html` file

Follow instruction on
https://github.com/raysan5/raylib/wiki/Working-for-Web-(HTML5)#2-compile-raylib-library

Step 3: build game

```bash
# open new terminal at web game folder 

# activate emcc program
source /Users/duongital/Programming/cpp/emsdk/emsdk_env.sh 

# create a web folder in the related game
mkdir web 

# build game for web
emcc -o ./snake/web/index.html ./snake/main.cpp \
   -Os -Wall ./libraylib.a \
    $(pkg-config --libs --cflags raylib) \
    -s ASYNCIFY \
    --shell-file ./shell.html -s USE_GLFW=3 -DPLATFORM_WEB
```
