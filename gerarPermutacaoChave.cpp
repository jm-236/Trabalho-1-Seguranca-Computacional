/**
 * Códigos referentes ao processo de geração de sub-chaves a partir da chave principal.
 */
#include<bits/stdc++.h>
#define endl '\n';
using namespace std;

// nova ordem dos bits na permutação P10
vector<int> maskten = {2,4,1,6,3,9,0,8,7,5};

// Nova ordem dos bits na permutação P8
vector<int> maskeight = {5,2,6,3,7,4,9,8}; 

// Função que recebe um bitset de tamanho 10, permuta os 10 bits dele e retorna o bitset permutado
bitset<10> permutacao10(bitset<10> chave) {
    bitset<10> newkey;
    for(int i = 0;i<10;i++)
    {
        int value = maskten[i];
        
        newkey[i] = chave[value]; 
    }
    cout<<"Permutação 10" << newkey<<endl;
    return newkey;    
}

// Função que recebe um bitset de tamanho 10, permuta 8 desses 10 bits e retorna o bitset permutado
bitset<10> permutacao8(bitset<10> chave) {
    bitset<10> newkey = chave;
    for(int i = 0;i<10;i++)
    {
        int value = maskeight[i];
        
        newkey[i] = chave[value]; 
    }
    // cout<<"Permutação 8" << newkey<<endl;
    return newkey;    
}

// Função que recebe um bitset de 10 bits, divide ele em dois bitsets de 5 bits, e aplica um deslocamento para a esquerda em ambos os bitsets, agrupa os dois bitsets e retorna um bitset de tamanho 10 com os bits deslocados
bitset<10> deslocarCircularMetades(bitset<10> chave10bits, int rotacoes = 1) {
    bitset<5> left;
    bitset<5> right;
    
    for(int i = 0; i < 5; i++){
        left[i] = chave10bits[i + 5];
        right[i] = chave10bits[i];
    }

    bitset<5> left_shifted;
    bitset<5> right_shifted;

    for (int i = 0; i < 5; i++){
        left_shifted[(i + rotacoes) % 5] = left[i];
        right_shifted[(i + rotacoes) % 5] = right[i];
    }

    //cout << left_shifted << endl;
    //cout << right_shifted << endl;

    bitset<10> ans;
    for(int i = 0; i < 5; i++){
        ans[i] = right_shifted[i];
        ans[i + 5] = left_shifted[i];
    }
    //cout << ans << endl;

    return ans;
}

// Função que gera as chaves k1 e k2 a partir da chave principal, utilizando funções de permutação e deslocamento
pair<bitset<10>,bitset<10>> gerarChaveAleatoria(bitset<10> chave) {
    
    bitset<10> permutado10 = permutacao10(chave);
    bitset<10> deslocado = deslocarCircularMetades(chave);
    bitset<10> k1 = permutacao8(deslocado);
    cout<<"k1 = "<<k1<<endl; 
    deslocado = deslocarCircularMetades(k1,2);
    bitset<10> k2 = permutacao8(deslocado);
    return {k1,k2};
}