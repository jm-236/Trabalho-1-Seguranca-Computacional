#include<bits/stdc++.h>
#include "gerarPermutacaoChave.cpp"
#include "initialPermutation.cpp"
// #include "dividirMensagem.cpp"
#include "rodadaFeistel.cpp"

using namespace std;

int main() {
    string Hello_World = "Hello, World";
    cout<<Hello_World<<endl;
    bitset<10> chave_0 = 0b1010000010; // Exemplo de chave de 10 bits
    
    // geração de k1 e k2
    pair<bitset<8>,bitset<8>> chaves = gerarChaveAleatoria(chave_0);
    bitset<8> chave_1 = chaves.first;
    bitset<8> chave_2 = chaves.second;
    cout<<"Chave k1 = "<<chave_1<<endl;
    cout<<"Chave k2 = "<<chave_2<<endl;
    bitset<8> mensagem = 0b01110010;
    bitset<8> mensagemPermutada = initial_permutation(mensagem);
    cout << "Mensagem permutada: " << mensagemPermutada << endl;
    pair<bitset<4>, bitset<4>> mensagemdivida = dividirMensagem(mensagemPermutada);
    cout<<"Mensagem dividida: ("<<mensagemdivida.first << ","<<mensagemdivida.second<<")\n";
    pair<bitset<4>, bitset<4>> mensagemAposRodada = rodadaFeistel(mensagemdivida, chave_1);
    
    return 0;
}


