# Matrix Operation in C++
A simple yet extensible C++ project implementing core matrix operations: 
- Addition 
- Multiplication
- Transpose
this project is the **first Stage** of the roadmap toward building robust, hight-performance matrix libraries suitable for scientific computing and HPC environment.
---
## Features 
-Clean object-oriented design (`Matrix.h`,`Matrix.cpp`,`main.cpp`)
-Core operations with dimension checks 
-Easy To extend with new operation (subTraction, determinant, inverse)
---
## Stages

### Stage 1 (completed)
- Implemented core matrix operations:
    - Addition
    - Multiplication
    - Transpose
- Verified correctness with demo example in the `main.cpp`.

### Stage 2 (completed)
- Added advanced matrix operations: 
    - Determinant (recursive expansion using minors and coFactors)
    - Inverse (build form coFactor matrix and determinant)
    - Identity matrix (neutral element in multiplication)
- Integrated these functions into Matrix class 
- Updated `main.cpp` with demo examples:
    - Determinant of 2*2  and 3*3 matrixes
    - Inverse of a 2*2 matrix
    -Identity matrix generation
- Tagged release: **v2.0-advanced**

### Stage 3 - Benchmarking (Completed)
- Measure performance of operations (multiplication, determinant) using `<chrono>`.
- Test with larger matrices (e.g., 100×100).
- Document execution times and compare efficiency.
- Prepare for optimization in Stage 4.
#### Output Of The Two Test Operation 
- Multiplication: 27.4259 Seconds
- Determinant:  8.4e-06 seconds
---
## Next Stage (planned): -Optimization Of The App-
- Adding Libraries Like Eigen\BLAS -> Faster Operations
- Experiment With OpenMP To Parallelize multiplication.
- Compare Optimized Result Against Stage 3's Results 

## Notes
- Code is structured with clear separation (`Matrix.h`, `Matrix.cpp`, `main.cpp`).
- Documentation and versioning are updated at each stage.
- MIT License included for open-source use.


## Project Structure
Matrix-Multiplication/
│── Matrix.h
│── Matrix.cpp
│── main.cpp
│── projectDocument.md
│── LICENSE

