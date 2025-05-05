#include<bits/stdc++.h>
#include "gerarPermutacaoChave.cpp"

using namespace std;

int main() {
    bitset<10> chave_1 = 0b1010000010; // Exemplo de chave de 10 bits
    
    // geração de k1 e k2
    pair<bitset<10>,bitset<10>> chaves = gerarChaveAleatoria(chave_1);
    bitset<10> chave_2 = chaves.first;
    bitset<10> chave_3 = chaves.second;

    return 0;
}


