#include <vector>
#include <iostream>

using namespace std;

void insertionSort(vector<int>& vetor){
    int x, j;
    for(int i = 1; i<(int)vetor.size(); i++){
        x = vetor[i];
        j = i-1;
        while(j>=0 && vetor[j]>x){
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = x;
    }
}

int main(){
    vector<int> nums = {3, 1, 2, 7, 5};
    insertionSort(nums);
    for(int x: nums)
        cout << x << ' ';
    cout << "\n";
    return 0;
}