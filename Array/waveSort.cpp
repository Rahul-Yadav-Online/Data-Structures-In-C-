/**
 * Program to demonstrate wave sort
 * Author : Rahul Yadav
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> arr = {5,4,3,1};
    std::cout<<std::endl;
    for(int i = 0; i<arr.size(); i+=2){
        // Run loop for even positions only 
        if(i>0 && arr[i]<arr[i-1]){
            std::swap(arr[i], arr[i-1]);
        }
        else if(i<arr.size()-1 && arr[i]<arr[i+1]){
            std::swap(arr[i], arr[i+1]);
        }
    }

    for(int i: arr){
        std::cout << i << " | ";
    }
    std::cout<<std::endl;
    return 0;
 }