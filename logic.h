#include <iostream>
#include <fstream>
#include <cmath>
#include <istream>

#include "SparseMatrix.h"
#include "io.h"
#include "operators.h"

SparseMatrix *newSparseMatrix(int row,int col,double value);
void addToRow(SparseMatrix &newIndex, SparseMatrix &matrix);
void addToCol(SparseMatrix &newIndex, SparseMatrix &matrix);
void addRow(SparseMatrix &matrix, int row);
void addCol(SparseMatrix &matrix, int col);
int colExistsInMatrix(int colNumber, SparseMatrix matrix);
int rowExistsInMatrix(int rowNumber, SparseMatrix matrix);
void insertIndexNextInRow(SparseMatrix *left, SparseMatrix &insert);
void insertIndexNextInCol(SparseMatrix *top, SparseMatrix &insert);
void addIndex(SparseMatrix& newIndex, SparseMatrix& matrix);
SparseMatrix* goToIndex(SparseMatrix matrix, int row, int col);
//void SparseMatrix::operator=(SparseMatrix right);

