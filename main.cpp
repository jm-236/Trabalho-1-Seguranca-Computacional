#include<bits/stdc++.h>
#include "gerarPermutacaoChave.cpp"
#include "initialPermutation.cpp"

using namespace std;

int main() {
    bitset<10> chave_1 = 0b1010000010; // Exemplo de chave de 10 bits
    
    // geração de k1 e k2
    pair<bitset<8>,bitset<8>> chaves = gerarChaveAleatoria(chave_1);
    bitset<8> chave_2 = chaves.first;
    bitset<8> chave_3 = chaves.second;
    cout<<"Chave k1 = "<<chave_2<<endl;
    cout<<"Chave k2 = "<<chave_3<<endl;
    bitset<8> mensagem = 0b01110010;
    bitset<8> mensagemPermutada = initial_permutation(mensagem);
    
    cout << "Mensagem original: " << mensagem << endl;
    cout << "Mensagem permutada: " << mensagemPermutada << endl;
    
    return 0;
}


