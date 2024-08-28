## Build for web:

- [all games](./_/)
- [snake game](./_/index.html)

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

# create a build folder (not tracking with git)
mkdir build 

# build game for web
emcc -o ./build/index.html game.c \
   -Os -Wall ./libraylib.a \
    $(pkg-config --libs --cflags raylib) \
    -s ASYNCIFY \
    --shell-file ./shell.html -s USE_GLFW=3 -DPLATFORM_WEB
```
