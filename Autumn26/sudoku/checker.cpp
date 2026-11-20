#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>

// in this program we are going to represent the sudoku as a one dimensional vector
// linearised by row, for instance the 4x4 sudoku: 
// 1 2 3 4
// 4 1 2 76
// 4 4 4 1
// 9 4 1 -7
// will be represented as: 
// 1 2 3 4 4 1 2 76 4 4 4 1 9 4 1 -7

int twod_to_oned(int row, int col, int rowlen){
    return row*rowlen+col;
}

int mfind(int n, const std::vector<int>& v){
    for(int i = 0; i < v.size(); i++){
        if(n == v[i]){
            return i;
        }
    }
    return -1;
}

bool check_sequence(const std::vector<int>& v){
    for(int i = 1; i < v.size(); i++){
        if(mfind(i, v) == -1){
            return false;
        }
    }
    return true;
}

void get_row(int r, const std::vector<int>& in, std::vector<int>& out){
    int n = sqrt(in.size());
    for(int i = 0; i < n; i++){
        int index = twod_to_oned(r, i, n);
        out.push_back(in[index]);
    }
}

void get_col(int c, const std::vector<int>& in, std::vector<int>& out){
    int n = sqrt(in.size());
    for(int i = 0; i < n; i++){
        int index = twod_to_oned(i, c, n);
        out.push_back(in[index]);
    }
}

void get_subsq(int subs, const std::vector<int>& in, std::vector<int>& out){
    int subn = sqrt(sqrt(in.size()));
    int r = (subs/subn)*subn;
    int c = (subs%subn)*subn;
    for (int j = r; j < r + subn; j++){
        for(int i = c; i < c + subn; i++){
            int index = twod_to_oned(j, i, subn*subn);
            out.push_back(in[index]);
        } 
    }
}

bool valid_sudoku(const std::vector<int>& g){
    int side = std::sqrt(g.size()); 
    std::vector<int> seq;

    for(int i = 0; i < side; i++){
        seq.clear();
        get_row(i, g, seq);

        if(!check_sequence(seq)){ 
            return false;
        }
    }

    for(int i = 0; i < side; i++){
        seq.clear();
        get_col(i, g, seq);

        if(!check_sequence(seq)){
            return false;
        }
    }

    for(int i = 0; i < side; i++){
        seq.clear();
        get_subsq(i, g, seq);

        if(!check_sequence(seq)){
            return false;
        }
    }

    return true;
}

int main(int argc, char* argv[]){

    if(argc != 2){
        std::cout << "one argument needed" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<int> s;

    // beginning of block of code reading the sudoku from the text file

    std::ifstream infile;
    infile.open(argv[1]);

    if(!infile.is_open()){
        std::cout << "error, can't open input file" << std::endl;
        return EXIT_FAILURE;
    }

    int tmp;

    while(infile >> tmp){
        s.push_back(tmp);
    }
    // end of block of code reading the sudoku from the text file
    // we now have the content of the sudoku in vector s

    int side = std::sqrt(s.size());
    // assuming it is a valid square grid in terms of size
    // (if it isn't, the program will not work properly, which is expected)

    // printing the content of the sudoku (as a square);
    // the sudoku is stored as a one-dimensional vector
    // but the vector can be indexed using two indices
    // by converting the indices of a two dimensional representation
    // into the corresponding one-dimensional index (using our function twod_to_oned)

    for(int i = 0; i < side; i++){
        for(int j = 0; j < side; j++){
            std::cout << s[twod_to_oned(i, j, side)] << " ";
        }
        std::cout << std::endl;
    }

    // calling the function checking if the sudoku is a valid one:

    bool valid = valid_sudoku(s);

    if(valid){
        std::cout << "valid" << std::endl;
    }
    else{
        std::cout << "not valid" << std::endl; 
    }

}