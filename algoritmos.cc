#include "algoritmos.hpp"

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
void Insercion(std::vector<Key>& numeros) {
  int aux;
  for (int i{0}; i < numeros.size(); ++i) {
    int posicion{i};
    aux = numeros[i]; // Número actual 
    while((posicion > 0) && (numeros[posicion - 1] > aux)) {
      numeros[posicion] = numeros[posicion - 1];
      posicion--;
    }
    numeros[posicion] = aux;
    // Mostramos la traza de el algoritmo
    std::cout << "Iteración número " << i << ":" << std::endl;
    PrintVector(numeros);
    std::cout << "-------------------------------" << std::endl;
  }
}

/////////////////////////////////////////////////////////
// ======= SHELLSORT =======
template <class Key>
void shellSort(std::vector<Key>& secuencia, double alfa) {
  auto salto{(secuencia.size() * alfa) / 2};
  auto n{secuencia.size()};
  int iterador{1};
  std::cout << "Secuencia original: " << std::endl;
  PrintVector(secuencia);
  std::cout << "-------------------------------" << std::endl;
  while (salto > 0) {
    bool print{false};
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
      if (print) {
        std::cout << "Iteración número " << iterador++ << ":" << std::endl;
        PrintVector(secuencia);
        std::cout << "-------------------------------" << std::endl;
      }
    }
    salto /= 2;
  }
}

////////////////////////////////////////////////////////////////////////
// ======= HEAPSORT =======
template <class Key>
void ConvertirEnHeap(std::vector<Key>& vector, int n, int i) {
  int largest = i; // Inicializa largest como la raíz, ya que usamos índices basados en 0
  int l = 2 * i + 1; // left = 2*i + 1
  int r = 2 * i + 2; // right = 2*i + 2

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
void heapSort(std::vector<Key>& vector, int n) {
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
    if(iteracion == 1 || iteracion == n/4 || iteracion == n/2 || iteracion == n/4*3 || iteracion == n-1) {
      std::cout << "Iteracion " << iteracion << ": ";
      for (int j = 0; j < n; j++) {
        std::cout << vector[j] << " ";
      }
      std::cout << std::endl;
    }
  }
}


//////////////////////////////////////////////////////////
// ======= MERGESORT =======
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

template <class Key>
void mergeSort(std::vector<Key>& v, int primero, int ultimo) {
  if (primero == 0 && ultimo == (v.size() - 1)) {
    std::cout << "Secuencia original: " << std::endl;
    PrintVector(v);
    std::cout << "-------------------------------" << std::endl;
  }
  
  if (primero < ultimo) {
    int central{(primero + ultimo) / 2};
    mergeSort(v, primero, central);       // Ordenamos la sublista izquierda
    mergeSort(v, (central + 1), ultimo);  // Ordenamos la sublista derecha
    Mezcla(v, primero, central,
           ultimo);  // Mezclar los elementos ordenados
    // Imprimir la traza
    std::cout << "Traza: ";
    for (int i = primero; i <= ultimo; ++i) {
      std::cout << v[i] << " ";
    }
    std::cout << std::endl;
  }
}

////////////////////////////////
// ======= RADIXSORT =======

// Función para obtener el máximo valor en un vector
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
void radixSort(std::vector<Key>& vec) {
    std::cout << "Secuencia original: " << std::endl;
    PrintVector(vec);
    std::cout << "-------------------------------" << std::endl;
    // Obtener el valor máximo en el vector
    int maximo = obtenerMaximo(vec), numero_fase{1};
    
    // Iterar a través de cada dígito del número, comenzando desde el menos significativo
    for (int exp = 1; maximo / exp > 0; exp *= 10) {
        // Crear un vector de salida y un arreglo de conteo
        std::vector<Key> salida(vec.size());
        int conteo[10] = { 0 };
        
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
        std::cout << "Fase " << numero_fase++ << ":" << std::endl;
        PrintVector(vec);
        std::cout << "-------------------------------" << std::endl;
    }
}