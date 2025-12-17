#include <iostream>
#include <vector>
#include <omp.h>
#include <cstdlib>
#include <ctime>


using namespace std;

int main(int argc, char* argv[]) 
{
    // seed random number generator for reproducible results
    srand(time(0));

    // define matrix dimensions: M rows, N columns
    int M = 3000, N = 3000;
    
    int num_threads;
    cout << "Enter number of threads: ";
    cin >> num_threads;

    // set number of threads for OpenMP
    omp_set_num_threads(num_threads);


/*  
    FOR AUTOMATIC TESTING
    cout << "Enter number of rows (M): ";
    cin >> M;
    cout << "Enter number of columns (N): ";
    cin >> N;


    DISPLAYING DIMENSIONS
    cout << "Serial Matrix-Vector Multiplication" << endl;
    cout << "Matrix dimensions: " << M << "x" << N << endl;
    cout << "Vector x size: " << N << endl;
    cout << "Result vector y size: " << M << endl;

*/ 

    // allocate memory for matrix A, vector x, and result vector y
    vector<double> A(M * N);  // matrix A: M x N
    vector<double> x(N);      // input vector x: N elements
    vector<double> y(M, 0.0); // result vector y: M elements, initialized to 0 

    // initialize matrix A with random values between 0 and 9
    cout << "Initializing matrix A with random values..." << endl;
    for (int i=0; i<M*N; i++)
    {
        A[i] = rand() % 10; 
    }

    // initialize vector x with random values (0-9)
    cout << "Initializing vector x with random values..." << endl;
    for (int i=0; i<N; i++)
    {
        x[i] = rand() % 10;
    }
    


    cout << "\nStarting parallel (dynamic,4) matrix-vector multiplication..." << endl;
    
    // record start time for performance measurement
    double start_serial = omp_get_wtime();

    // static scheduling
    #pragma omp parallel for schedule(guided)

    // perform matrix-vector multiplication: y = A * x
    // for each row i of matrix A
    for (int i = 0; i < M; i++)
    {
        y[i] = 0.0;  // initialize result element

        // compute dot product of row i with vector x
        for (int j = 0; j < N; j++)
        {
            y[i] += A[i * N + j] * x[j];  // accumulate: row[i] * x
        }
    }
    
    // record end time and calculate elapsed time
    double end_serial = omp_get_wtime();
    double elapsed_time = end_serial - start_serial;
    
    // display performance results
    cout << "\n----------------------------------------" << endl;
    cout << "Method: GUIDED SCHEDULE | Threads: " << num_threads << endl;
    cout << "Execution Time: " << elapsed_time << " seconds" << endl;
    cout << "-------------------------------------------" << endl;
    


    return 0;


}