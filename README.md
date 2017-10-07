# OpenNN_ClassificationTutorial

## Installation

Make sure your have **OpenNN**, **git** and **CMake** all installed on your system. To install **OpenNN**, follow the instructions in OpenNN webpage `http://www.opennn.net/documentation/building_opennn.html`.

For MacOS users, **git** and **CMake** can be installed via `brew` as:
```
brew install git
brew install cmake
```

For Ubuntu users, **git** and **CMake** can be installed via `apt` as:
```
sudo apt install git
sudo apt install cmake
```

To download and install this tutorial. Following these command in a terminal:

```
cd ~
mkdir ./OpenNN_Tutorial
cd ./OpenNN_Tutorial
git clone https://github.com/dungducphan/OpenNN_ClassificationTutorial.git
```

**IMPORTANT**: You have to change the line number [7] and [8] according to the OpenNN installation on your system. Without changing these paths, `gcc` will not be able to find the headers and the libraries so your compilation will fail.

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


## Dataset

I DO NOT own the copyright of the dataset used in this tutorial. `banknote.dat` is taken from `http://archive.ics.uci.edu/ml/datasets/banknote+authentication`
