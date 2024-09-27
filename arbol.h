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
  void RecorridoAmplitud();
  bool CompruebaRama(Nodo* nodo, int identificador);
  void ImprimeCamino(Nodo* nodo);
  void PrintCostes();
  void PrintGenerados();
  void PrintVisitados();
private:
  Nodo* raiz_;
  int origen_;
  int destino_;
  std::vector<std::vector<double>> matriz_costes_;
  int numero_de_nodos_;
  std::vector<int> nodos_visitados_;
  std::vector<int> nodos_generados_;
  int iteracion_;
};




#endif