#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;
// Gera uma permutação pseudoaleatória dos números de 0 até n-1 com base em uma chave de 10 bits
int gerarPermutacaoComChave(unsigned int chave10bits) {
    if (chave10bits >= 1024) {
        throw invalid_argument("A chave deve ter no máximo 10 bits (0 a 1023)");
    }

    // Extrai os bits da chave para um vetor
    std::vector<int> bits(10);
    for (int i = 0; i < 10; ++i) {
        bits[i] = (chave10bits >> i) & 1;
    }

    // Gera permutação dos índices [0..9] usando a própria chave como semente
    std::vector<int> indices(10);
    for (int i = 0; i < 10; ++i) {
        indices[i] = i;
    }

    std::mt19937 rng(chave10bits); // usa a chave como seed
    std::shuffle(indices.begin(), indices.end(), rng);

    // Aplica a permutação aos bits
    unsigned int novaChave = 0;
    for (int i = 0; i < 10; ++i) {
        if (bits[i]) {
            novaChave |= (1 << indices[i]);
        }
    }

    return novaChave; // Retorna a nova chave de 10 bits permutada
}

// Função para aplicar rotação circular de 5 bits
int rotacionarEsquerda5bits(int valor, int rotacoes) {
    rotacoes %= 5; // Garante que não passe de 5
    return ((valor << rotacoes) | (valor >> (5 - rotacoes))) & 0b11111; // Mantém só 5 bits
}

// Divide a chave de 10 bits em duas metades (5 bits) e rotaciona cada uma
int deslocarCircularMetades(int chave10bits, int rotacoes = 1) {
    if (chave10bits >= 1024) {
        throw invalid_argument("A chave deve ter no máximo 10 bits (0 a 1023)");
    }

    // Extrai as metades esquerda e direita
    unsigned int esquerda = (chave10bits >> 5) & 0b11111;  // bits 9 a 5
    unsigned int direita  = chave10bits & 0b11111;         // bits 4 a 0

    // Aplica rotação circular
    esquerda = rotacionarEsquerda5bits(esquerda, rotacoes);
    direita  = rotacionarEsquerda5bits(direita, rotacoes);

    // Recombina as duas metades em uma nova chave de 10 bits
    return (esquerda << 5) | direita;
}

int permutar8bits(int chave10bits){
    if (chave10bits >= 1024) {
        throw invalid_argument("A chave deve ter no máximo 10 bits (0 a 1023)");
    }

    // Extrai os bits da chave para um vetor
    vector<int> bits(10);
    for (int i = 0; i < 10; ++i) {
        bits[i] = (chave10bits >> i) & 1;
    }

    // Gera permutação dos índices [0..7] usando a própria chave como semente
    vector<int> indices(8);
    for (int i = 0; i < 8; ++i) {
        indices[i] = i;
    }

    mt19937 rng(chave10bits); // usa a chave como seed
    shuffle(indices.begin(), indices.end(), rng);

    // Aplica a permutação aos bits
    unsigned int novaChave = 0;
    for (int i = 0; i < 8; ++i) {
        if (bits[i]) {
            novaChave |= (1 << indices[i]);
        }
    }

    novaChave |= (1 << bits[8]);
    novaChave |= (1 << bits[9]);

    return novaChave; // Retorna a nova chave de 10 bits com 8 bits permutados
}

int gerarChaveAleatoria(int chave) {
    return permutar8bits(deslocarCircularMetades(gerarPermutacaoComChave(chave)));
}