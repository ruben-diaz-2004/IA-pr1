/**
 * Clase nodo
 */

#ifndef _NODO_H
#define _NODO_H

class Nodo {
public:
  Nodo(const int& identificador, const double& coste, Nodo* padre) : identificador_{identificador}, coste_{coste}, padre_{padre} {}
  Nodo(const int& identificador, const double& coste) : identificador_{identificador}, coste_{coste}, padre_{nullptr} {}
  int GetIdentificador() const { return identificador_; }
  double GetCoste() const { return coste_; }
  Nodo* GetPadre() const { return padre_; }
  void SetPadre(Nodo* padre) { padre_ = padre; }
private:
  int identificador_;
  double coste_;
  Nodo* padre_;
  // vector de nodos vecinos (almacenar puntero y coste?) 
};


#endif