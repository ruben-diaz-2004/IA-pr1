/**
 * Clase nodo
 */



class Nodo {
public:
  Nodo(const int& identificador, const double& coste, Nodo* padre) : identificador_{identificador}, coste_{coste}, padre_{padre} {}
  Nodo(const int& identificador, const double& coste) : identificador_{identificador}, coste_{coste}, padre_{nullptr} {}
private:
  int identificador_;
  double coste_;
  Nodo* padre_;
  // vector de nodos vecinos (almacenar puntero y coste?) 
};