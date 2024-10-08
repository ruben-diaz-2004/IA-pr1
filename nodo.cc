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


#include "nodo.h"
#include <vector>



Nodo::~Nodo() {
  for (int i{0}; i < hijos_.size(); i++) {
    if (hijos_[i] != nullptr) delete hijos_[i];
  }
}


void Nodo::EliminaHijo(Nodo* hijo) {
  for (int i{0}; i < hijos_.size(); ++i) {
    if (hijos_[i] == hijo) hijos_.erase(hijos_.begin() + i);
  }
}