#include "metodos_ordenacion.hpp"
/*
Aunque no lo pidan en esta práctica, implementa todos los algortimos de
ordenacion dados en clase para estudiar para el examen y ver las trazas y el
código de cada uno
**Hacer en un archivo aparte**
*/
int main() {
  int opcion_algoritmo, opcion_valores, valor_secuencia;
  unsigned size;
  bool traza{false};
  std::vector<long> secuencia;
  std::cout << "Introduce el tamaño de la secuencia: ";
  std::cin >> size;
  secuencia.reserve(size);
  std::cout << "¿Quieres introducir los valores manualmente o aleatoriamente? "
               "\n1) Manualmente 2) Aleatoriamente\n";
  std::cin >> opcion_valores;
  switch (opcion_valores) {
    case 1: {
      traza = true;
      int i{0};
      while (i != size) {
        std::cout << "Introduce el valor " << ++i << ": ";
        std::cin >> valor_secuencia;
        secuencia.emplace_back(valor_secuencia);
      }
      break;
    }
    case 2: {
      srand(1000);
      for (int i{0}; i < size; ++i) {
        secuencia.emplace_back((rand() % 9999));
      }
      break;
    }
    default:
      std::cout << "La opción " << opcion_valores << " es incorrecta "<<  << std::endl;
      exit(1);
      break;
  }
  SortMethod<long>* Metodo;
  std::cout << "Elige el algoritmo que quieras utilizar: \n1) Inserción\n2) "
               "MergeSort\n3) ShellSort\n4) HeapSort\n5) RadixSort\n";
  std::cin >> opcion_algoritmo;
  switch (opcion_algoritmo) {
    case 1:
      Metodo = new InsertionSort<long>{size, secuencia, traza};
      Metodo->Sort();
      break;

    case 2:
      Metodo = new MergeSort<long>{size, secuencia, traza};
      Metodo->Sort();
      break;

    case 3: 
      Metodo = new ShellSort<long>{size, secuencia, traza};
      break;
    
    case 4:
      Metodo = new HeapSort<long>{size, secuencia, traza};
      break;
    
    case 5:
      Metodo = new RadixSort<long>{size, secuencia, traza};
      break;
    default:
      std::cout << "La opción " << opcion_valores << " es incorrecta "<<  << std::endl;
      exit(1);
      break;
  }
  return 0;
}
