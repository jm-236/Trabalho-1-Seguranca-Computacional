#include<bits/stdc++.h>
#define endl '\n';
using namespace std;

// Ordem da permutação realizada
vector<int> initial_order = {1,5,2,0,3,7,4,6};

// Função que recebe a mensagem inicial de 8 bits e retorna a mensagem permutada
bitset<8> initial_permutation(bitset<8> message){

    bitset<8> novaMensagem;

    for (int i = 7; i >= 0; i--){
        int index = initial_order[7 - i];
        // cout<<i<< " "<<index<<" "<<message[index]<< endl;
        novaMensagem[i] = message[7 - index];
    }

    return novaMensagem;
}