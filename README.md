# OpenNN_ClassificationTutorial

Make sure your have **OpenNN**, **git** and **CMake** all installed on your system.

To download and install this tutorial. Following these command in a terminal.

```
cd ~
mkdir ./OpenNN_Tutorial
cd ./OpenNN_Tutorial
git clone https://github.com/dungducphan/OpenNN_ClassificationTutorial.git
```
**IMPORTANT**: You have to change the line number [7] and [8] according to the OpenNN installation on your system. Without changing these paths, gcc will not be able to find the headers and the libraries so your compilation will fail.

```
mkdir ./OpenNN_ClassificationTutorial_build
cd ./OpenNN_ClassificationTutorial_build
cmake ../OpenNN_ClassificationTutorial
make
```

To run the executable, just do
```
./NeuralNetApp
```
