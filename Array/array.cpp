#include <iostream>

int main(){
    // Array Declaration 
    int arr[10] = {1,2,3,4,5,6,7};
    // Array Indexing
    arr[9] = -990;
    // Array Traversing
    std::cout << "\nOne Dimensional Array" << std::endl;
    for(int i = 0; i < 10; i++){
        std::cout << arr[i] << " | ";
    }

    // 2 dimensional array
    int arr2[][2] = {1,2,3,4};
    // Array Indexing
    arr2[1][1] = -990;
    // Array Traversing
    std::cout << "\nTwo Dimensional Array" << std::endl;
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            std::cout << arr2[i][j] << " | ";
        }
        std::cout << std::endl;
    }

    // 3dimensional array
    int arr3[][2][2] = {1,2,3,4,5,6,7,8};
    // Traversal
    std::cout << "\nThree Dimensional Array" << std::endl;
    for(int i = 0; i <2; i++){
        for(int j = 0; j<2; j++){
            for(int k = 0; k<2; k++){
                std::cout << arr3[i][j][k] << " | ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}   