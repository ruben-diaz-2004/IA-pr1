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
  nodos_generados_.emplace_back(origen_);
  iteracion_ = 1;
  fichero_salida << "--------------------------------------------\n";
  fichero_salida << "Número de nodos del grafo: " << numero_de_nodos << std::endl;
  fichero_salida << "Número de aristas del grafo: " << numero_de_aristas << std::endl;
  fichero_salida << "Vértice de origen: " << origen_ << std::endl;
  fichero_salida << "Vértice de destino: " << destino_ << std::endl;
  fichero_salida << "--------------------------------------------\n";
  fichero_salida << "Iteración: " << iteracion_ << std::endl;
  iteracion_++;
  PrintGenerados();
  PrintVisitados();
  fichero_salida << "--------------------------------------------\n";
}


Arbol::~Arbol() {
  std::queue<Nodo*> cola_nodos;
  Nodo* nodo_auxiliar = raiz_;
  bool first_iteration = true;
  cola_nodos.emplace(nodo_auxiliar);
  while (!cola_nodos.empty()) {
    nodo_auxiliar = cola_nodos.front();
    cola_nodos.pop();
    if (nodo_auxiliar->GetPadre() == nullptr && !first_iteration) {
    } else {
      for (int i{0}; i < nodo_auxiliar->GetNumeroHijos(); ++i) {
        cola_nodos.emplace(nodo_auxiliar->GetHijo(i));
      }
      nodo_auxiliar->SetPadre(nullptr);
      delete nodo_auxiliar;
    }
    first_iteration = false;
  }
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
  Nodo* nodo_actual = nullptr;
  while (!cola_nodos.empty() && solucion == false) {
  nodo_actual = cola_nodos.front();
  cola_nodos.pop();
  nodos_visitados_.emplace_back(nodo_actual->GetIdentificador());
  identificador_actual = nodo_actual->GetIdentificador();
  if (identificador_actual == destino_) {
    solucion = true;
  } else {
    for (int i{0}; i < numero_de_nodos_; ++i) {
      if (matriz_costes_[identificador_actual-1][i] != -1) {  
        if (!CompruebaRama(nodo_actual, i+1)) { // Comprobar que no pertenece a la rama
          Nodo* nodo_nuevo = new Nodo(i+1, matriz_costes_[identificador_actual-1][i], nodo_actual); // Comprobar que el identificador es correcto
          cola_nodos.emplace(nodo_nuevo);
          nodos_generados_.emplace_back(i+1);
          nodo_actual->NuevoHijo(nodo_nuevo);
        }
      }
    }
  }
  fichero_salida << "Iteración: " << iteracion_ << std::endl;
  iteracion_++;
  PrintGenerados();
  PrintVisitados();
  fichero_salida << "--------------------------------------------\n";
  }
  if (!solucion) fichero_salida << "No se ha encontrado solución\n";
  else ImprimeCamino(nodo_actual);
  // EliminaNodosAmplitud(nodo_actual);
  // while (!cola_nodos.empty()) {
  //   Nodo* nodo_auxiliar = cola_nodos.front();
  //   cola_nodos.pop();
  //   EliminaNodosAmplitud(nodo_auxiliar);
  // }
}


// void Arbol::EliminaNodosAmplitud(Nodo* nodo) {
//     if (nodo->GetPadre() != nullptr) {
//       EliminaNodosAmplitud(nodo->GetPadre());
//       nodo->SetPadre(nullptr);
//     }
// }


// void Arbol::RecorridoProfundidad() {
//   std::stack<Nodo*> pila_nodos;
//   pila_nodos.emplace(raiz_);
//   bool solucion = false;
//   int identificador_actual{0};
//   Nodo* nodo_actual = nullptr;
//   while (!pila_nodos.empty() && solucion == false) {
//     nodo_actual = pila_nodos.top();
//     pila_nodos.pop();
//     nodos_visitados_.emplace_back(nodo_actual->GetIdentificador());
//     identificador_actual = nodo_actual->GetIdentificador();
//     if (identificador_actual == destino_) {
//       solucion = true;
//     } else {
//       for (int i{numero_de_nodos_-1}; i >= 0; --i) {
//         if (matriz_costes_[identificador_actual-1][i] != -1) {
//           if (!CompruebaRama(nodo_actual, i+1)) { // Comprobar que no pertenece a la rama
//             Nodo* nodo_nuevo = new Nodo(i+1, matriz_costes_[identificador_actual-1][i], nodo_actual); // Comprobar que el identificador es correcto
//             pila_nodos.emplace(nodo_nuevo);
//             nodos_generados_.emplace_back(i+1);
//           }
//         }
//       }
//     }
//     std::cout << "Iteración: " << iteracion_ << std::endl;
//     iteracion_++;
//     PrintGenerados();
//     PrintVisitados();
//     std::cout << "--------------------------------------------\n";
//   }
//   if (!solucion) std::cout << "No se ha encontrado solución\n";
//   else ImprimeCamino(nodo_actual);
// }



bool Arbol::RecorridoProfundidad(Nodo* nodo) {
  std::stack<Nodo*> pila_nodos;
  bool solucion = false;
  int identificador_actual = nodo->GetIdentificador();
  nodos_visitados_.emplace_back(identificador_actual);
    if (identificador_actual == destino_) {
      solucion = true;
    } else {
      for (int i{numero_de_nodos_-1}; i >= 0; --i) {
        if (matriz_costes_[identificador_actual-1][i] != -1) {
          if (!CompruebaRama(nodo, i+1)) { // Comprobar que no pertenece a la rama
            Nodo* nodo_nuevo = new Nodo(i+1, matriz_costes_[identificador_actual-1][i], nodo); // Comprobar que el identificador es correcto
            pila_nodos.emplace(nodo_nuevo);
            nodos_generados_.emplace_back(i+1);
            nodo->NuevoHijo(nodo_nuevo);
          }
        }
      }
    }
  fichero_salida << "Iteración: " << iteracion_ << std::endl;
  iteracion_++;
  PrintGenerados();
  PrintVisitados();
  fichero_salida << "--------------------------------------------\n";
  if (solucion) {
    ImprimeCamino(nodo);
    return true;
  }
  
  while (!pila_nodos.empty() && !solucion) {
    Nodo* nodo_actual = pila_nodos.top();
    pila_nodos.pop();
    if (RecorridoProfundidad(nodo_actual)) {
      solucion = true;
    } else {
      // std::cout << "Borrando nodo: " << nodo_actual->GetIdentificador() << std::endl;
      delete nodo_actual;
    }
  }
  
  return solucion;
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
  fichero_salida << "Camino: ";
  double coste_total{0};
  Nodo* nodo_auxiliar = nodo;

  std::stack<int> camino;
  while (nodo_auxiliar != nullptr) {
    coste_total += nodo_auxiliar->GetCoste();
    camino.push(nodo_auxiliar->GetIdentificador());
    nodo_auxiliar = nodo_auxiliar->GetPadre();
  }

  bool running = true;
  while (running) {
    fichero_salida << camino.top();
    camino.pop();
    if (camino.empty()) running = false;
    else fichero_salida << " - ";
  }

  // for (int i{0}; i < camino.size(); ++i) {
  //   std::cout << camino.top() << " - ";
  //   camino.pop();
  // }
  // std::cout << camino.top();
  // camino.pop();

  fichero_salida << std::endl;

  fichero_salida << "Costo: " << coste_total << std::endl;
}



void Arbol::PrintGenerados() {
  fichero_salida << "Nodos generados: ";
  for (int i{0}; i < nodos_generados_.size(); ++i) {
    fichero_salida << nodos_generados_[i] << " ";
  }
  fichero_salida << std::endl;
}



void Arbol::PrintVisitados() {
  fichero_salida << "Nodos inspeccionados: ";
  for (int i{0}; i < nodos_visitados_.size(); ++i) {
    fichero_salida << nodos_visitados_[i] << " ";
  }
  if (nodos_visitados_.empty()) fichero_salida << "-";
  fichero_salida << std::endl;
}