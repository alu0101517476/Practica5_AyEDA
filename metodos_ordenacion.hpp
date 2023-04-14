#include "algoritmos.hpp"

template <class Key>
class SortMethod {
 public:
  SortMethod(unsigned size, std::vector<Key> secuencia, bool traza);
  virtual void Sort() = 0;

 protected:
  unsigned size_;
  std::vector<Key> secuencia_;
  bool traza_;
};

// ===== InsertionSort =====
template <class Key>
class InsertionSort : public SortMethod<Key> {
 public:
  InsertionSort(unsigned size, std::vector<Key> secuencia, bool traza = false) : SortMethod<Key>(size, secuencia, traza) {}
  void Sort();
};

// ===== MergeSort =====
template <class Key>
class MergeSort : public SortMethod<Key> {
 public:
  MergeSort(unsigned size, std::vector<Key> secuencia, bool traza = false) : SortMethod<Key>(size, secuencia, traza) {}
  void Sort();
};

// ===== ShellSort =====
template <class Key>
class ShellSort : public SortMethod<Key> {
 public:
  ShellSort(unsigned size, std::vector<Key> secuencia, bool traza = false) : SortMethod<Key>(size, secuencia, traza) {}
  void Sort();
};

// ===== HeapSort =====
template <class Key>
class HeapSort : public SortMethod<Key> {
 public:
  HeapSort(unsigned size, std::vector<Key> secuencia, bool traza = false) : SortMethod<Key>(size, secuencia, traza) {}
  void Sort();
};

// ===== RadixSort =====
template <class Key>
class RadixSort : public SortMethod<Key> {
 public:
  RadixSort(unsigned size, std::vector<Key> secuencia, bool traza = false) : SortMethod<Key>(size, secuencia, traza) {}
  void Sort();
};

// ===== CONSTRUCTORES =====
template <class Key>
SortMethod<key>::SortMethod(unsigned size, std::vector<Key> secuencia, bool traza) {
  this->size_ = size;
  this->secuencia_ = secuencia;
  this->traza_ = traza;
}

/*
template <class Key>
InsertionSort<Key>::InsertionSort(unsigned size, std::vector<Key> secuencia) {
  this->size_ = size;
  this->secuencia_ = secuencia;
}

template <class Key>
MergeSort<Key>::MergeSort(unsigned size, std::vector<Key> secuencia) {
  this->size_ = size;
  this->secuencia_ = secuencia;
}

template <class Key>
ShellSort<Key>::ShellSort(unsigned size, std::vector<Key> secuencia) {
  this->size_ = size;
  this->secuencia_ = secuencia;
}

template <class Key>
HeapSort<Key>::HeapSort(unsigned size, std::vector<Key> secuencia) {
  this->size_ = size;
  this->secuencia_ = secuencia;
}

template <class Key>
RadixSort<Key>::RadixSort(unsigned size, std::vector<Key> secuencia) {
  this->size_ = size;
  this->secuencia_ = secuencia;
}
*/
// ===== MÉTODOS DE ORDENACIÓN =====

// Método Sort() de la clase InsertionSort
template <class Key>
void InsertionSort<Key>::Sort() {
  Insercion<Key>(this->secuencia_);
}

// Método Sort() de la clase MergeSort
template <class Key>
void MergeSort<Key>::Sort() {
  mergeSort(this->secuencia_, 0, (this->secuencia_.size() - 1));
}

// Método Sort() de la clase ShellSort
template <class Key>
void ShellSort<Key>::Sort() {
  double alfa;
  std::cout << "Introduce el valor de alfa: ";
  std::cin >> alfa;
  shellSort(this->secuencia_, alfa);
}

// Método Sort() de la clase HeapSort
template <class Key>
void HeapSort<Key>::Sort() {
  heapSort(this->secuencia_, (this->secuencia_.size() - 1));
}

// Método Sort() de la clase RadixSort
template <class Key>
void RadixSort<Key>::Sort() {
  radixSort(this->secuencia_);
}
