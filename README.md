# Nula Engine
The Nula Engine is something I'm developing to teach myself about the ECS pattern and game engine architecture in general. 

My goal is to create an engine using the pattern that is both functional and easy/fun to use. 

## Requirements
This project depends on SDL2 & GLM being discoverable by CMake. I've used the `find_package` command to link SDL2 to the engine. So make sure there is a local copy of SDL2 & GLM in your `CMAKE_PREFIX_PATH` environment variable.

## Building the project
Following the usual CMake build steps should suffice.

### Clone the repo
```bash
git clone https://github.com/SemihMT/GameEngineTemplate.git
```
### Create a build directory
It's a good practice to create a separate build directory to keep the source files clean:
```bash
mkdir build 
cd build
```
### Configure the project
```bash
cmake ..
```
### Build the project
```bash
cmake --build .
```

### This project was created using the Game Engine Template
see: [this repo](https://github.com/SemihMT/GameEngineTemplate)