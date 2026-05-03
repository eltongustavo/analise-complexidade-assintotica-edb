#include "algoritmos.h"

#include <vector>
using namespace std;

//algoritmo de busca sequencial que recebe vetor de inteiros e chave a ser buscada
bool busca_sequencial(const vector<int>& arr, int key) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            return true;
        }
    }
    return false;
}

//algoritmo de busca binária que recebe vetor de inteiros ordenados e chave a ser buscada
bool busca_binaria(const vector<int>& arr, int key) {
    int esq = 0, dir = arr.size() - 1;
    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        if (arr[meio] == key) return true;
        if (arr[meio] < key) esq = meio + 1;
        else dir = meio - 1;
    }
    return false;
}

//algoritmo de ordenação selection sort que recebe vetor de inteiros
void selection_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}

//algoritmo de ordenação insertion sort que recebe vetor de inteiros
void insertion_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
