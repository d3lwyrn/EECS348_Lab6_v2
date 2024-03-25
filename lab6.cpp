#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Function 2: displays matrix
void display(int size, int **matrix) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(6) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function 3: adds two matrices and displays sum
void add(int size, int **matrix1, int **matrix2) {
    // Creates new array
    int **sum = new int *[size];
    for (int i = 0; i < size; i++) {
        sum[i] = new int[size];
// perform addition and save to new matrix
        for (int j = 0; j < size; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    } // display result
    display(size, sum);

    // Free memory after operation (must do after functions involving new int to prevent memory leaks)
    for (int i = 0; i < size; ++i) {
        delete[] sum[i];
    }
    delete[] sum;
}

// Function 5: multiplies two matrices and display result
void mult(int size, int **matrix1, int **matrix2) {
    // Creates a new matrix
    int **multiple = new int *[size];
    for (int i = 0; i < size; i++) {
        multiple[i] = new int[size]();

        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                multiple[i][j] += matrix1[i][k] * matrix2[k][j]; // Takes dot product of each row and column
            }
        }
    }
// display result
    display(size, multiple);

    // Free memory after operation
    for (int i = 0; i < size; ++i) {
        delete[] multiple[i];
    }
    delete[] multiple;
}

// Subtracts the 1st matrix from the 2nd, then displays result
void subtract(int size, int **matrix1, int **matrix2) {
    // Creates new matrix
    int **subtraction = new int *[size];
    for (int i = 0; i < size; i++) {
        subtraction[i] = new int[size];
// subtract and save result to new matrix
        for (int j = 0; j < size; j++) {
            subtraction[i][j] = matrix2[i][j] - matrix1[i][j];
        }
    }
//display result
    display(size, subtraction);

    // Free memory after operation
    for (int i = 0; i < size; ++i) {
        delete[] subtraction[i];
    }
    delete[] subtraction;
}

// Function 6: updates and displays updated matrix
void update(int size, int row, int column, int value, int **matrix) {
    // makes sure row and column are valid
    if (row < 0 | column < 0 | row >= size | column >= size) {
        cout << "Invalid indices for update" << endl;
    } else {
        matrix[row][column] = value; //update value
        display(size, matrix); // display result
    }
}

// Function 7: finds max value of matrix
int max(int size, int **matrix) {
    int max_val = matrix[0][0];
// loop through each value in matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j]; // If new value is bigger, overwrite max_val to contain new max
            }
        }
    }
    return max_val;
}

// Function 8: transposes and displays matrix
void transpose(int size, int **matrix) {
    // Creates a new matrix
    int **trans_matrix = new int *[size];
    for (int i = 0; i < size; i++) {
        trans_matrix[i] = new int[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            trans_matrix[j][i] = matrix[i][j]; // Rows swap with columns
        }
    }
// display new matrix
    display(size, trans_matrix);

    // Free memory after operation
    for (int i = 0; i < size; ++i) {
        delete[] trans_matrix[i];
    }
    delete[] trans_matrix;
}


int main() {
    // Initializes the file
    ifstream input_file("matrix_input.txt");
    if (!input_file.is_open()) { // handle error if file fails to open
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    // get matrix size and create matrices to read data into
    int matrix_size;
    input_file >> matrix_size;
    int **matrix1 = new int *[matrix_size];
    int **matrix2 = new int *[matrix_size];

    // use for loop to read in matrix1
    for (int i = 0; i < matrix_size; i++) {
        matrix1[i] = new int[matrix_size]();
        matrix2[i] = new int[matrix_size]();
        for (int j = 0; j < matrix_size; j++) {
            input_file >> matrix1[i][j];
        }
    }

    // use for loop to read in matrix2
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            input_file >> matrix2[i][j];
        }
    }

    input_file.close();

    // run each function
    cout << "3: add matrices:\n";
    add(matrix_size, matrix1, matrix2);

    cout << "4: multiply matrices:\n";
    mult(matrix_size, matrix1, matrix2);

    cout << "5: subtract matrices: \n";
    subtract(matrix_size, matrix1, matrix2);

    cout << "6: update value:\n";
    update(matrix_size, 0, 0, 5, matrix1);

    cout << "7: find max value: " << max(matrix_size, matrix1) << endl << endl;

    cout << "8: transpose:\n";
    transpose(matrix_size, matrix1);

    // Free memory after program runs
    for (int i = 0; i < matrix_size; ++i) {
        delete[] matrix1[i];
        delete[] matrix2[i];
    }
    delete[] matrix1;
    delete[] matrix2;

    return 0;
}