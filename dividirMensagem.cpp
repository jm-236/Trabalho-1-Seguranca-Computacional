#include<bits/stdc++.h>

using namespace std;

// Função que recebe uma mensagem de 8 bits e a divide num par de mensagens com 4 bits cada
pair<bitset<4>, bitset<4>> dividirMensagem(bitset<8> message){

    bitset<4> left;
    bitset<4> right;

    for(int i = 0; i < 8; i++){
        // cout << message[i];
        right[i] = message[i];
        left[i] = message[i + 4];
    }
    cout << endl;
    cout << left << endl;
    cout << right << endl;

    return {left,right};
}