# BJGYM (WIP)

**Not yet in Alpha** 

A simple blackjack game that interfaces over CLI.
Once I get a soket-layer interface working, I'll start getting more serious about documentation. This program is designed as an "AI Gym" to provide RL agents with an environment for building a policy for playing blackjack. Blackjack Gym was designed to super easy to build across multiple hardware platforms, highly scalable, and very efficient. Here are some key features of Blackjack Gym:

- Run multiple instances of the game at once. I still haven't decided as to whether concurrency will be handled inside the executable or not.

- Returns game data instead of reward data. You can implement your own reward policy based on what's happening in the game.

- Standard game will only be player + dealer. Maybe we'll get more players 

- Logging feature (not yet implemented)

## Build Details

Current Compiler
```
Apple LLVM version 9.1.0 (clang-902.0.39.2)
Target: x86_64-apple-darwin17.5.0
Thread model: posix
```
Current Compile command
```
clang -Wall -g -std=c11 -o bjgym src/*.c
```
