# the Fighting Game Kernel (fgk).

## Table Of Content.
* **0.** [**Organization of the repository.**](https://github.com/AntoineStevan/fgk/tree/main/#0-organization-of-the-repository-toc)
* **1.** [**Compile the code.**](https://github.com/AntoineStevan/fgk/tree/main/#1-compile-the-code-toc)
  - **1.1.** [**Dependencies.**    ](https://github.com/AntoineStevan/fgk/tree/main/#11-dependencies-toc)
  - **1.2.** [**Compile.**         ](https://github.com/AntoineStevan/fgk/tree/main/#12-compile-toc)
  - **1.3.** [**Run.**             ](https://github.com/AntoineStevan/fgk/tree/main/#13-run-toc)
* **2.** [**What the kernel attempts to do.**](https://github.com/AntoineStevan/fgk/tree/main/#2-what-the-kernel-attempts-to-do-toc)

## 0. Organization of the repository. [[toc](https://github.com/AntoineStevan/fgk/tree/main/#table-of-content)]

The repository is organized as follows:

📦 ***fgk***  
┣ 📂 **build** -- *see [here](https://github.com/AntoineStevan/fgk/tree/main/#12-compile-toc) to compile the code.*  
┃ ┣ fgk       \  
┃ ┣ ...       | *files created with the compilation.*  
┃ ┗ Makefile  /  
┣ 📜 [`CMakeLists.txt`] -- **  
┣ 📂 [`lib`] -- **  
┃ ┗ ...  
┣ 📜 [`LICENSE`]  
┣ 📜 [`README.md`]  
┣ 📂 [`res`] -- **  
┃ ┗ ...  
┗ 📂 [`src`] -- **  
  ┗ 📜 [`main.cpp`]  

## 1. Compile the code. [[toc](https://github.com/AntoineStevan/fgk/tree/main/#table-of-content)]
### 1.1. Dependencies. [[toc](https://github.com/AntoineStevan/fgk/tree/main/#table-of-content)]
[Download](https://www.sfml-dev.org/download/sfml/2.5.1/index-fr.php) and [install](https://www.sfml-dev.org/tutorials/2.5/start-linux.php) the SFML on your machine.  
Install `cmake`. There are multiple ways to install `cmake` on your machine.  

### 1.2. Compile. [[toc](https://github.com/AntoineStevan/fgk/tree/main/#table-of-content)]
In a terminal, run
```bash
mkdir build
cd build
cmake ..
make
```

### 1.3. Run. [[toc](https://github.com/AntoineStevan/fgk/tree/main/#table-of-content)]
Once the code has been compiled, see [here](https://github.com/AntoineStevan/fgk/tree/main/#12-compile-toc), one can run the code, from `./build`, with
```bash
./fgk
```

## 2. What the kernel attempts to do. [[toc](https://github.com/AntoineStevan/fgk/tree/main/#table-of-content)]
* [x] parabolic-by-parts jumps
  - [x] parameterised by height and time to get there.
  - [x] variable height jumps based on use input, e.g. the longer the key is pressed the bigger the jump.
  - [x] air control to guide the jump.
  - [x] fast falling -> that feeling !
* [x] verlet integration scheme




[`CMakeLists.txt`]: CMakeLists.txt
[`lib`]: lib
[`LICENSE`]: LICENSE
[`README.md`]: README.md
[`res`]: res
[`src`]: src
[`main.cpp`]: src/main.cpp

