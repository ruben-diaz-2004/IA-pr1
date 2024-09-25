/**
 * Implementación de la clase árbol
 */


#include "arbol.h"


Arbol::Arbol(std::fstream& fichero_entrada, int origen, int destino) {
  int numero_de_nodos{0};
  // Coger el primer número del fichero

  for (int i{0}; i < numero_de_nodos; ++i) {
    for (int j{i+1}; j < numero_de_nodos; ++j) {
      matriz_costes_[i][j] = // sacar del fichero
      matriz_costes_[j][i] = // sacar del fichero
    }
  }
}