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
      if (lista[i].second == true)
      std::cout << lista[i].first << " ";
    }
    std::cout << std::endl;
} 

std::vector<std::pair<int, bool>> remove (std::vector<std::pair<int, bool>> lista, int i) {

    if (lista[i-1].second == true) {
      for (unsigned j = i*i; j <= lista.size(); j += i) {
        
        lista[j-1].second = false;
        
      }
    }
  return lista;
}

std::vector<std::pair<int, bool>> sieve (std::vector<std::pair<int, bool>> lista) {

  for (unsigned i = 2; i*i <= lista.size(); i++) {
    lista = remove(lista, i);
    
  }
  return lista;
}

std::vector<std::pair<int, bool>> delete_no_primes (std::vector<std::pair<int, bool>> lista) {

   
   for (unsigned i = 0; i < lista.size(); i++) {
     
      if (lista[i].second == false)
        
        lista.erase(lista.begin() + i);
    }
    
 
  
  return lista;
} 


int main (int argc, char *argv[]) {

  int numeroMax = atoi(argv[1]);

  std::vector< std::pair<int, bool> > lista;
  lista = rellenar(numeroMax);
 
  lista = sieve(lista);
  lista = delete_no_primes(lista);
  write(lista);
    
}
