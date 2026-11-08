#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

int search_vector(std::string s, const std::vector<std::string>& vin){
    int i = 0;
    for(; i < vin.size(); i++ ){
        if(s == vin[i]){
            return i;
        }
    }
    return -1;
}


void union_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){
    for(int i=0; i < vin1.size(); i++){
        vout.push_back(vin1[i]);
    }
    for(int i = 0 ; i < vin2.size(); i++){
        int a = search_vector(vin2[i], vin1);
        if(a == -1){
            vout.push_back(vin2[i]);
        }
    }
}

void intersection_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){
    for(int i = 0 ; i < vin2.size(); i++){
        int a = search_vector(vin2[i], vin1);
        if(a != -1){
            vout.push_back(vin2[i]);
        }
    }
}



int main(){
    std::string fn1, fn2;
    std::cout << "Type the two file name respectively" << std::endl;
    std::cin >> fn1 >> fn2;

    std::ifstream infile1, infile2;
    infile1.open(fn1);
    infile2.open(fn2);

    if(!infile1.is_open() || !infile2.is_open()){
        std::cout << "error opening files" << std::endl;
        return EXIT_FAILURE;
    }
    
    std::vector<std::string> vwh1, vwh2, vu, vi;
    std::string a, b;
    while (infile1 >> a){
        vwh1.push_back(a);
    }
    while (infile2 >> b){
        vwh2.push_back(b);
    }

    infile1.close();
    infile2.close();

    union_vector(vwh1, vwh2, vu);
    intersection_vector(vwh1, vwh2, vi);

    std::ofstream outfile1,outfile2;
    outfile1.open("union.txt");
    outfile2.open("intersection.txt");

    if(!outfile2.is_open() || !outfile2.is_open()){
        std::cout << "error opening files" << std::endl;
        return EXIT_FAILURE;
    }

    for (int i = 0; i < vu.size(); i++){
        outfile1 << vu[i] << std::endl;
    }

    for (int i = 0; i < vi.size(); i++){
        outfile2 << vi[i] << std::endl;
    }
    
    outfile1.close();
    outfile2.close();
    
}  