#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <functional>
#include <algorithm>

#include "algoritmos.h"

using namespace std;
using namespace std::chrono;

//função que gera um vetor de tamanho n de inteiros aleatórios
vector<int> gerarVetorAleatorio(int n) {
    vector<int> v(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 10000);
    for (int i = 0; i < n; ++i) v[i] = distrib(gen);
    return v;
}

//função que gera um vetor de tamanho n de inteiros ordenados
vector<int> gerarVetorOrdenado(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) v[i] = i + 1;
    return v;
}

//função para medir o tempo médio de execução de um algoritmo lambda, repetindo o teste um número definido de vezes
double time(function<void()> algoritmo, int repeticoes) {
    long long tempoTotal = 0;
    for (int i = 0; i < repeticoes; ++i) {
        auto inicio = high_resolution_clock::now();
        algoritmo();
        auto fim = high_resolution_clock::now();
        tempoTotal += duration_cast<nanoseconds>(fim - inicio).count();
    }
    return static_cast<double>(tempoTotal) / repeticoes;
}

int main() {
    vector<int> tamanhos_busca = {1000, 5000, 10000, 50000, 100000}; //valores maiores para buscas
    vector<int> tamanhos_sort = {100, 500, 1000, 2000, 5000}; //valores menores para ordenação
    int repeticoes = 10;

    cout << "Iniciando bateria de testes empiricos...\n";
    cout << "------------------------------------------\n";

    for (size_t i = 0; i < 4; ++i) {
        int n_busca = tamanhos_busca[i];
        int n_sort = tamanhos_sort[i];

        //busca sequencial
        vector<int> dados_sequencial = gerarVetorOrdenado(n_busca);
        int chave_seq = dados_sequencial.empty() ? 0 : dados_sequencial.back();
        double tempoMedioBuscaSequencial = time([dados_sequencial, chave_seq]() { busca_sequencial(dados_sequencial, chave_seq); }, repeticoes);
        cout << "Tamanho (n): " << n_busca << " | Tempo Medio Busca Sequencial: " << tempoMedioBuscaSequencial << " ns\n";
        
        //busca binaria
        vector<int> dados_ordenados = gerarVetorOrdenado(n_busca);
        int chave_bin = dados_ordenados.empty() ? 0 : dados_ordenados.back();
        double tempoMedioBuscaBinaria = time([dados_ordenados, chave_bin]() { busca_binaria(dados_ordenados, chave_bin); }, repeticoes);
        cout << "Tamanho (n): " << n_busca << " | Tempo Medio Busca Binaria: " << tempoMedioBuscaBinaria << " ns\n";

        //selection sort
        vector<int> dados_selection = gerarVetorAleatorio(n_sort);
        double tempoMedioSelectionSort = time([&dados_selection]() { selection_sort(dados_selection); }, repeticoes);
        cout << "Tamanho (n): " << n_sort << " | Tempo Medio Selection Sort: " << tempoMedioSelectionSort << " ns\n";

        //insertion sort
        vector<int> dados_insertion = gerarVetorAleatorio(n_sort);
        double tempoMedioInsertionSort = time([&dados_insertion]() { insertion_sort(dados_insertion); }, repeticoes);
        cout << "Tamanho (n): " << n_sort << " | Tempo Medio Insertion Sort: " << tempoMedioInsertionSort << " ns\n";

        cout << "------------------------------------------\n";
    }

    return 0;
}