#include "logic.h"

void addIndex(SparseMatrix &newIndex, SparseMatrix& matrix)
    {
    SparseMatrix emptyMatrix;
    //SparseMatrix *current = &matrix;
    if (rowExistsInMatrix(newIndex.row, matrix)  && colExistsInMatrix(newIndex.col, matrix) )
        {
        cout << "Tried to add index that already existed" << endl;
        return;
        }
    if (!rowExistsInMatrix(newIndex.row, matrix) )
        {
        addRow(matrix, newIndex.row);
        }
    if (!colExistsInMatrix(newIndex.col, matrix) )
        {
        addCol(matrix, newIndex.col);
        }
    addToRow(newIndex, matrix);         //add to row
    addToCol(newIndex, matrix);         //add to col
    return;
    }
//This function assumes the column exists
void addToRow(SparseMatrix &newIndex, SparseMatrix &matrix)
    {
    SparseMatrix *current = &matrix;
    
    while(  (current->nextInCol != NULL) && (current->row != newIndex.row) )
        {                                                  
        current = current->nextInCol;
        }
    //now at correct row header
    
    while (current->nextInRow != NULL && current->col < newIndex.col )
        {
        cout << "start loop" << endl;
        current = current->nextInCol;
        cout << "through loop" << endl;
        }
    insertIndexNextInRow(current, newIndex);
    return;
    }

void addToCol(SparseMatrix &newIndex, SparseMatrix &matrix)
    {
    SparseMatrix *current = &matrix;
    while(  (current->nextInRow != NULL) &&(current->col != newIndex.col) )
        {                                           //is null or the next       
        current = current->nextInRow;
        }
    //
    while (current->nextInCol != NULL && current->row < newIndex.row )
        {
        current = current->nextInRow;
        }
    insertIndexNextInCol(current, newIndex);
    return;
    }

int rowExistsInMatrix(int rowNumber, SparseMatrix matrix)
    {
    SparseMatrix *current = &matrix;
    while(current != NULL)
        {
        if (current->row == rowNumber)
            {return 1;}
        current = current->nextInCol;
        }
    return 0;
    }

int colExistsInMatrix(int colNumber, SparseMatrix matrix)
    {
    SparseMatrix *current = &matrix;
    while(current != NULL)
        {
        if (current->col == colNumber)
            {return 1;}
        current = current->nextInRow;
        }
    return 0;
    }

void addRow(SparseMatrix &matrix, int row)
    {
    SparseMatrix *current = &matrix;
    while (current->nextInCol != NULL && row > matrix.nextInCol->row)
        {
        current = current->nextInCol;
        }
    SparseMatrix *newRowHeader = newSparseMatrix(row,0,0);
    insertIndexNextInCol(current, *newRowHeader);
    return;
    }
//change below to addCol
void addCol(SparseMatrix &matrix, int col)
    {
    SparseMatrix *current = &matrix;
    while (current->nextInRow != NULL && col > matrix.nextInRow->col)
        {
        current = current->nextInRow;
        }
    SparseMatrix *newColHeader = newSparseMatrix(0,col,0);    
    insertIndexNextInRow(current, *newColHeader);
    return;
    }

void insertIndexNextInCol(SparseMatrix *top, SparseMatrix &insert)
    {
    SparseMatrix *temp = top->nextInCol;
    top->nextInCol = &insert;
    insert.nextInCol = temp;
    return;
    }

void insertIndexNextInRow(SparseMatrix *left, SparseMatrix &insert)
    {
    SparseMatrix *temp = left->nextInRow;
    left->nextInRow = &insert;
    insert.nextInRow = temp;
    return;
    }

//returns a specific index corresponding to the row and col number passed to it
//will not work if the index does not exist.
SparseMatrix* goToIndex(SparseMatrix matrix, int row, int col)
    {
    SparseMatrix *current;
    current = &matrix;
    while (current->nextInCol != NULL && row > current->nextInCol->row)
        {
        current = current->nextInCol;
        }
    if (row != current->row)
        cout << "Error: Index not found in function goToIndex" << endl;
    while (current->nextInRow != NULL && col > current->nextInRow->col)
        {
        current = current->nextInRow;
        }
    if (col != current->col)
        cout << "Error: Index not found in function goToIndex" << endl;
    return current;
    }

SparseMatrix *newSparseMatrix(int row,int col,double value)
    {   
    SparseMatrix *matrix = new SparseMatrix;
    matrix->row = row;
    matrix->col = col;
    matrix->value = double (value);
    return matrix;
    }

