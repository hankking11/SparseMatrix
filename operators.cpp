#include <iostream>
#include <fstream>
#include <istream>

#include "SparseMatrix.h"
#include "operators.h"
#include "logic.h"
#include "io.h"

void SparseMatrix::operator=(SparseMatrix right)
    {
    this->value = right.value;
    this->row = right.row;
    this->col = right.col;
    this->nextInRow = right.nextInRow;
    this->nextInCol = right.nextInCol;
    return;
    }
/*
void SparseMatrix::operator=(SparseMatrix *right)
    {
    this->value = right->value;
    this->row = right->row;
    this->col = right->col;
    this->nextInRow = right->nextInRow;
    this->nextInCol = right->nextInCol;
    return;
    }
*/

ostream& operator<<(ostream& out, SparseMatrix matrix)
    {
    SparseMatrix *current = &matrix;
    while (current != NULL)
        {
        printRow(out, current);
        current = current->nextInCol;
        }

    //printIndex(out, matrix); 
    return out;
    }


istream& operator>>(istream& in, SparseMatrix& matrix)
    {
    //matrix = readIndex(in); 
    SparseMatrix *newIndex;
    while(in)
        {
        newIndex = readIndex(in);
        cout << "adding index" << endl;
        addIndex(*newIndex, matrix);
        cout << "matrix so far: " << endl << matrix;
        }
    return in;
    }
