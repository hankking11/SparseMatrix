#include "io.h"

SparseMatrix *readIndex(istream& in)
    {
    char comma;
    SparseMatrix *matrix = new SparseMatrix;
    if (in)
        {
        in >> matrix->row;
        in >> comma;
        in >> matrix->col;
        in >> comma;
        in >> matrix->value;
        in >> comma;
        }
    else
        {
        cout << "Error: file not opened for reading" << endl;
        return matrix;
        }
    return matrix;
    }

void printIndex(ostream& out, SparseMatrix *matrix)
    {
    out << "value: " << matrix->value << endl;
    out << "row: " << matrix->row << endl;
    out << "col: " << matrix->col << endl;
    out << "nextInCol: " << matrix->nextInCol << endl;
    out << "nextInRow: " << matrix->nextInRow << endl;
    return;
    }


void printRow(ostream& out, SparseMatrix *current)
    {
    while (current != NULL)
        {
        printIndex(out, current);
        cout << endl;                   // can remove
        current = current->nextInRow;
        }
    return;
    }
