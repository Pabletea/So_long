# So_Long

## 📌 Overview

**So_Long**  is a simple 2D game built using the MLX42 library. The goal of the project is to create a small game where the player navigates through a map, collects items, and reaches an exit while avoiding obstacles.


---

## 📖 Contents

- [Features](#features)
- [Project Structure](#projectstructure)
- [Requirements](#requirements)
- [Installation](#installation)
- [Controls](#controls)
- [Map Format](#mapformat)
- [Gameplay Example](#gameplayexample)
- [Author](#author)

---

## 🚀 Features

- Uses the **MLX42** library for rendering.
- Supports **custom map parsing**.
- Handles **keyboard input for movement**.

---
## 📂 Project Structure
| File                        | Description                                                                 |
|-----------------------------|-----------------------------------------------------------------------------|
| **`MLX42/`**       | External library for rendering.         |
| **`ft_libft/`**       | External custom library (libft).         |
| **`ft_printf/`**       | External library (ft_printf).            |
| **`get_next_line/`** | External library (get_next_line).          |
| **`maps/`** | Folder containing some valid/invalid example maps.   |
| **`resources/`** | Folder contaning all the sprites the game displays   |
| **`src/`** | Folder containing all the source code of the game   |
| **`.gitignore.c`** | Gitignore file.   |
| **`Makefile.c`** | Build and compilation script   |



---

## ⚙️ Requirements

- OS: **Linux**.
- Compiler: **GCC** or equivalent.
- Functional Makefile.

---

## 🛠️ Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/so_long.git
   cd so_long
   ```

2. Install dependencies:
   ```sh
    sudo apt update
    sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
   ```

3. Run the game:
   ```sh
   ./so_long maps/map.ber
   ```

## ⬆️ Controls

The player can move in the following directions:

- **W/A/S/D** - Move the player
- **ESC** - Quit the game

## 🗺️ Map Format

The game requires a `.ber` map file with the following format:

- `1` for walls
- `0` for empty space
- `P` for the player start position
- `E` for the exit
- `C` for collectibles

---
## 🎮 Gameplay example

Here’s a gameplay example:


![game_gif](https://github.com/user-attachments/assets/2fc83da5-f6f8-4eec-8594-8b6ce8dbfb53)

---
## Author 

**Pablo Alonso García**
