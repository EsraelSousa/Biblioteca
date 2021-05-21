#include <vector>
#include <iostream>

using namespace std;

void mergeSort(vector<int>& vetor){
    if(1 == (int)vetor.size()) return; // caso base da recursão
    int meio = (int)vetor.size()/2; // metade do vetor
    int index1, index2; // indece para percorrer os vetores auxiliares
    bool end1=false, end2=false; // controlo do fim dos vetores auxiliares
    vector<int> aux1, aux2; // primeira e segunda parte do vetor

    for(int i=0; i<meio; i++)
        aux1.push_back(vetor[i]);
    for(int i=meio; i<(int)vetor.size(); i++)
        aux2.push_back(vetor[i]);

    mergeSort(aux1);
    mergeSort(aux2);

    index1 = index2 = 0;

    for(int i=0; i<(int)vetor.size(); i++){
        if(!end1 && !end2){
            if(aux1[ index1 ] <= aux2[ index2 ])
                vetor[i] = aux1[ index1++];
            else
                vetor[i] = aux2[ index2++];
            
            if(index1 == meio) //fim de aux1
                end1=true;
            if(index2+meio == (int)vetor.size()) // fim de aux2
                end2=true;
        }
        else{
            if(end1) // terminou aux1
                vetor[i] = aux2[index2++];
            else //terminou aux2
                vetor[i] = aux1[index1++];
        }
    }
}

int main(){
    vector<int> nums = {3, 1, 2, 7, 5};
    mergeSort(nums);
    for(int x: nums)
        cout << x << ' ';
    cout << "\n";
    return 0;
}