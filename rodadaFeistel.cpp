#include<bits/stdc++.h>
#include "dividirMensagem.cpp"
using namespace std;

vector<int> expansion_order = {3, 0, 1, 2, 1, 2, 3, 0};

int S0[4][4] ={{1, 0, 3, 2},{3, 2, 1, 0},{0, 2, 1, 3},{3, 1, 3, 2}};
int S1[4][4] ={{0, 1, 2, 3},{2, 0, 1, 3},{3, 0, 1, 0},{2, 1, 0, 3}};


bitset<2> s_box(pair<bitset<4>, bitset<4>> mensagem){

    bitset<4> left = mensagem.first;
    bitset<4> right = mensagem.second;

    int row = 0;
    int column = 0;

    row += left[3] == 1 ? 2 : 0;
    row += left[0] == 1 ? 1 :  0;

    column += left[2] == 1 ? 2 : 0;
    column += left[1] == 1 ? 1 :  0;

    cout << row << endl;
    cout << column << endl;

    int n = S0[row][column];
    cout << n << endl;

    return 0;
}

bitset<8> expand(bitset<4> left){
    bitset<8> leftExpanded;

    for (int i = 7; i >= 0; i--){
        int index = expansion_order[7 - i];
        leftExpanded[i] = left[3 - index];
    }
    cout << "left: " << left << endl;
    cout << "left expanded: " << leftExpanded << endl;  
    
    return leftExpanded;
}

bitset<4> functionF(bitset<4> left, bitset<8>chave){

    bitset<8> leftexpanded = expand(left);
    cout << "key: " << chave << endl;
    bitset<8> leftexpanded_XOR = leftexpanded ^ chave;
    cout << "Após xor: " << leftexpanded_XOR << endl;
    pair<bitset<4>, bitset<4>> mensagemDividida = dividirMensagem(leftexpanded_XOR);

    // dividir essa merda antes de passar pra s-box
    s_box(mensagemDividida);

    return 0;
}

pair<bitset<4>, bitset<4>> rodadaFeistel(pair<bitset<4>, bitset<4>> mensagem, bitset<8> chave){

    bitset<4> newLeft = functionF(mensagem.second, chave);

    return {0,0};
}