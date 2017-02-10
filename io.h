#include <iostream>
#include <fstream>
#include <istream>

#include "SparseMatrix.h"

SparseMatrix *readIndex(istream& in);
void printIndex(ostream& out, SparseMatrix matrix);
void printIndex(ostream& out, SparseMatrix *matrix);
void printRow(ostream& out, SparseMatrix *current);

