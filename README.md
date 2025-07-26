# Spiderman Game

## Download

[Download the latest release](https://github.com/mashrur-rahman-fahim/Spiderman-Ultimate-Game/releases/latest)

---

## Game Instructions

### Objective
Survive as Spiderman, defeat bosses, and achieve the highest score possible! Use your skills to jump, web-sling, fight, and dash through challenging levels.

### Controls
- **Left/Right Arrow Keys**: Move Spiderman left or right
- **Up Arrow Key**: Jump
- **0 (Zero) Key**: Double jump (while in the air)
- **W**: Web shoot (attack with web)
- **F**: Fight/Attack (melee attack)
- **D**: Dash (quick movement)
- **Q**: Reset the game
- **P**: Save your score
- **I**: Show data file location (for troubleshooting)

### Features
- Progressive boss battles with increasing difficulty
- Enhanced health bar with visual effects
- Leaderboard system with persistent high scores
- Multiple game mechanics: jumping, web-slinging, combat, dashing
- Robust error handling for file operations
- Multiple fallback locations for data storage
- Detailed error messages showing exact file paths
- Automatic directory creation for save files
- Permission checking for file writes

### Scoring & Leaderboard
- Defeat enemies and bosses to increase your score
- Save your score with 'P' to update the leaderboard
- View high scores and compete for the top spot

### Troubleshooting File Write Issues
If you see errors like "Failed to open data.txt for writing":

1. **Check Data File Location**
   - Press 'I' in the main menu to see where the game is trying to store data
   - The game tries these locations in order:
     1. `%APPDATA%/Spiderman/data.txt`
     2. `%USERPROFILE%/Documents/Spiderman/data.txt`
     3. Game directory: `data.txt`

2. **Run as Administrator**
   - Right-click the game executable and select "Run as administrator"
   - This may be required if the game is in Program Files (x86)

3. **Move Game Location**
   - Copy the game folder to a user-writable location (Desktop, Documents, etc.)
   - Run the game from the new location

4. **Manual Folder Creation**
   - Press Windows + R, type `%APPDATA%`, and press Enter
   - Create a folder named `Spiderman`
   - Restart the game

---

Enjoy playing Spiderman Ultimate! For updates and support, visit the [GitHub repository](https://github.com/mashrur-rahman-fahim/Spiderman-Ultimate-Game).# Spiderman-Ultimate-Game
