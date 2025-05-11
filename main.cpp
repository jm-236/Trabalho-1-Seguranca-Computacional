#include<bits/stdc++.h>
#include "gerarPermutacaoChave.cpp"
#include "initialPermutation.cpp"
#include "dividirMensagem.cpp"
#include "rodadaFeistel.cpp"
#include "concatenaBitset.cpp"
#include "inversePermutation.cpp"
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
    cout<<"P4 = "<<mensagemAposRodada.first<<" S0S1 = "<<mensagemAposRodada.second<<endl;
    
    cout<< "Fazer xor de : "<< mensagemdivida.first << " Com " << mensagemAposRodada.first <<endl;
    bitset<4> aposXor = mensagemdivida.first ^ mensagemAposRodada.first;
    cout<<"Apos xor : "<<aposXor<<endl;
    
    bitset<8> round1 = concatenaBitset(aposXor,mensagemdivida.second);
    cout<<"Round1 : "<<round1<<endl;
    
    //Round 2
    mensagemdivida = dividirMensagem(round1);
    cout<<"Mensagem dividida round 2: ("<<mensagemdivida.first << ","<<mensagemdivida.second<<")\n";
    
    mensagemAposRodada = rodadaFeistel(mensagemdivida, chave_2);
    cout<<"P4 = "<<mensagemAposRodada.first<<" S0S1 = "<<mensagemAposRodada.second<<endl;
    
    cout<< "Fazer xor de : "<< mensagemdivida.first << " Com " << mensagemAposRodada.first <<endl;
    aposXor = mensagemdivida.first ^ mensagemAposRodada.first;
    cout<<"Apos xor : "<<aposXor<<endl;

    bitset<8> round2 = concatenaBitset(mensagemdivida.second,aposXor);
    cout<<"Round2 : "<<round2<<endl;

    bitset<8> inverse_permutated = inversePermutation(round2);
    cout<<"Texto encriptado: "<<inverse_permutated<<endl;
    return 0;
}


