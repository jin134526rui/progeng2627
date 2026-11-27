#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

void find_first_letters (
    const std::vector<std::vector<char>>& gridv, 
    const std::vector<std::string>& words, 
    std::vector<std::vector<char>>& resultv, 
    std::vector<std::string>& not_found
){
    for (int i=0; i < words.size(); i++){
        bool found = 0;
        char first_letter = words[i][0];
        for (int y=0; y < gridv.size(); y++){
            for (int x=0; x < gridv[y].size();x++){
                if (first_letter == gridv[y][x]){
                    std::string horizontal_word;
                    std::string vertical_word;
                    for(int a = x; a < x + words[i].size() && a < gridv[y].size(); a++){   
                        horizontal_word.push_back(gridv[y][a]);
                    }
                    for(int a = y; a < y + words[i].size() && a < gridv.size(); a++){
                        vertical_word.push_back(gridv[a][x]);
                    }
                    if (horizontal_word == words[i]){
                        for(int a = x, b = 0; b < words[i].size(); a++, b++){
                            resultv[y][a] = words[i][b];
                            found = 1;
                        }
                    }
                    if (vertical_word == words[i]){
                        for(int a = y, b = 0; b < words[i].size(); a++, b++){
                            resultv[a][x] = words[i][b];
                            found = 1;
                        }
                    }
                }
            }
        }
        if(found == 0){
            not_found.push_back(words[i]);
        }
    }
}

void find_words(
    const std::vector<std::string>& grid, 
    const std::vector<std::string>& words,
    std::vector<std::string>& solution,
    std::vector<std::string>& not_found
){
    std::vector<std::vector<char>> gridv(grid.size());
    std::vector<std::vector<char>> resultv(grid.size());
    for (int i=0; i < grid.size(); i++){
        for (int j=0; j < grid[i].size(); j++){ 
            gridv[i].push_back(grid[i][j]);
            resultv[i].push_back('#');
        }        
    }
    find_first_letters(gridv, words, resultv, not_found);
    for(int i = 0; i < grid.size(); i++){
        std::string word_in_sol;
        for(int j = 0; j < grid[i].size(); j++){
            word_in_sol.push_back(resultv[i][j]);
        }
        solution.push_back(word_in_sol);
    }
    
}

int main(){

    std::vector<std::string> grid = {
        "xappleg",
        "dzeazkg",
        "zwazzbx",
        "dxnqzoy",
        "qyueytp",
        "pythtyg"
    };

    std::vector<std::string> words = {"peanut", "bot", "mango", "apple", "cinnamon"};
    std::vector<std::string> solution;
    std::vector<std::string> not_found;

    find_words(grid, words, solution, not_found); 

    std::vector<std::string> expected_solution = {
        "#apple#",
        "##e####",
        "##a##b#",
        "##n##o#",
        "##u##t#",
        "##t####"
    };

    std::vector<std::string> expected_not_found = {"mango", "cinnamon"};

    if( (solution == expected_solution) && (not_found == expected_not_found) ){
        std::cout << "test passed" << std::endl;
    }
    else{
        std::cout << "test failed" << std::endl;
    }

    std::cout << "solution:" << std::endl;
    for(int i = 0; i < solution.size(); i++){
        std::cout << solution[i] << std::endl;
    }

    std::cout << "not found:" << std::endl;
    for(int i = 0; i < not_found.size(); i++){
        std::cout << not_found[i] << std::endl;
    }

}