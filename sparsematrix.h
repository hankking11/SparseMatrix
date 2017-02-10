#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
using namespace std;
class SparseMatrix {
    
    public:
    double value;
    int row;
    int col;
    SparseMatrix *nextInRow;
    SparseMatrix *nextInCol;
    SparseMatrix(void)  // constructor
        {
        value = 0;
        row = 0;
        col = 0;
        nextInRow = NULL;
        nextInCol = NULL;
        return;
        }    
    void operator=(SparseMatrix right);
//    void operator=(SparseMatrix *right);
//    ~SparseMatrix();
    };
#endif


