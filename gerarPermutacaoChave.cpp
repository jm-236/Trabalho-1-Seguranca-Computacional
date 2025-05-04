#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;
// Gera uma permutação pseudoaleatória dos números de 0 até n-1 com base em uma chave de 10 bits
bitset<10> gerarPermutacaoComChave(bitset<10> chave10bits) {
    return 0;    
}

// Divide a chave de 10 bits em duas metades (5 bits) e rotaciona cada uma
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

    cout << left_shifted << endl;
    cout << right_shifted << endl;

    bitset<10> ans;
    for(int i = 0; i < 5; i++){
        ans[i] = right_shifted[i];
        ans[i + 5] = left_shifted[i];
    }
    cout << ans << endl;

    return ans;
}

bitset<10> permutar8bits(bitset<10> chave10bits){
    return 0;
}

bitset<10> gerarChaveAleatoria(int chave) {
    return permutar8bits(deslocarCircularMetades(gerarPermutacaoComChave(chave)));
}