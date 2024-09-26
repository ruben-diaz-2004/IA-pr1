/**
 * Implementación de la clase árbol
 */


#include "arbol.h"
#include "nodo.h"
#include <iostream>

Arbol::Arbol(std::fstream& fichero_entrada, int origen, int destino) : origen_{origen}, destino_{destino} {
  int numero_de_nodos{0};
  int numero_de_aristas{0};
  // Coger el primer número del fichero
  fichero_entrada >> numero_de_nodos;
  int auxiliar{0};
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