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

#ifndef _NODO_H
#define _NODO_H

#include <vector>

class Nodo {
public:
  Nodo(const int& identificador, const double& coste, Nodo* padre) : identificador_{identificador}, coste_{coste}, padre_{padre} {}
  Nodo(const int& identificador, const double& coste) : identificador_{identificador}, coste_{coste}, padre_{nullptr} {}
  int GetIdentificador() const { return identificador_; }
  double GetCoste() const { return coste_; }
  Nodo* GetPadre() const { return padre_; }
  void SetPadre(Nodo* padre) { padre_ = padre; }
  void NuevoHijo(Nodo* hijo) { hijos_.push_back(hijo); }
  Nodo* GetHijo(int i) { return hijos_[i]; }
  int GetNumeroHijos() { return hijos_.size(); }
private:
  int identificador_;
  double coste_;
  Nodo* padre_;
  std::vector<Nodo*> hijos_;
};


#endif