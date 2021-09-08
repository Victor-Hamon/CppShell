# SiSH

## Working Environment

**The SiSH is cross-platform (not tested on MacOS but it should work with Clang)
<br>
Here is a quick description of the work environment for each OS**

### Windows version

| Element      | Description                                |
| ----------- | ----------------|
| Compiler      | MSVC (Visual studio 2019 Entreprise)       |
| CMake Version      | 3.16       |
| Profile   | Debug/Release|
| OS Build version   | 19042.1165|
| Visual Studio version   | 16.11.0|
| IDE   | Jetbrains CLion|

### Linux Version

| Element      | Description                                |
| ----------- | ----------------|
| Compiler      | G++       |
| Compiler version      |11.1.0       |
| CMake Version      | 3.16       |
| Profile   | WSL Debug / WSL Release|
| Distribution   | Ubuntu (WSL 2) |
| OS version   | 20.04 |
| IDE   | Jetbrains CLion|

This was tested on windows subsystem for linux (WSL 2) and *should* work on a normal Linux distribution

## Current Version
### Windows Version

- [ ] Create a script (.bat) to build and launch SiSH automatically
- [x] Create a Cmake (make) file to build the project
- [x] Print a shell-like interface after each command
- [x] Retrieve user input
- [x] Parse input into a command object containing the input's data
- [x] Handle multiple commands
- [ ] Handle pipes
- [ ] Handle redirections (<, >, >>, <<)


## Getting Started