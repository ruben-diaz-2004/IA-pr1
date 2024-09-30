/**
 * Clase árbol
 */

#ifndef _ARBOL_H
#define _ARBOL_H

#include "fstream"
#include "nodo.h"
#include "vector"
#include "stack"

class Arbol {
public:
  Arbol(std::fstream& fichero_entrada, int origen, int destino);
  ~Arbol();
  void RecorridoAmplitud();
  void EliminaNodosAmplitud(Nodo* nodo);
  // void RecorridoProfundidad();
  bool RecorridoProfundidad(Nodo* nodo);
  bool CompruebaRama(Nodo* nodo, int identificador);
  void ImprimeCamino(Nodo* nodo);
  void PrintCostes();
  void PrintGenerados();
  void PrintVisitados();
  Nodo* GetRaiz() { return raiz_; }
private:
  Nodo* raiz_;
  int origen_;
  int destino_;
  std::vector<std::vector<double>> matriz_costes_;
  int numero_de_nodos_;
  std::vector<int> nodos_visitados_;
  std::vector<int> nodos_generados_;
  int iteracion_;
  // Imprimimos la salida por un fichero
  std::ofstream fichero_salida{"salida.txt"};
};




#endif