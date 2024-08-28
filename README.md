# CPP in practice

- `base`: to remember knowledge
- `draw`: visual things
- [game](/game/): cover classic games
- `pratice`: leetcode or codeforces

# How to debug a file:

- Use `.vscode/tasks.json` to create a task `C++: g++-14`, then open a C++ file.
- On top right, there is a play button to run or debug the program with the
  selected task.

# VSCode extensions:

- C/C++ IntelliSense (Microsoft)
- clangd (to have linter check)

# Run and serve static games on web:

- start or serve static folder with Deno: `deno run --allow-all serve.ts`
- build game, for example snake_web README.md file steps
- run game: `http://localhost:3000/game/snake/web/index.html`
