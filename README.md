# RPG-game

The goal of this project is to implement a text based RPG adventure game.

1. Set up Git

   * git clone \<url>
   * (Work on the project & compile with cmake/make, see below)
   * git status
   * git add .
   * git commit -m "comment"
   * git push
2. Set up CMake

   * Create CMakeLists.txt (inside source folder)
   * mkdir build & cd build (binary folder)
   * cmake .. -G "MinGW Makefiles" (generate makefile)
   * make (compile into binary file .exe)

   * Problem encountered: https://stackoverflow.com/questions/4101456/running-cmake-on-windows
3. Create Main Menu
   * Start new game
   * Load previous game
   * Exit
4. Main Game Loop
   * Step-by-step operations: fight /show status/ rest / save / exit
5. Engine Class

   * Create player
   * Upgrade player
   * Save/load
6. Player Class

   * Player status
   * Fight
7. Trainee/Fighter/Mage Class
   * Trainee inherits from Player
   * Trainee can be upgraded into Fighter or Mage (depends on user choice)

(To be continued...)






