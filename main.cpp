#include <fstream>
#include <iostream>
#include <string>
#define MAX 100
using namespace std;

// Function prototypes
void read_matrix(fstream &my_file, int matrix[MAX][MAX], int jump);
void print_matrix(int matrix[MAX][MAX], int jump);
void add_two_matrices(int matrix_one[MAX][MAX], int matrix_two[MAX][MAX], int sum_matrix[MAX][MAX], int jump);
void multiply_two_matrices(int matrix_one[MAX][MAX], int matrix_two[MAX][MAX], int multiplied_matrix[MAX][MAX], int jump);
void subtract_second_from_first(int matrix_one[MAX][MAX], int matrix_two[MAX][MAX], int sum_matrix[MAX][MAX], int jump);

int main()
{  
    cout << endl << "William Hedges" << endl;
    cout << "Lab #6: Matrix manipulation" << endl << endl;
    string file_name = "matrix_input.txt";
    int jump;
    int matrix_one[MAX][MAX];
    int matrix_two[MAX][MAX];
    int sum_matrix[MAX][MAX];
    int multiplied_matrix[MAX][MAX];
    int subtraction[MAX][MAX];

    fstream my_file;
    my_file.open(file_name, ios::in);

    if (!my_file)
    {
        cout << "No such file";
        return 1;
    }

    // Read and print the first matrix
    my_file >> jump;
    read_matrix(my_file, matrix_one, jump);
    cout << "Matrix A:" << endl;
    print_matrix(matrix_one, jump);

    // Read and print the second matrix
    read_matrix(my_file, matrix_two, jump);
    cout << "Matrix B:" << endl;
    print_matrix(matrix_two, jump);

    // Sum matrices
    add_two_matrices(matrix_one, matrix_two, sum_matrix, jump);
    cout << "Matrix Sum (A+B):" << endl;
    print_matrix(sum_matrix, jump);

    // Multiply matrices
    multiply_two_matrices(matrix_one, matrix_two, multiplied_matrix, jump);
    cout << "Matrix Product (A*B):" << endl;
    print_matrix(multiplied_matrix, jump);

    // Subtract second matrix from the first one so matrix_one - matrix_two
    subtract_second_from_first(matrix_one, matrix_two, subtraction, jump);
    cout << "Matrix Difference (A - B):" << endl;
    print_matrix(subtraction, jump);

    my_file.close();

    return 0;
}

// Function definitions
void read_matrix(fstream &my_file, int matrix[MAX][MAX], int jump)
{
    int a = 0;
    int b = 0;

    for (int i = 0; i < jump; i++)
    {
        for (int o = 0; o < jump; o++)
        {
            my_file >> matrix[a][b];
            b++;
        }
        a++;
        b = 0; // Reset b for the next row
    }
}

void print_matrix(int matrix[MAX][MAX], int jump)
{
    int a = 0;
    int b = 0;

    for (int i = 0; i < jump; i++)
    {
        for (int o = 0; o < jump; o++)
        {
            cout << matrix[a][b] << " "; // Add a space between numbers
            b++;
        }
        cout << endl; // Print a new line for each row
        a++;
        b = 0; // Reset b for the next row
    }
    cout << "\n";
}

void add_two_matrices(int matrix_one[MAX][MAX], int matrix_two[MAX][MAX], int sum_matrix[MAX][MAX], int jump)
{
    int a = 0;
    int b = 0;

    for (int i = 0; i < jump; i++)
    {
        for (int o = 0; o < jump; o++)
        {
            sum_matrix[a][b] = matrix_one[a][b] + matrix_two[a][b];
            b++;
        }
        a++;
        b = 0; // Reset b for the next row
    }
}

void multiply_two_matrices(int matrix_one[MAX][MAX], int matrix_two[MAX][MAX], int multiplied_matrix[MAX][MAX], int jump)
{
    int a = 0;
    int b = 0;

    for (int i = 0; i < jump; i++)
    {
        for (int o = 0; o < jump; o++)
        {   
            int sum = 0; // Initialize the sum to zero

            for (int d = 0; d < jump; d++) // Fix the loop condition
            {
                sum += matrix_one[a][d] * matrix_two[d][b];
            }
            multiplied_matrix[a][b] = sum;
            b++;
        }
        a++;
        b = 0; // Reset b for the next row
    }
}


void subtract_second_from_first(int matrix_one[MAX][MAX], int matrix_two[MAX][MAX], int sum_matrix[MAX][MAX], int jump)
{
    int a = 0;
    int b = 0;

    for (int i = 0; i < jump; i++)
    {
        for (int o = 0; o < jump; o++)
        {
            sum_matrix[a][b] = matrix_one[a][b] - matrix_two[a][b];
            b++;
        }
        a++;
        b = 0; // Reset b for the next row
    }
}
