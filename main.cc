/**
 *  Práctica #1: Búsquedas no informadas
 *  Curso: Inteligencia Artificial
 *  @date 2024-09-24
 */

/**
 * Origen-destino se pregunta por teclado
 * A la hora de elegir nodos, se elige el de menor índice
 * No se genera un nuevo nodo si ya pertenece a la rama
 */

#include <iostream>
#include "fstream"

int main() {
  std::ifstream fichero_de_entrada;
  // Recoger el fichero por parámetros

  int origen, destino;
  std::cout << "Introduce el nodo de origen: \n";
  std::cin >> origen;
  std::cout << "Introduce el nodo de destino: \n";
  std::cin >> destino;

  // Llamamos a la clase árbol

  // Ejecutar amplitud | profundidad

}