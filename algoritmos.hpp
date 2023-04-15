#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <iostream>
#include <vector>

// Función para imprimir un vector que usaremos constantemente en los algoritmos
template <class Key>
void PrintVector(std::vector<Key> vector) {
  for (auto& i : vector) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

///////////////////////////////////////////////////
// ======= MÉTODO DE INSERCIÓN =======
template <class Key>
void Insercion(std::vector<Key>& numeros, bool traza) {
  if (!traza) {
    std::cout << "Secuencia original: " << std::endl;
    PrintVector(numeros);
    std::cout << "-------------------------------" << std::endl;
  }
  int aux;
  for (int i{0}; i < numeros.size(); ++i) {
    int posicion{i};
    aux = numeros[i];  // Número actual
    while ((posicion > 0) && (numeros[posicion - 1] > aux)) {
      numeros[posicion] = numeros[posicion - 1];
      posicion--;
    }
    numeros[posicion] = aux;
    // Mostramos la traza de el algoritmo
    if (traza) {
      std::cout << "Iteración número " << i << ":" << std::endl;
      PrintVector(numeros);
      std::cout << "-------------------------------" << std::endl;
    }
  }
  if (!traza) { // El usuario ha introducido los números aleatoriamente
    std::cout << "Vector ordenado:" << std::endl;
    PrintVector(numeros);
  }
}

/////////////////////////////////////////////////////////
// ======= SHELLSORT =======
template <class Key>
void shellSort(std::vector<Key>& secuencia, double alfa, bool traza) {
  auto salto{(secuencia.size() * alfa) / 2};
  auto n{secuencia.size()};
  int iterador{1};
  std::cout << "Secuencia original: " << std::endl;
  PrintVector(secuencia);
  std::cout << "-------------------------------" << std::endl;
  while (salto > 0) {
    bool print{false}; // Variable que nos sirve para mostrar las iteraciones en las que hay un cambio en la secuencia
    for (auto i{salto}; i < n; ++i) {
      auto j{i - salto};
      while (j >= 0) {
        auto k = j + salto;
        if (secuencia[j] <= secuencia[k]) {
          j -= 1;
        } else {
          std::swap(secuencia[j], secuencia[k]);
          j -= salto;
          print = true;
        }
      }
      if (print && traza) {
        std::cout << "Iteración número " << iterador++ << ":" << std::endl;
        PrintVector(secuencia);
        std::cout << "-------------------------------" << std::endl;
      }
    }
    salto /= 2;
  }
  if (!traza) { // El usuario ha introducido los valores aleatoriamente
    PrintVector(secuencia);
  }
}

////////////////////////////////////////////////////////////////////////
// ======= HEAPSORT =======
// Función auxiliar para realizar el Heap Sort
template <class Key>
void ConvertirEnHeap(std::vector<Key>& vector, int n, int i) {
  int largest =
      i;  // Inicializa largest como la raíz, ya que usamos índices basados en 0
  int l = 2 * i + 1;  // left = 2*i + 1
  int r = 2 * i + 2;  // right = 2*i + 2

  // Si el hijo izquierdo es mayor que la raíz
  if (l < n && vector[l] > vector[largest]) largest = l;

  // Si el hijo derecho es mayor que el mayor hasta ahora
  if (r < n && vector[r] > vector[largest]) largest = r;

  // Si largest no es la raíz
  if (largest != i) {
    std::swap(vector[i], vector[largest]);

    // Recursivamente convertir en heap el sub-árbol afectado
    ConvertirEnHeap(vector, n, largest);
  }
}

// Función principal para hacer heap sort
template <class Key>
void heapSort(std::vector<Key>& vector, int n, bool traza) {
  std::cout << "Secuencia original: " << std::endl;
  PrintVector(vector);
  std::cout << "-------------------------------" << std::endl;
  // Construir el heap (reorganizar el arreglo)
  for (int i = n / 2 - 1; i >= 0; i--) ConvertirEnHeap(vector, n, i);

  int iteracion = 0;
  // Extraer un elemento del heap uno por uno
  for (int i = n - 1; i >= 0; i--) {
    // Mover la raíz actual al final
    std::swap(vector[0], vector[i]);

    // Llamar a ConvertirEnHeap en el heap reducido
    ConvertirEnHeap(vector, i, 0);

    iteracion++;
    if ((iteracion == 1 || iteracion == n / 4 || iteracion == n / 2 ||
        iteracion == n / 4 * 3 || iteracion == n - 1) && traza) {
      std::cout << "Iteracion " << iteracion << ": ";
      for (int j = 0; j < n; j++) {
        std::cout << vector[j] << " ";
      }
      std::cout << std::endl;
      std::cout << "-------------------------------" << std::endl;
    }
  }
  if (!traza) { // Se han introducido los valores aleatoriamente
    std::cout << "Vector ordenado: " << std::endl;
    for (int j = 0; j < n; j++) {
        std::cout << vector[j] << " ";
      }
      std::cout << std::endl;
  }
}

//////////////////////////////////////////////////////////
// ======= MERGESORT =======
// Función auxiliar para realizar el Merge Sort que mezcla las subsecuencias
template <class Key>
void Mezcla(std::vector<Key>& v, int primero, int medio, int ultimo) {
  std::vector<Key> aux(ultimo - primero + 1);
  int i{primero}, k{medio + 1}, z{0};

  // Ordenamos los elementos en el vector aux
  while (i <= medio && k <= ultimo) {
    if (v[i] <= v[k]) {
      aux[z++] = v[i++];
    } else {
      aux[z++] = v[k++];
    }
  }

  // Insertamos los elementos restantes de los subvectores en el vector aux
  while (i <= medio) {
    aux[z++] = v[i++];
  }

  while (k <= ultimo) {
    aux[z++] = v[k++];
  }

  // Copiamos todos los elementos de aux hacia v
  for (int i{0}; i < z; ++i) {
    v[primero + i] = aux[i];
  }
}

// Función principal para realizar el Merge Sort
template <class Key>
void mergeSort(std::vector<Key>& v, int primero, int ultimo, bool traza) {
  if (primero == 0 && ultimo == (v.size() - 1)) {
    std::cout << "Secuencia original: " << std::endl;
    PrintVector(v);
    std::cout << "-------------------------------" << std::endl;
  }

  if (primero < ultimo) {
    int central{(primero + ultimo) / 2};
    mergeSort(v, primero, central, traza);  // Ordenamos la sublista izquierda
    mergeSort(v, (central + 1), ultimo, traza);  // Ordenamos la sublista derecha
    Mezcla(v, primero, central,
           ultimo);  // Mezclar los elementos ordenados
    // Imprimir la traza
    if (traza) {
      std::cout << "Traza: ";
      for (int i = primero; i <= ultimo; ++i) {
        std::cout << v[i] << " ";
      }
      std::cout << std::endl;
    }
  } 
  // Mostrar el vector ordenado en la última iteración
    if (primero == 0 && ultimo == (v.size() - 1) && !traza) {
      std::cout << "Vector ordenado: " << std::endl;
      PrintVector(v);
      std::cout << "-------------------------------" << std::endl;
    }
}

////////////////////////////////
// ======= RADIXSORT =======

// Función auxiliar para el Radix Sort para obtener el máximo valor en un vector
template <class Key>
int obtenerMaximo(std::vector<Key>& vec) {
  int maximo = vec[0];
  for (int i = 1; i < vec.size(); i++) {
    if (vec[i] > maximo) {
      maximo = vec[i];
    }
  }
  return maximo;
}

// Función para realizar el RadixSort
template <class Key>
void radixSort(std::vector<Key>& vec, bool traza) {
  std::cout << "Secuencia original: " << std::endl;
  PrintVector(vec);
  std::cout << "-------------------------------" << std::endl;
  // Obtener el valor máximo en el vector
  int maximo = obtenerMaximo(vec), numero_fase{1};

  // Iterar a través de cada dígito del número, comenzando desde el menos
  // significativo
  for (int exp = 1; maximo / exp > 0; exp *= 10) {
    // Crear un vector de salida y un arreglo de conteo
    std::vector<Key> salida(vec.size());
    int conteo[10] = {0};

    // Calcular el conteo de frecuencia para cada dígito
    for (int i = 0; i < vec.size(); i++) {
      conteo[(vec[i] / exp) % 10]++;
    }

    // Calcular las posiciones finales de cada elemento en la salida
    for (int i = 1; i < 10; i++) {
      conteo[i] += conteo[i - 1];
    }

    // Colocar cada elemento en su posición correcta en la salida
    for (int i = vec.size() - 1; i >= 0; i--) {
      salida[conteo[(vec[i] / exp) % 10] - 1] = vec[i];
      conteo[(vec[i] / exp) % 10]--;
    }

    // Copiar el vector de salida al vector original
    for (int i = 0; i < vec.size(); i++) {
      vec[i] = salida[i];
    }
    if (traza) { // Vamos mostrando la traza
      std::cout << "Fase " << numero_fase++ << ":" << std::endl;
      PrintVector(vec);
      std::cout << "-------------------------------" << std::endl;
    }
  }
  if (!traza) { // El usuario ha introducido los números aleatoriamente
    std::cout << "Vector ordenado: " << std::endl;
    PrintVector(vec);
  }
}

#endif
