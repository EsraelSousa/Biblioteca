/*
 Implementacao de uma arvore binaria
 Todos os metodo sao O(n) no pior caso
 @Esrael
*/

#include <iostream>
#include <list>

using namespace std;

// estrutura nó de uma árvore 
class NO{
    public: int valor;
    public: NO* esq;
    public: NO* dir;
};

// estrutura árvore
class ArvoreBin{
    NO* raiz; // por padrão é privado
    
    public: NO* getRaiz(){
        return this->raiz;
    }
    
    public: void setRaiz(NO* no){
        this->raiz = no;
    }
    
    public: ArvoreBin(){
        setRaiz(nullptr); // árvore vazia
    }
   
    // insere um novo valor, nao aceita valor repetido na arvore 
    public: void insert(NO* r, int val){
        if(val < r->valor){
            if(r->esq == nullptr){
                NO* esq = new NO;
                esq->valor = val;
                esq->esq = nullptr;
                esq->dir = nullptr;
                r->esq = esq;
            }else{
                insert(r->esq, val);
            }
        }
        else if(val > r->valor){
            if(r->dir == nullptr){
                NO* dir = new NO;
                dir->valor = val;
                dir->esq = nullptr;
                dir->dir = nullptr;
                r->dir = dir;
            }else{
                insert(r->dir, val);
            }
        }
    }
    
    // inserindo um novo valor
    public: void insert(int val){
        if(getRaiz() == nullptr){ // arvore vazia
            NO* novo = new NO;
            novo->valor = val;
            novo->esq = nullptr;
            novo->dir = nullptr;
            setRaiz(novo);
        }else{
            NO* novo = getRaiz();
            insert(novo, val);
        }
    }
    
    public: void posfix(NO* no){
        if(no != nullptr){
            posfix(no->esq);
            posfix(no->dir);
            cout << no->valor << " ";
        }
    }
    
    public: void posfix(){
        NO* r = getRaiz();
        if(r != nullptr){ // arvore nao vazia
        	posfix(r);
        	cout << endl;
        }
    }
    
    // busca as folhas e adiciona a uma lista passada por referencia
    public: void findFolha(NO* no, list<int>& lista){
    	if(no == nullptr) return;
    	if(no->esq == nullptr && no->dir == nullptr) lista.push_back(no->valor);
    	findFolha(no->esq, lista);
    	findFolha(no->dir, lista);
    }
    
    public: list<int> getNosFolha(){
    	list<int> lista;
    	findFolha(getRaiz(), lista);
    	return lista;
    }
    
    // busca e retorna um ponteiro para um no
    public: NO* getNo(NO* no, int val){
        if(no == nullptr) return nullptr; // no nao existe
        if(val == no->valor) return no;
        if(val < no->valor) return getNo(no->esq, val);
        return getNo(no->dir, val);
    }
    
    public: int grauNo(int val){
        NO* no = getNo(getRaiz(), val);
        if(no == nullptr) return -1; // o nó não existe
        if(no->esq == nullptr && no->dir == nullptr) return 0; //sem filhos
        if(no->esq == nullptr || no->dir == nullptr) return 1; // possui apenas um filho
        return 2; // possui dois filhos
    }
    
    // pega a altura da arvore apartir da raiz
    public: int getAltura(NO* no){
    	if(no == nullptr) return -1; // no nao existe
    	int esq = 1 + getAltura(no->esq);
    	int dir = 1 + getAltura(no->dir);
    	return max(esq, dir);
    }
    
    // pega a altura da arvore
    public: int altura(){
        return getAltura(getRaiz());
    }
    
    public: int profundidade(){
    	// Para saber a profundidade da arvore pegamos a altura da arvore, pois e equivalente. 
    	return altura();
    }
};

int main(){
    ArvoreBin T = ArvoreBin(); 
    
    int elementos[] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 11, 13, 15};
    for(int i=0; i<13; i++){
    	cout << "Inserindo o elemento " << elementos[i] << " na arvore\n";
    	T.insert(elementos[i]);
    }
    
    cout << "\nALGUMAS PROPRIEDADES\n\n";
    list<int> lista = T.getNosFolha();
    list<int>:: iterator it; // para percorrer a lista
    for(it = lista.begin(); it != lista.end(); it++){
    	cout << "O no " << *it << " eh uma folha\n";
    }
    
    cout << "\nO grau do no 2 eh " << T.grauNo(2) << "\n";
    cout << "O grau do no 6 eh " << T.grauNo(6) << "\n";
    cout << "O grau do no 15 eh " << T.grauNo(15) << "\n\n";
    
    cout << "A altura da arvore eh " <<T.altura() << "\n\n";
    
    cout << "A profundiade da arvore eh " << T.profundidade() << "\n";
    
    return 0;
}