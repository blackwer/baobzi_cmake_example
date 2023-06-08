# Baobzi template example

To build/run
```bash
module load gcc

# Run this the first time you clone this repo
git submodule update --init --recursive

mkdir -p build
cd build
cmake ..
make
./baobzi_example
```
