<div id="top">

<!-- HEADER STYLE: CLASSIC -->
<div align="center">


# JEU_MARIOSDL

<em>Unleash Creativity, Conquer Challenges, Play Fearlessly</em>

<!-- BADGES -->
<img src="https://img.shields.io/github/license/RMichel14/Jeu_MarioSDL?style=flat&logo=opensourceinitiative&logoColor=white&color=0080ff" alt="license">
<img src="https://img.shields.io/github/last-commit/RMichel14/Jeu_MarioSDL?style=flat&logo=git&logoColor=white&color=0080ff" alt="last-commit">
<img src="https://img.shields.io/github/languages/top/RMichel14/Jeu_MarioSDL?style=flat&color=0080ff" alt="repo-top-language">
<img src="https://img.shields.io/github/languages/count/RMichel14/Jeu_MarioSDL?style=flat&color=0080ff" alt="repo-language-count">

<em>Built with the tools and technologies:</em>

<img src="https://img.shields.io/badge/Markdown-000000.svg?style=flat&logo=Markdown&logoColor=white" alt="Markdown">
<img src="https://img.shields.io/badge/GNU%20Bash-4EAA25.svg?style=flat&logo=GNU-Bash&logoColor=white" alt="GNU%20Bash">
<img src="https://img.shields.io/badge/C-A8B9CC.svg?style=flat&logo=C&logoColor=black" alt="C">

</div>
<br>

---

## Table of Contents

- [Overview](#overview)
- [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Installation](#installation)
    - [Usage](#usage)
    - [Testing](#testing)
- [Features](#features)
- [Project Structure](#project-structure)
- [License](#license)

---

## Overview

Jeu_MarioSDL is a modular, SDL2-based framework for developing engaging 2D platformer games. It provides a structured architecture that manages rendering, user input, obstacles, platforms, and game states, enabling developers to create interactive and dynamic gameplay experiences efficiently.

**Why Jeu_MarioSDL?**

This project aims to simplify the development of SDL2 games by offering a well-organized codebase and automation tools. The core features include:

- 🟢 **Modular Design:** Clear separation of game components like player, obstacles, and events for easy maintenance and scalability.
- 🔵 **Automated Build Process:** Makefile and setup scripts streamline compilation, resource management, and execution.
- 🟠 **Real-Time Event Handling:** Responsive input processing and event management for smooth gameplay.
- 🟣 **Dynamic Game Elements:** Procedural obstacle and platform management to keep gameplay engaging.
- 🟡 **SDL2 Integration:** Efficient rendering and input handling for a seamless visual and interactive experience.

---

## Features

|      | Component          | Details                                                                                     |
| :--- | :----------------- | :------------------------------------------------------------------------------------------ |
| ⚙️  | **Architecture**   | <ul><li>Modular design separating rendering, input handling, and game logic</li><li>Uses SDL2 for graphics and input</li><li>Event-driven main loop managing game states</li></ul> |
| 🔩 | **Code Quality**   | <ul><li>Consistent C coding style with clear function separation</li><li>Use of header files for declarations</li><li>Comments indicating major functions and modules</li></ul> |
| 📄 | **Documentation**  | <ul><li>Basic README with project overview and build instructions</li><li>Inline comments in source code</li><li>No extensive external documentation or API docs</li></ul> |
| 🔌 | **Integrations**    | <ul><li>SDL2 library for graphics, input, and audio</li><li>Makefile for build automation</li><li>Custom modules like `sauv_mariosdl_before_obstacle` for game state management</li></ul> |
| 🧩 | **Modularity**      | <ul><li>Separate modules for Mario, obstacles, and game states</li><li>Header files (`header`) for interface definitions</li><li>Potential for adding new obstacle types with minimal impact</li></ul> |
| 🧪 | **Testing**         | <ul><li>No explicit unit testing framework detected</li><li>Some functions have manual test cases in comments</li><li>Potential to integrate C testing frameworks for robustness</li></ul> |
| ⚡️  | **Performance**     | <ul><li>Uses SDL2 hardware acceleration features</li><li>Game loop optimized for minimal frame delay</li><li>Potential bottlenecks in obstacle rendering or collision detection</li></ul> |
| 🛡️ | **Security**        | <ul><li>Limited security considerations; typical C vulnerabilities (buffer overflows) possible</li><li>No input sanitization beyond SDL event handling</li></ul> |
| 📦 | **Dependencies**    | <ul><li>SDL2 library for graphics and input</li><li>Custom modules (`mariosdl`, `sauv_mariosdl_before_obstacle`, etc.)</li><li>No external package managers; build via Makefile</li></ul> |

---

## Project Structure

```sh
└── Jeu_MarioSDL/
    ├── Makefile
    ├── MarioSDL
    ├── README.md
    ├── dependencies
    │   ├── blocs.o
    │   ├── dangers.o
    │   ├── events.o
    │   ├── game.o
    │   ├── main.o
    │   └── player.o
    ├── filesC
    │   ├── blocs.c
    │   ├── dangers.c
    │   ├── events.c
    │   ├── game.c
    │   ├── main.c
    │   └── player.c
    ├── images
    │   ├── background_accueil.png
    │   ├── background_game.jpg
    │   ├── background_game2.jpg
    │   ├── joueur1.png
    │   ├── joueur1_.jpg
    │   ├── joueur2.png
    │   └── joueur2_.jpg
    ├── include
    │   ├── blocs.h
    │   ├── dangers.h
    │   ├── events.h
    │   ├── game.h
    │   └── player.h
    ├── sauv_MarioSDL_before_obstacle
    ├── sauv_MarioSDL_obstacles
    └── start.sh
```

---

## Getting Started

### Prerequisites

This project requires the following dependencies:

- **Programming Language:** C
- **Package Manager:** Make

### Installation

Build Jeu_MarioSDL from the source and install dependencies:

1. **Clone the repository:**

    ```sh
    ❯ git clone https://github.com/RMichel14/Jeu_MarioSDL
    ```

2. **Navigate to the project directory:**

    ```sh
    ❯ cd Jeu_MarioSDL
    ```

3. **Install the dependencies:**

SDL2 & SDL_image

### Usage

Run the project with:

**Using start file:**

```sh
./start.sh
```

---

## License

Jeu_mariosdl is protected under the Boost Software License 1.0. For more details, refer to the [LICENSE](https://choosealicense.com/licenses/bsl-1.0/).

---

<div align="left"><a href="#top">⬆ Return</a></div>

---