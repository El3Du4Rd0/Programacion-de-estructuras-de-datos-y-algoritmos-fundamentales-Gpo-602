#include <iostream>
#include <string>
#include <fstream>

#include "heap.h"

// estrctura de datos donde se defines los valores que puede tener una carta
struct Carta{
  std::string nomb;
  int cost, ataq, vida;
  int bandera;

  Carta() : nomb(""), cost(0), ataq(0), vida(0) , bandera(0) {}
  Carta(std::string n, int c, int a, int v) : nomb(n), cost(c), ataq(a), vida(v), bandera(0) {}
  Carta(std::string n, int c, int a, int v, int b) : nomb(n), cost(c), ataq(a), vida(v), bandera(b) {}

  bool menor_cost(const Carta &c) { return c.cost < this->cost; }
  bool mayor_cost(const Carta &c) { return c.cost > this->cost; }
  bool menor_ataque(const Carta &c) { return c.ataq < this->ataq; }
  bool mayor_ataque(const Carta &c) { return c.ataq > this->ataq; }
  bool menor_vida(const Carta &c) { return c.vida < this->vida; }
  bool mayor_vida(const Carta &c) { return c.vida > this->vida; }

  bool operator < (const Carta &c) {
    if (bandera == 0){
      return mayor_cost(c);
    } else if (bandera == 1){
      return mayor_ataque(c);
    } else if (bandera == 2){
      return mayor_vida(c);
    } else if (bandera == 3){
      return c.nomb > this->nomb;
    }
  }

  bool operator > (const Carta &c) {
    if (bandera == 0){
      return menor_cost(c);
    } else if (bandera == 1){
      return menor_ataque(c);
    } else if (bandera == 2){
      return menor_vida(c);
    } else if (bandera == 3){
      return c.nomb < this->nomb;
    }
  }
};

void leer(Heap<Carta> &H, int orden) {
  std::ifstream arch("lista_cartas.txt");

  // se crean variables tipo int y string para la posicion de las comas y la linea de lectura
  int coma_1, coma_2, coma_3;
  std::string linea;

  // while que se ejecuta hasta que ya no se lean lineas en el archivo txt
  while(getline(arch, linea)){

    // se define el valor de las comas segun su posicion en la linea de texto
    coma_1 = linea.find(",");
    coma_2 = linea.find(",", coma_1 + 1);
    coma_3 = linea.find(",", coma_2 + 1);

    H.push(Carta(
      linea.substr(0, coma_1),
      std::stoi(linea.substr(coma_1 + 1, coma_2 - coma_1 - 1)),
      std::stoi(linea.substr(coma_2 + 1, coma_3 - coma_2 - 1)),
      std::stoi(linea.substr(coma_3 + 1)), orden
    ));
  }

  arch.close();
}

void escribir(Carta &c){
  std::ofstream arch("lista_cartas.txt", std::ios::app);

  arch << '\n' << c.nomb << ',' << c.cost << ',' << c.ataq << ',' << c.vida;

  arch.close();
}

int main(){
  // se crea un objeto heap de tipo carta
  Heap<Carta> heap(200);

  bool bandera; bandera = true;

  while(bandera){
    std::cout << "que quieres hacer? " << std::endl
      << "1. Agregar cartas" << std::endl 
      << "2. Extraer heap de cartas" << std::endl;

    int aux; std::cin >> aux;

    switch (aux) {
      case 1:
      {
        std::string nom;
        int c, a, v;

        std::cout << "¿Cuantas cartas quieres agregar?" << '\n';
        int cantidad; std::cin >> cantidad;

        for(int i = 0; i < cantidad; i++){
          std::cout << "Nombre: "; std::cin >> nom;
          std::cout << "Coste: "; std::cin >> c;
          std::cout << "Ataque: "; std::cin >> a;
          std::cout << "Vida: "; std::cin >> v;

          Carta nueva_carta(nom,c,a,v);
          escribir(nueva_carta);
        }
      }
        break;
      case 2:
      {
        std::cout << "En que orden quieres mostrar las cartas:" << '\n'
        << "0. Coste." << '\n'
        << "1. Ataque." << '\n'
        << "2. Vida." << '\n'
        << "3. Nombre." << '\n';

        int aux; std::cin >> aux;
        leer(heap, aux);

        while (!heap.empty()) {
          Carta carta = heap.top();
          std::cout << "Nombre: " << carta.nomb << '\n' << '\t'
            << "- Coste: " << carta.cost << ", Ataque: " << carta.ataq 
            << ", Vida: " << carta.vida << '\n' << '\n';
          heap.pop();
        }
      }
        break;
      default:

        bandera = false;
        break;
    }
  }

  return 0;
}