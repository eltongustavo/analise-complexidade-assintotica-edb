#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <vector>

//arquivo de cabeçalho que declara as funções de busca e ordenação usadas no arquivo algogoritmos.cpp
bool busca_sequencial(const std::vector<int>& arr, int key);
bool busca_binaria(const std::vector<int>& arr, int key);
void selection_sort(std::vector<int>& arr);
void insertion_sort(std::vector<int>& arr);

#endif // ALGORITMOS_H
