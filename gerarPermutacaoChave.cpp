/**
 * Códigos referentes ao processo de geração de sub-chaves a partir da chave principal.
 */
#include<bits/stdc++.h>
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
        int value = 9-maskten[i];
        
        newkey[i] = chave[value];
        //cout<<i<<" "<<value<<" "<< chave[value]<<endl; 
    }
    // cout<<"Permutação " << newkey<<endl;
    return newkey;    
}

// Função que recebe um bitset de tamanho 10, permuta 8 desses 10 bits e retorna o bitset permutado
bitset<8> permutacao8(bitset<10> chave) {
    bitset<8> newkey;
    for(int i = 0;i<8;i++)
    {
        int value = maskeight[i];
        newkey[i] = chave[value]; 
        // cout<<i<<" "<<value<<" "<< chave[value]<<endl; 
    }
    // cout<<"Permutação 8" << newkey<<endl;
    return newkey;    
}
// Função que recebe um bitset de 10 bits, divide ele em dois bitsets de 5 bits, e aplica um deslocamento para a esquerda em ambos os bitsets, agrupa os dois bitsets e retorna um bitset de tamanho 10 com os bits deslocados
bitset<10> deslocarCircularMetades(bitset<10> chave10bits, int rotacoes = 1) {
    rotacoes = 5 - rotacoes;
    //Bitset usa msb em vez de lsb, então temos que rotacionar na direção contraria
    bitset<5> left;
    bitset<5> right;
    //cout<<"Chave entrando no deslocamento:"<<chave10bits<<endl;
    for(int i = 0; i < 5; i++){
        left[i] = chave10bits[i + 5];
        right[i] = chave10bits[i];
    }
    //cout<<"Left = "<<left<<endl;
    //cout<<"Right = "<<right<<endl;

    bitset<5> left_shifted;
    bitset<5> right_shifted;

    for (int i = 0; i < 5; i++){
        left_shifted[(i + rotacoes) % 5] = left[i];
        right_shifted[(i + rotacoes) % 5] = right[i];
    }

    // cout << "Left_Shifted = "<< left_shifted << endl;
    // cout << "Right_Shifted = " << right_shifted << endl;

    bitset<10> ans;
    for(int i = 0; i < 5; i++){
        ans[i] = right_shifted[i];
        ans[i + 5] = left_shifted[i];
    }
    //cout << ans << endl;

    return ans;
}
// Função que recebe um bitset de 8 bits, divide ele em dois bitsets de 4 bits, e aplica um deslocamento para a esquerda em ambos os bitsets, agrupa os dois bitsets e retorna um bitset de tamanho 8 com os bits deslocados
bitset<8> deslocarCircularMetades8(bitset<8> chave8bits, int rotacoes = 1) {
    rotacoes = 4- rotacoes;
    //Bitset usa msb em vez de lsb, então temos que rotacionar na direção contraria
    bitset<4> left;
    bitset<4> right;
    //cout<<"Chave entrando no deslocamento:"<<chave8bits<<endl;
    for(int i = 0; i < 4; i++){
        left[i] = chave8bits[i + 4];
        right[i] = chave8bits[i];
    }
    // cout<<"Left = "<<left<<endl;
    // cout<<"Right = "<<right<<endl;

    bitset<4> left_shifted;
    bitset<4> right_shifted;

    for (int i = 0; i < 4; i++){
        left_shifted[(i + rotacoes) % 4] = left[i];
        right_shifted[(i + rotacoes) % 4] = right[i];
    }

    //cout << "Left_Shifted = "<< left_shifted << endl;
    //cout << "Right_Shifted = " << right_shifted << endl;

    bitset<8> ans;
    for(int i = 0; i < 4; i++){
        ans[i] = right_shifted[i];
        ans[i + 4] = left_shifted[i];
    }
    //cout << ans << endl;

    return ans;
}

// Função que gera as chaves k1 e k2 a partir da chave principal, utilizando funções de permutação e desloc amento
pair<bitset<8>,bitset<8>> gerarChaveAleatoria(bitset<10> chave) {

    cout << '\n' << "------------GERAÇÃO DE CHAVES----------------" << endl;
    cout<<"K = "<<chave<<endl;  
    bitset<10> permutado10 = permutacao10(chave);
    cout<<"permutado10 = "<<permutado10<<endl;
    bitset<10> deslocado = deslocarCircularMetades(permutado10);
    cout<<"Deslocado = "<<deslocado<<endl;
    bitset<8> k1 = permutacao8(deslocado);
    cout<<"k1 = "<<k1<<endl; 
    bitset<10> deslocado2 =  deslocarCircularMetades(deslocado,2);
    cout<<"Deslocado 2 = "<<deslocado2<<endl;
    bitset<8> k2 = permutacao8(deslocado2);
    cout<<"k2 = "<<k2<<endl;
    return {k1,k2};
}