#include<bits/stdc++.h>

using namespace std;

vector<int> expansion_order = {3, 0, 1, 2, 1, 2, 3, 0};
bitset<4> p4;
bitset<4> s0s1;
int S0[4][4] ={{1, 0, 3, 2},{3, 2, 1, 0},{0, 2, 1, 3},{3, 1, 3, 2}};
int S1[4][4] ={{0, 1, 2, 3},{2, 0, 1, 3},{3, 0, 1, 0},{2, 1, 0, 3}};

int p4_order[4] = {1,3,2,0};

// Recebe um par de valores representando as partes esquerda e direita da mensagem e as retorna após passarem pelas S-boxes
void s_box(pair<bitset<4>, bitset<4>> mensagem){

    // extrai left e right da mensagem
    bitset<4> left = mensagem.first;
    bitset<4> right = mensagem.second;

    pair<int,int> sw1,sw2;
    //row column 1 e 2;
    bitset<2> aux;
    //cout<<mensagem.first<<" "<<mensagem.second<<endl;
    
    // Lendo o primeiro e ultimo bit da mensagem
    aux[1] = mensagem.first[0];
    aux[0] = mensagem.first[3];

    // valor em inteiro decimal
    sw1.first = aux.to_ulong();
    //cout<<"Aux = "<<aux<<endl;

    // mesma coisa mas com os bits 1 e 2 (0-indexed)
    aux[1] = mensagem.first[1];
    aux[0] = mensagem.first[2];
    sw1.second = aux.to_ulong();
    //cout<<"Aux = "<<aux<<endl;

    aux[1] = mensagem.second[0];
    aux[0] = mensagem.second[3];
    sw2.first = aux.to_ulong();
    //cout<<"Aux = "<<aux<<endl;

    aux[1] = mensagem.second[1];
    aux[0] = mensagem.second[2];
    sw2.second = aux.to_ulong();
    //cout<<"Aux = "<<aux<<endl;

    // Lendo os valores da matriz
    pair<bitset<2>,bitset<2>> pbb = {S0[sw2.first][sw2.second],S1[sw1.first][sw1.second] };
    
    //cout<<"\n\n\n\n";
    //cout<<pbb.first<<" "<<pbb.second<<endl;
    //cout<<sw1.first<<" "<<sw1.second<<endl;
    //cout<<sw2.first<<" "<<sw2.second<<endl;
    s0s1[0] = pbb.first[1];
    s0s1[1] = pbb.first[0];
    s0s1[2] = pbb.second[1];
    s0s1[3] = pbb.second[0];
    //cout<<"s0s1 : "<<s0s1<<endl;

    // aplicando permutação
    for(int i =0;i<4;i++)
    {
        int value = p4_order[i];
        p4[3-i] = s0s1[value];
    }
    //cout<<"p4: "<<p4<<endl;

}

// Realiza a expansão da parte da mensagem
bitset<8> expand(bitset<4> left){
    bitset<8> leftExpanded;

    for (int i = 7; i >= 0; i--){
        int index = expansion_order[i];
        leftExpanded[i] = left[3 - index];
    }
    //cout << "left: " << left << endl;
    //cout << "left expanded: " << leftExpanded << endl;  
    
    return leftExpanded;
}

// Função que executa uma rodada do proceso de FEistel, processando a parte direita da mensagem
bitset<4> functionF(bitset<4> left, bitset<8>chave){
    cout << '\n' << "-----------FUNÇÃO F-----------" << endl;

    bitset<8> leftexpanded = expand(left);
    cout << "key: " << chave << endl;
    cout<<"ep = "<<leftexpanded<<endl;
    bitset<8> leftexpanded_XOR = leftexpanded ^ chave;
    cout << "Apos xor 1: " << leftexpanded_XOR << endl;
    pair<bitset<4>, bitset<4>> mensagemDividida = dividirMensagem(leftexpanded_XOR);

    s_box(mensagemDividida);
    return p4;
    
}

pair<bitset<4>, bitset<4>> rodadaFeistel(pair<bitset<4>, bitset<4>> mensagem, bitset<8> chave){

    bitset<4> newLeft = functionF(mensagem.second, chave);
    //cout<<"newleft = "<<newLeft<<" s0s1 = "<<s0s1<<endl;
    return {newLeft,s0s1};
}