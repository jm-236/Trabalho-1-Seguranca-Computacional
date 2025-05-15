#include<bits/stdc++.h>
#define endl '\n';
using namespace std;

// Ordem da permutação realizada
vector<int> inverse_order ={3,0,2,4,6,1,7,5};

// Função que recebe a mensagem inicial de 8 bits e retorna a mensagem permutada
bitset<8> inversePermutation(bitset<8> message){
    cout << '\n' << "-----------INVERSE PERMUTATION-----------" << endl;

    bitset<8> novaMensagem;

    for (int i = 7; i >= 0; i--){
        int index = inverse_order[7 - i];
        // cout<<i<< " "<<index<<" "<<message[index]<< endl;
        novaMensagem[i] = message[7 - index];
    }

    return novaMensagem;
}