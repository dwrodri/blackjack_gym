# BJGYM (WIP)

**Not yet in Alpha** 

A simple blackjack game that interfaces over CLI.
Once I get a soket-layer interface working, I'll start getting more serious about documentation. This program is designed as an "AI Gym" to provide RL agents with an environment for building a policy for playing blackjack. Blackjack Gym was designed to super easy to build across multiple hardware platforms, highly scalable, and very efficient. Here are some key features of Blackjack Gym:

- Run multiple instances of the game at once. I still haven't decided as to whether concurrency will be handled inside the executable or not.

- Returns game data instead of reward data. You can implement your own reward policy based on what's happening in the game.

- Standard game will only be player + dealer. Maybe we'll get more players 

- Logging feature (not yet implemented)

## Build Details

This project uses [CMake](https://cmake.org/), because the creator is not a fan of `autotools`.
After installing CMake on your platform, change into the repo directory and give `cmake . && make` a go.
This should build automatically build everything for your platform, assuming you have a C11-compatible compiler.
The binary will be in the `bin` folder. Here are the setups I have confirmed working so far:

```
OS: macOS High Sierra 10.13.6 17G65 x86_64
Kernel: 17.7.0
CPU: Intel i7-4870HQ (8) @ 2.50GHz
GPU: AMD Radeon R9 M370X, Intel Iris Pro
Memory: 16384MiB
Compiler: Apple LLVM version 9.1.0 (clang-902.0.39.2)
Target: x86_64-apple-darwin17.7.0
Thread model: posix
```
