
#include <iostream>
#include <fstream>
#include <cmath>
#include <istream>

#include "SparseMatrix.h"
#include "logic.h"
#include "io.h"
#include "operators.h"
using namespace std;

int main(int argc, char **argv)
    {
    ifstream infile1;
    if (argc < 2)
        {
        cerr << "error: enter main.cpp followed by a file name" << endl;
        return 0;
        }
    infile1.open(argv[1]); // add error checking
    if (!infile1)
        {
        cout << "Error: File could not be opened" << endl;
        }
    /*string str;
    getline(infile1, str);
    cout << str << endl;
    */
    SparseMatrix matrix;
    infile1 >> matrix;
//    SparseMatrix* newIndex = readIndex(infile1);
//    addIndex(*newIndex, matrix);
    cout << matrix;
//    matrix->SparseMatrix();
//    SparseMatrix matrix2 = matrix;
//    cout << "matrix is: " << matrix;
//    cout << "matrix2 is: " << matrix;

    return 0;
    }
