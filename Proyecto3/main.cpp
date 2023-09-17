#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Funciones.h"

// estrctura de datos donde se defines los valores que puede tener una carta
struct carta{
  std::string nomb, tipo;
  int cost, ataq, vida;
};

void mostrar(std::vector<struct carta> vec){
  for ( carta carta_ : vec ){
    std::cout << carta_.nomb << " - " << carta_.tipo << '\n' << '\t'
    << carta_.cost << "/" << carta_.ataq << "/" << carta_.vida << '\n';
  }
}

int main(){
  // Se lee el archivo
  std::ifstream archivo("lista_cartas.txt");

  // definimos variables y vector principal  
  std::string linea;
  std::vector<struct carta> vec_cartas;
  int coma_1, coma_2, coma_3, coma_4;

  // while que se ejecuta hasta que ya no se lean lineas en el archivo txt
  while (getline(archivo, linea)){

    // se define el valor de las comas segun su posicion en la linea de texto
    coma_1 = linea.find(",");
    coma_2 = linea.find(",", coma_1 + 1);
    coma_3 = linea.find(",", coma_2 + 1);
    coma_4 = linea.find(",", coma_3 + 1);

    /*
    Se agrega un valor de la estructura de datos carta al vector de cartas. Los
    valores se buscan justo despues de la coma correspondiente en el archivo de 
    texto y toman los caracteres justos para obtener el dato solicitado.
    */

    vec_cartas.push_back(carta{
      nomb : linea.substr(0, coma_1),
      tipo : linea.substr(coma_1 + 1, coma_2 - coma_1 - 1),
      cost : std::stoi(linea.substr(coma_2 + 1, coma_2 - coma_3 - 1)),
      ataq : std::stoi(linea.substr(coma_3 + 1, coma_2 - coma_4 - 1)),
      vida : std::stoi(linea.substr(coma_4+1))
    });
  }

  Funciones<struct carta> fun;
  
  std::cout << '\n' << "Orden por coste de mana" << '\n' << '\n';
  fun.sort_cost(vec_cartas);
  mostrar(vec_cartas);

  std::cout << '\n' << "Orden por puntos de ataque" << '\n' << '\n';
  fun.sort_ataq(vec_cartas);
  mostrar(vec_cartas);

  std::cout << '\n' << "Orden por puntos de vida" << '\n' << '\n';
  fun.sort_vida(vec_cartas);
  mostrar(vec_cartas);
  
  std::cout << '\n' << "Busqueda de cartas" << '\n' << '\n';
  std::vector<struct carta> vec_busqueda;
  vec_busqueda.push_back(fun.search_cost(vec_cartas, 2));
  vec_busqueda.push_back(fun.search_ataq(vec_cartas, 9));
  vec_busqueda.push_back(fun.search_vida(vec_cartas, 10));
  mostrar(vec_busqueda);

  return 0;
}