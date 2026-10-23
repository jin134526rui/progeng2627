#include <iostream>
#include <cmath>

int cp(int a, bool& p){
    p = true;
    for(int i = 2; i < a; i++){

        if( (a % i) == 0){ 
            p = false;
            break;
        }

    }
    return 0;
}
int PIR(int n1, int n2){
    bool p;
    for (int i = n1 ; i < n2; i++){
        cp(i, p);
        if (p == true){
            std::cout << i << std::endl;
        }
        
    }
    return 0;
}

int main(){
    int n1, n2;
    std::cout << "Input a smaller integer and a larger integer respectively, prime numbers between them will be shown" << std::endl;
    std::cin >> n1 >> n2;
    PIR(n1, n2);
}