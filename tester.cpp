
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
    int row = 123;
    SparseMatrix matrix;
    SparseMatrix *cursor = &matrix;
    SparseMatrix *newMatrix = newSparseMatrix(10,20,17);    
    addIndex(*newMatrix, matrix);
    //addCol(matrix, 20);
    //addRow(matrix, 10);
    //addToRow(*newMatrix, matrix);
    //addToCol(*newMatrix, matrix);
    //cursor = cursor->nextInCol;
    //insertIndexNextInRow(cursor, *newMatrix);

//    addIndex(*matrix, matrix1); 
    cout << matrix << endl;
    return 0;
    }
