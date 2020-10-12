#include <iostream>
#include <vector>
#include <stdlib.h>
#include <bits/stdc++.h> 

 std::vector<std::pair<int, bool>> rellenar(int numero) {
    
    std::vector< std::pair <int, bool>> lista;

    for (int i = 0; i < numero; i++) {
      lista.push_back({i+1, true});
    }
   
    return lista;
} 

void write (std::vector<std::pair<int, bool>> lista) {

   for (unsigned i = 0; i < lista.size(); i++) {
      std::cout << lista[i].first << " " << lista[i].second << " |" << std::endl;
    }
} 

int main (int argc, char *argv[]) {

  int numeroMax = atoi(argv[1]);

  std::vector< std::pair<int, bool> > lista;
  lista = rellenar(numeroMax);
 
 
    
}
