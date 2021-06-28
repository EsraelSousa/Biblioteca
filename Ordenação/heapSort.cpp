#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

// função gera e retorna um vetor de inteiros gerados de forma aleatória
vector<int> gerarVetor(int tamanho){
    vector<int> vet;
    for(int i=0; i<tamanho; i++)
        vet.push_back(rand () % 100*tamanho);
    return vet;
}

void heapify(vector<int>& vetor, int size, int i){
    int root = i; // raiz
    int l = 2*i+1; // soma 1 no filho esquerdo pelo fato do vetor iniciar em 0
    int r = 2*i + 2; // soma 2 no filho direito pelo fato do vetor iniciar em 0
    
    if(l < size && vetor[l] < vetor[root])
        root = l;
    if(r < size && vetor[r] < vetor[root])
        root = r;
    if(root != i){
        swap(vetor[i], vetor[root]); // troca os valores das variaveis
        
        heapify(vetor, size, root);
    }
}

// ordena um vetor de inteiros que é passado por referencia
void heapSort(vector<int>& vetor){
    int size = vetor.size();
    // ordena parcialmente
    for(int i=size/2-1; i>=0; i--) 
        heapify(vetor, size, i);
    // faz a ordenação completa
    for(int i=size-1; i>=0; i--){
        swap(vetor[i], vetor[0]);
        heapify(vetor, i, 0);
    }
}

int main(){
    vector<int> vetor;
    int tamanho = 10;
    srand(time(NULL));
    
    vetor = gerarVetor(tamanho);
    
    cout << "Vetor gerado:\n";
    for(int xi: vetor) cout << xi << " ";
    
    heapSort(vetor);
    
    cout << "\nVetor ordenado:\n";
    for(int xi: vetor) cout << xi << " ";
    cout << "\n";
    return 0;
}