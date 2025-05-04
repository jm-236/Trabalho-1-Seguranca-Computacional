#include<bits/stdc++.h>
#include "gerarPermutacaoChave.cpp"

using namespace std;

int main() {
    unsigned int chave_1 = 0b1000001101; // Exemplo de chave de 10 bits
    unsigned int chave_2 = gerarPermutacaoComChave(chave_1);
    unsigned int chave_3 = gerarPermutacaoComChave(chave_2);

    cout << "Chave 1: " << chave_1 << endl;
    cout << "Chave 2:" << chave_2 << endl;
    cout << "Chave 3:" << chave_3 << endl;
    
    return 0;
}