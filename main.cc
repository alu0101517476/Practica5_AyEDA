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
  std::vector<long> secuencia;
  std::cout << "Introduce el tamaño de la secuencia: ";
  std::cin >> size;
  secuencia.reserve(size);
  std::cout << "¿Quieres introducir los valores manualmente o aleatoriamente? "
               "\n1) Manualmente 2) Aleatoriamente\n";
  std::cin >> opcion_valores;
  switch (opcion_valores) {
    case 1: {
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
      std::cout << "Opción incorrecta"<< opcion_valores << std::endl;
      exit(1);
      break;
  }
  SortMethod<long>* Metodo;
  std::cout << "Elige el algoritmo que quieras utilizar: \n1) Inserción\n2) "
               "MergeSort\n3) ShellSort\n4) HeapSort\n5) RadixSort\n";
  std::cin >> opcion_algoritmo;
  switch (opcion_algoritmo) {
    case 1:
      Metodo = new InsertionSort<long>{size, secuencia};
      Metodo->Sort();
      break;
    case 2:
      //Metodo = new MergeSort<long>{size, secuencia};
      //Metodo->Sort();
      break;
    default:
      break;
  }
  return 0;
}
