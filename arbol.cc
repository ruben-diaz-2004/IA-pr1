/**
 * Implementación de la clase árbol
 */


#include "arbol.h"
#include "nodo.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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
  Nodo* nodo_actual = cola_nodos.front();
  cola_nodos.pop();
  identificador_actual = nodo_actual->GetIdentificador();
  if (identificador_actual == destino_) {
    solucion = true;
    std::cout << "Se ha encontrado una solución: \n";
    ImprimeCamino(nodo_actual);
    // Imprimir camino y calcular coste
  } else {
    for (int i{0}; i < numero_de_nodos_; ++i) {
      if (matriz_costes_[identificador_actual][i] != -1) {  
        if (!CompruebaRama(nodo_actual, i+1)) { // Comprobar que no pertenece a la rama
          Nodo* nodo_nuevo = new Nodo(i+1, matriz_costes_[identificador_actual][i], nodo_actual); // Comprobar que el identificador es correcto
          cola_nodos.emplace(nodo_nuevo);
        }
      }
    }
  }
  }
}


bool Arbol::CompruebaRama(Nodo* nodo, int identificador) {
  Nodo* nodo_auxiliar = nodo;
  while (nodo_auxiliar != nullptr) {
    if (nodo_auxiliar->GetIdentificador() == identificador) return true;
    nodo_auxiliar = nodo_auxiliar->GetPadre();
  }
  return false;
}


void Arbol::ImprimeCamino(Nodo* nodo) {
  Nodo* nodo_auxiliar = nodo;
  std::stack<int> camino;
  while (nodo_auxiliar != nullptr) {
    camino.push(nodo_auxiliar->GetIdentificador());
    nodo_auxiliar = nodo_auxiliar->GetPadre();
  }

  for (int i{0}; i < camino.size(); ++i) {
    std::cout << camino.top() << " - ";
    camino.pop();
  }
    std::cout << camino.top();
    camino.pop();

  std::cout << std::endl;
}