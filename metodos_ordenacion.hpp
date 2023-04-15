#ifndef METODOS_ORDENACION_H
#define METODOS_ORDENACION_H

#include <iostream>
#include <vector>
#include "algoritmos.hpp"

template <class Key>
class SortMethod {
 public:
  virtual void Sort() = 0;

 protected:
  unsigned size_;
  std::vector<Key> secuencia_;
  bool traza_; // atributo que sirve para mostrar la traza completa o no
};

// ===== InsertionSort =====
template <class Key>
class InsertionSort : public SortMethod<Key> {
 public:
  InsertionSort(unsigned size, std::vector<Key> secuencia, bool traza = false);
  void Sort();
};

// ===== MergeSort =====
template <class Key>
class MergeSort : public SortMethod<Key> {
 public:
  MergeSort(unsigned size, std::vector<Key> secuencia, bool traza = false);
  void Sort();
};

// ===== ShellSort =====
template <class Key>
class ShellSort : public SortMethod<Key> {
 public:
  ShellSort(unsigned size, std::vector<Key> secuencia, bool traza = false);
  void Sort();
};

// ===== HeapSort =====
template <class Key>
class HeapSort : public SortMethod<Key> {
 public:
  HeapSort(unsigned size, std::vector<Key> secuencia, bool traza = false);
  void Sort();
};

// ===== RadixSort =====
template <class Key>
class RadixSort : public SortMethod<Key> {
 public:
  RadixSort(unsigned size, std::vector<Key> secuencia, bool traza = false);
  void Sort();
};

// ===== CONSTRUCTORES =====
template <class Key>
InsertionSort<Key>::InsertionSort(unsigned size, std::vector<Key> secuencia,bool traza) {
  this->size_ = size;
  this->secuencia_ = secuencia;
  this->traza_ = traza;
}

template <class Key>
MergeSort<Key>::MergeSort(unsigned size, std::vector<Key> secuencia,bool traza) {
  this->size_ = size;
  this->secuencia_ = secuencia;
  this->traza_ = traza;
}

template <class Key>
ShellSort<Key>::ShellSort(unsigned size, std::vector<Key> secuencia,bool traza) {
  this->size_ = size;
  this->secuencia_ = secuencia;
  this->traza_ = traza;
}

template <class Key>
HeapSort<Key>::HeapSort(unsigned size, std::vector<Key> secuencia,bool traza) {
  this->size_ = size;
  this->secuencia_ = secuencia;
  this->traza_ = traza;
}

template <class Key>
RadixSort<Key>::RadixSort(unsigned size, std::vector<Key> secuencia,bool traza) {
  this->size_ = size;
  this->secuencia_ = secuencia;
  this->traza_ = traza;
}

// ===== MÉTODOS DE ORDENACIÓN =====

// Método Sort() de la clase InsertionSort
template <class Key>
void InsertionSort<Key>::Sort() {
  Insercion<Key>(this->secuencia_, this->traza_);
}

// Método Sort() de la clase MergeSort
template <class Key>
void MergeSort<Key>::Sort() {
  mergeSort<Key>(this->secuencia_, 0, (this->secuencia_.size() - 1), this->traza_);
}

// Método Sort() de la clase ShellSort
template <class Key>
void ShellSort<Key>::Sort() {
  double alfa;
  do { // Nos aseguramos de que el usuario introduce un alfa correcto
    std::cout << "Introduce el valor de alfa: ";
    std::cin >> alfa;
  } while (alfa < 0 || 1 < alfa);
  shellSort<Key>(this->secuencia_, alfa, this->traza_);
}

// Método Sort() de la clase HeapSort
template <class Key>
void HeapSort<Key>::Sort() {
  heapSort<Key>(this->secuencia_, (this->secuencia_.size() - 1), this->traza_);
}

// Método Sort() de la clase RadixSort
template <class Key>
void RadixSort<Key>::Sort() {
  radixSort<Key>(this->secuencia_, this->traza_);
}


#endif
