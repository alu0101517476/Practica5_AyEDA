#include <iostream>
#include <vector>

template <class Key>
class SortMethod {
 public:
  virtual void Sort( ) = 0;
 protected:
  unsigned size_;
  std::vector<Key> secuencia_;
};

template <class Key>
class InsertionSort : public SortMethod {
 public:
  void Sort();
};

template <class Key>
class MergeSort : public SortMethod {
 public:
  void Sort();
};

template <class Key>
class ShellSort : public SortMethod {
 public:
  void Sort();
};

template <class Key>
class HeapSort : public SortMethod {
 public:
  void Sort();
};

template <class Key>
class RadixSort : public SortMethod {
 public:
  void Sort();
};