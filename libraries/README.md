# Intro to robotics libraries

## Description
This folder contains C++ classes which are used in several examples and external Arduino libraries. 

The classes I put here **do not pretend to be production quality libraries** (and .zip files don't contain 
all the necessary information - only code). They were puth here just to avoid copying files from one example 
to another.

The external libraries are situated in ./externals and taken as is from other GIT repositories. They can be zipped
and installed to Arduino IDE (see below). To clone submodules after clonning the repository you can use the command:
```
git submodule update --init --recursive
```
Check [git-submodule(1)](https://www.kernel.org/pub/software/scm/git/docs/git-submodule.html) for additional details.

## Installation
[How to install .zip library in Arduino IDE](https://www.arduino.cc/en/Guide/Libraries#toc4)
