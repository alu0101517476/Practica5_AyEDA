#include <array>
#include <iostream>
#include <vector>

template <class Key>
void PrintVector(std::vector<Key> vector);

///////////////////////////////////////////////////
// ======= MÉTODO DE INSERCIÓN =======
template <class Key>
void Insercion(std::vector<Key>& numeros);

/////////////////////////////////////////////////////////
// ======= SHELLSORT =======
template <class Key>
void shellSort(std::vector<Key>& secuencia, double alfa);

////////////////////////////////////////////////////////////////////////
// ======= HEAPSORT =======
template <class Key>
void ConvertirEnHeap(std::vector<Key>& vector, int n, int i);

// Función principal para hacer heap sort
template <class Key>
void heapSort(std::vector<Key>& vector, int n);

//////////////////////////////////////////////////////////
// ======= MERGESORT =======
template <class Key>
void Mezcla(std::vector<Key>& v, int primero, int medio, int ultimo);

template <class Key>
void mergeSort(std::vector<Key>& v, int primero, int ultimo);

////////////////////////////////
// ======= RADIXSORT =======

// Función para obtener el máximo valor en un vector
template <class Key>
int ObtenerMaximo(std::vector<Key>& vec);

// Función para realizar el RadixSort
template <class Key>
void radixSort(std::vector<Key>& vec);