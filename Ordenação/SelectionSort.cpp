#include <vector>
#include <iostream>

using namespace std;

void selectionSort(vector<int>& vetor){
    int id_min;
    for(int i = 0; i<(int)vetor.size()-1; i++){
        id_min = i;
        for(int j = i+1; j<(int)vetor.size(); j++){
            if(vetor[j] <  vetor[id_min])
                id_min = j;
        }
        swap(vetor[i], vetor[id_min]);
    }
}

int main(){
    vector<int> nums = {3, 1, 2, 7, 5};
    selectionSort(nums);
    for(int x: nums)
        cout << x << ' ';
    cout << "\n";
    return 0;
}