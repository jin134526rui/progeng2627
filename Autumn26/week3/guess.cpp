#include <iostream>
#include <string>

int main(){
    int n, l, h;
    std:: string ans;

    std:: cout << "I am going to guess your number, set your lower and upper boundaires repectively:" << std:: endl;
    std:: cin >> l >> h;
    std:: cout << "Think of a number between that range." << std:: endl;
    n = (l + h)/2;
    
    std:: cout << "Is your number greater than, equal to, or smaller than " << n << "?" << std::endl;
    std:: cin >> ans;

    for (; ans != "equal";){

        if (ans == "greater"){
            l = (l + h)/2;

        }

        else if (ans == "smaller"){
            h = (l + h)/2;

        }

        n = (l + h)/2;
        
        std:: cout << "Is your number greater than, equal to, or smaller than " << n << "?" << std::endl;
        std:: cin >> ans;
    }
    std:: cout << "Your number is " << n;



}