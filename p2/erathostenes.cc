#include <iostream>
#include <vector>
#include <stdlib.h>
#include <bits/stdc++.h> 

std::vector<std::pair<int, bool>> CreateVector(int list_size) {    
    
  std::vector< std::pair <int, bool>> vector_list;
  for (int i = 0; i < list_size; i++) {
    vector_list.push_back({i+1, true});
  }
  return vector_list;
} 

void Write (std::vector<std::pair<int, bool>> vector_list) {

  for (unsigned i = 0; i < vector_list.size(); i++) {
    if (vector_list[i].second == true)
    std::cout << vector_list[i].first << " ";
  }
  std::cout << std::endl;
} 

std::vector<std::pair<int, bool>> Remove(std::vector<std::pair<int, bool>> vector_list, int i) {

  if (vector_list[i-1].second == true) {
    for (unsigned j = i*i; j <= vector_list.size(); j += i) {
      vector_list[j-1].second = false;  
    } 
  }
  return vector_list;
}

std::vector<std::pair<int, bool>> Sieve(std::vector<std::pair<int, bool>> vector_list) {

  for (unsigned i = 2; i*i <= vector_list.size(); i++) {
    vector_list = Remove(vector_list, i);    
  }
  return vector_list;
}

std::vector<std::pair<int, bool>> DeleteNoPrimes(std::vector<std::pair<int, bool>> vector_list) {
   
  for (unsigned i = 0; i < vector_list.size(); i++) {   
    if (vector_list[i].second == false)      
      vector_list.erase(vector_list.begin() + i);
    }
  return vector_list;
} 

int main (int argc, char *argv[]) {

  int max_number = atoi(argv[1]);
  std::vector< std::pair<int, bool> > vector_list;
  vector_list = CreateVector(max_number); 
  vector_list = Sieve(vector_list);
  vector_list = DeleteNoPrimes(vector_list);
  write(vector_list);
    
}
