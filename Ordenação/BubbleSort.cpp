#include <vector>
#include <iostream>

using namespace std;

void bubbleSort(vector<int>& vetor){
    for(int i = (int)vetor.size(); i>0; i--){
        for(int j = 0; j<i; j++){
            if(vetor[j] > vetor[j+1])
                swap(vetor[j], vetor[j+1]);
        }
    }
}

int main(){
    vector<int> nums = {3, 1, 2, 7, 5};
    bubbleSort(nums);
    for(int x: nums)
        cout << x << ' ';
    cout << "\n";
    return 0;
}