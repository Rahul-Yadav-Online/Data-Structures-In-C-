/**
 * This program demonstrates the use of Vector class in C++
*/

#include <iostream> 
#include <vector>

int main(){
    std::vector<int> arr = {1,2,3,4,5,6,7};
    // Indexing and adding elements
    arr[0] = -990;
    arr.push_back(8);
    // Traversing
    for(int i: arr){
        std::cout << i << " | ";
    }
    std::cout << std::endl;

    // multidimensional vector
    std::cout << "Two Dimensional Array" <<std::endl;
    std::vector<int> arr2[2] {{1,2,3,4}, {5,6,7,8}};
    for(int i = 0 ; i< 2; i++){
        for(int j: arr2[i]){
            std::cout << j << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    return 0;
}