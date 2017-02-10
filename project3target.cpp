#include "project3.h"

using namespace std;

int main(int argc, char **argv) {
    // check if argc==5
    SparseMatrix m1, m2, m;
    ifstream infile1, infile2;

    infile1.open(argv[2]); // add error checking
    infile2.open(argv[3]); // add error checking

    infile1 >> m1;
    infile2 >> m2;

    infile1.close();
    infile2.close();
    /*
    string op(argv[1]);
    if (op=="add") {
        m=m1+m2;
    }
    else if (op=="sub") {
        m=m1-m2;
    }
    else if (op=="mul") {
        m=m1*m2;
    }
    else {
        cerr << "No such operation" << endl;
        return 1;
    }
    
    ofstream outfile;
    outfile.open(argv[4]); // add error checking

    outfile << m;

    outfile.close();

    return 0;*/
}
