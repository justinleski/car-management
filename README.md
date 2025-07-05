# CarCTRL
A small command-line inventory manager for car dealerships written in ISO C99.

### Purpose
This program intends to utilize `linked lists` to read and write from a file to sort, manage, store, and remove cars based on specifications. Coming from higher-level languages where the runtime hides memory details, I wanted to get comfortable with manual allocation, pointer manipulation, and *valgrind*-level debugging.

### Building and Running
```
git clone https://github.com/justinleski/car-management.git
cd car-management
make
./bin/carBase
```

### Challeneges Faced
Starting from high-level languages got me used to not considering the ins and outs of memory allocation as it was all taken care of for me. Thanks to Valgrind and a lot of effort, I was able to truly mould and strengthen my understanding in how a computer allocates memory; this was by far the most difficult part of the project.
