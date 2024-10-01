/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Inteligencia Artificial 2024-2025
  * Práctica 1: Búsquedas no informadas
  * 
  * @author Rubén Díaz Marrero 
  * @date 01/10/2024
  */


#include <iostream>
#include "fstream"
#include "arbol.h"

int main(int argc, char* argv[]) {
  std::fstream fichero_de_entrada{argv[1]};

  int origen, destino;
  std::cout << "Introduce el nodo de origen: \n";
  std::cin >> origen;
  std::cout << "Introduce el nodo de destino: \n";
  std::cin >> destino;

  // Llamamos a la clase árbol
  Arbol arbol(fichero_de_entrada, origen, destino);
  // Ejecutar amplitud | profundidad
  int opcion;
  std::cout << "Introduce 1 para búsqueda en amplitud o 2 para búsqueda en profundidad: \n";
  std::cin >> opcion;
  if (opcion == 1) {
    arbol.RecorridoAmplitud();
  } else if (opcion == 2) {
    if (!arbol.RecorridoProfundidad(arbol.GetRaiz())) {
      std::cout << "No se ha encontrado solución\n";
    }
  } else {
    std::cout << "Opción no válida\n";
  }


  return 0;
}