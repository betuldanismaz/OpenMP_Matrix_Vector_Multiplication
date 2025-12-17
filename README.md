# OpenMP Matrix-Vector Multiplication

A comprehensive performance analysis of OpenMP scheduling strategies for parallel matrix-vector multiplication operations.

## Overview

This project implements and compares different OpenMP scheduling strategies (static, dynamic, and guided) for matrix-vector multiplication. It provides detailed performance analysis including execution time measurements and speedup calculations across various thread counts.

## Features

- **Serial Implementation**: Baseline single-threaded matrix-vector multiplication
- **Static Scheduling**: Equal workload distribution among threads
- **Dynamic Scheduling**: Runtime workload distribution with chunk size of 4
- **Guided Scheduling**: Adaptive chunk size for load balancing
- **Performance Visualization**: Python scripts for graphical analysis of results

## Project Structure

```
OpenMP_Matrix_Vector_Multiplication/
├── matrixvector/
│   ├── serial.cpp          # Serial (non-parallel) implementation
│   ├── static.cpp          # OpenMP static scheduling
│   ├── dynamic.cpp         # OpenMP dynamic scheduling
│   ├── guided.cpp          # OpenMP guided scheduling
│   └── .vscode/
│       └── tasks.json      # VS Code build configuration
├── speedup.py              # Speedup comparison visualization
├── executiontime.py        # Execution time comparison visualization
└── README.md               # Project documentation
```

## Requirements

### C++ Compilation

- **Compiler**: GCC/G++ with OpenMP support (version 4.2 or higher)
- **Operating System**: Windows, Linux, or macOS
- **OpenMP**: Version 2.0 or higher

### Python Visualization

- **Python**: 3.6 or higher
- **matplotlib**: For generating performance graphs

## Installation

### 1. Clone the Repository

```bash
git clone https://github.com/betuldanismaz/OpenMP_Matrix_Vector_Multiplication.git
cd OpenMP_Matrix_Vector_Multiplication
```

### 2. Install Python Dependencies

```bash
pip install matplotlib
```

## Compilation

### Windows (MinGW/MSYS2)

```bash
cd matrixvector
g++ serial.cpp -o serial.exe -fopenmp
g++ static.cpp -o static.exe -fopenmp
g++ dynamic.cpp -o dynamic.exe -fopenmp
g++ guided.cpp -o guided.exe -fopenmp
```

### Linux/macOS

```bash
cd matrixvector
g++ serial.cpp -o serial -fopenmp
g++ static.cpp -o static -fopenmp
g++ dynamic.cpp -o dynamic -fopenmp
g++ guided.cpp -o guided -fopenmp
```

## Usage

### Running the Programs

Navigate to the `matrixvector` directory first:

```bash
cd matrixvector
```

**Serial version:**

```bash
./serial
```

**Parallel versions** (you'll be prompted to enter thread count):

```bash
./static
./dynamic
./guided
```

### Example Output

```
Enter number of threads: 4
Initializing matrix A with random values...
Initializing vector x with random values...

Starting parallel (static) matrix-vector multiplication...

----------------------------------------
Method: STATIC SCHEDULE | Threads: 4
Execution Time: 0.027 seconds
-------------------------------------------
```

### Visualizing Results

After collecting performance data, generate graphs:

```bash
python speedup.py
python executiontime.py
```

## OpenMP Scheduling Strategies

### Static Scheduling

- **Description**: Divides iterations into equal-sized chunks at compile time
- **Best For**: Uniform workload distribution
- **Syntax**: `#pragma omp parallel for schedule(static)`

### Dynamic Scheduling

- **Description**: Assigns chunks to threads at runtime with specified chunk size (4)
- **Best For**: Variable workload or load imbalancing
- **Syntax**: `#pragma omp parallel for schedule(dynamic, 4)`

### Guided Scheduling

- **Description**: Starts with large chunks and progressively decreases size
- **Best For**: Load balancing with decreasing overhead
- **Syntax**: `#pragma omp parallel for schedule(guided)`

## Performance Analysis

### Test Configuration

- **Matrix Size**: 3000 × 3000
- **Vector Size**: 3000 elements
- **Thread Counts**: 1, 2, 4, 8, 16
- **Data Type**: Double precision floating-point

### Key Metrics

#### Speedup Formula

```
Speedup = T_serial / T_parallel
```

#### Efficiency Formula

```
Efficiency = Speedup / Number_of_Threads
```

### Results Summary

| Threads | Static Time (s) | Dynamic Time (s) | Guided Time (s) |
| ------- | --------------- | ---------------- | --------------- |
| 1       | 0.087           | 0.079            | 0.076           |
| 2       | 0.043           | 0.068            | 0.044           |
| 4       | 0.027           | 0.045            | 0.026           |
| 8       | 0.016           | 0.033            | 0.015           |
| 16      | 0.013           | 0.023            | 0.017           |

## Implementation Details

### Matrix Representation

- **Storage**: Row-major order in 1D vector
- **Access Pattern**: `A[i * N + j]` for element at row i, column j
- **Initialization**: Random values between 0-9

### Parallelization Strategy

- **Parallel Loop**: Outer loop (matrix rows) is parallelized
- **Private Variables**: Each thread maintains independent row calculations
- **Synchronization**: Implicit barrier at end of parallel region

### Timing Methodology

- **Timer**: `omp_get_wtime()` for high-resolution timing
- **Measurement**: Excludes initialization and only measures computation time

## Building with VS Code

This project includes VS Code task configuration in the `matrixvector/.vscode/` folder:

1. Open any `.cpp` file from the `matrixvector` directory
2. Press `Ctrl+Shift+B` (Windows/Linux) or `Cmd+Shift+B` (macOS)
3. Select "build C++ with OpenMP"

## Troubleshooting

### Compilation Errors

**Issue**: `undefined reference to 'omp_get_wtime'`

- **Solution**: Add `-fopenmp` flag to compilation command

**Issue**: Compiler not found

- **Solution**: Install GCC/G++ with OpenMP support

### Runtime Issues

**Issue**: Poor speedup with high thread count

- **Possible Causes**:
  - Thread overhead exceeds computation benefit
  - Insufficient CPU cores
  - Memory bandwidth limitations

## Contributing

Contributions are welcome! Please feel free to submit issues or pull requests.

### Areas for Enhancement

- Additional scheduling strategies (auto, runtime)
- Different matrix sizes and sparsity patterns
- Cache optimization techniques
- NUMA-aware implementations
- GPU acceleration comparison

## License

This project is available for educational and research purposes.

## Author

**Betul Danismaz**

- GitHub: [@betuldanismaz](https://github.com/betuldanismaz)

## Acknowledgments

- OpenMP Architecture Review Board for the OpenMP specification
- Course instructors and teaching assistants for guidance

## References

1. OpenMP Application Program Interface, Version 5.0 - November 2018
2. Chapman, B., Jost, G., & Van Der Pas, R. (2007). _Using OpenMP: Portable Shared Memory Parallel Programming_
3. Mattson, T., Sanders, B., & Massingill, B. (2004). _Patterns for Parallel Programming_

---

**Last Updated**: December 2025
