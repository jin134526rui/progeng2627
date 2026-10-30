#include <iostream>
#include <vector>

void filter_v(const std::vector<double>& vin, double t, std::vector<double>& vout){
    for(int i=0; i < vin.size(); i++){
        if( vin[i] < t ){
            vout.push_back(vin[i]);
        }
    }
}
int main(){
    std::vector<double> vin{1,7,3,4,2,-2,19}, vout;
    double t;
    std::cin >> t;
    filter_v(vin, t, vout);
    for(int i =0; i< vout.size(); i++){
        std::cout << vout[i] << std::endl;
    }
}