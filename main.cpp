#include<bits/stdc++.h>
#include "gerarPermutacaoChave.cpp"
#include "initialPermutation.cpp"
#include "dividirMensagem.cpp"
#include "rodadaFeistel.cpp"
#include "concatenaBitset.cpp"
#include "inversePermutation.cpp"
#include "SDES.cpp"
#include "ebc.cpp"
#include "cbc.cpp"
using namespace std;

int main() {
    bitset<10> chave_0 = 0b1010000010; // Exemplo de chave de 10 bits
    pair<bitset<8>,bitset<8>> chaves = gerarChaveAleatoria(chave_0);
    bitset<8> mensagem = 0b11010111;

    cout << '\n' << "-----------CRIPTAÇÃO-----------" << endl;
    bitset<8> mensagem_encriptada = SDES(mensagem, chaves);
    cout << "MEnsagem apos sdes: " << mensagem_encriptada <<  endl;

    cout << '\n' << "----------DECRIPTAÇÃO-----------" << endl;
    bitset<8> mensagem_decriptada = SDES(mensagem_encriptada, {chaves.second, chaves.first}); // inverte a chaves para descriptografar
    cout << "Mensagem descriptografada: " << mensagem_decriptada << endl;

    vector<bitset<8>> temp = ebc(0b11010111011011001011101011110000,gerarChaveAleatoria(0b1010000010));
    cout<<"Apos ebc: ";
    for(auto a:temp)
    {
        cout<<a<<" ";
    }
    cout<<endl;

    temp = cbc(0b11010111011011001011101011110000,gerarChaveAleatoria(0b1010000010));
    cout<<"Apos cbc: ";
    for(auto a:temp)
    {
        cout<<a<<" ";
    }
    cout<<endl;
    
    
    return 0;
}


