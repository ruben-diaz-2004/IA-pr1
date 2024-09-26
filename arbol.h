/**
 * Clase árbol
 */

#ifndef _ARBOL_H
#define _ARBOL_H

#include "fstream"
#include "nodo.h"
#include "vector"

class Arbol {
public:
  Arbol(std::fstream& fichero_entrada, int origen, int destino);
  void PrintCostes();
private:
  Nodo* raiz_;
  int origen_;
  int destino_;
  std::vector<std::vector<int>> matriz_costes_;
  int numero_de_nodos_;
};




#endif