/**
 * Implementación de la clase árbol
 */


#include "arbol.h"
#include "nodo.h"
#include <iostream>
#include <vector>
#include <queue>

Arbol::Arbol(std::fstream& fichero_entrada, int origen, int destino) : origen_{origen}, destino_{destino} {
  int numero_de_nodos{0};
  int numero_de_aristas{0};
  
  fichero_entrada >> numero_de_nodos;
  numero_de_nodos_ = numero_de_nodos;
  matriz_costes_.resize(numero_de_nodos);
  for (int i{0}; i < numero_de_nodos; ++i) {
    for (int j{0}; j < numero_de_nodos; ++j) {
      matriz_costes_[i].push_back(0);
    }
  }
  PrintCostes();

  double auxiliar{0};
  for (int i{0}; i < numero_de_nodos; ++i) {
    for (int j{i+1}; j < numero_de_nodos; ++j) {
      fichero_entrada >> auxiliar;
      if (auxiliar != -1) ++numero_de_aristas;
      matriz_costes_[i][j] = auxiliar;
      matriz_costes_[j][i] = auxiliar;
    }
  }

  raiz_ = new Nodo(origen_, 0);
}


void Arbol::PrintCostes() {
  std::cout << "Matriz de costes: \n";
  
  for (int i{0}; i < numero_de_nodos_; ++i) {
    for (int j{0}; j < numero_de_nodos_; ++j) {
      std::cout << matriz_costes_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}


void Arbol::RecorridoAmplitud() {
  std::queue<Nodo*> cola_nodos;
  cola_nodos.emplace(raiz_);
  bool solucion = false;
  int identificador_actual{0};
  while (!cola_nodos.empty() && solucion == false) {
  Nodo nodo_actual = *cola_nodos.front();
  cola_nodos.pop();
  identificador_actual = nodo_actual.GetIdentificador();
  if (identificador_actual == destino_) {
    solucion = true;
    std::cout << "Se ha encontrado una solución: \n";
    // Imprimir camino y calcular coste
  } else {
    for (int i{0}; i < numero_de_nodos_; ++i) {
      if (matriz_costes_[identificador_actual][i] != -1) {  // Hay que comprobar que no se haya visitado ya
        Nodo* nodo_nuevo = new Nodo(i+1, matriz_costes_[identificador_actual][i], &nodo_actual); // Comprobar que el identificador es correcto
        cola_nodos.emplace(nodo_nuevo);
      }
    }
  }
  }
}