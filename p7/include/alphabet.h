#include <iostream>
#include <string>
#include <set>

/**
 * \class Alphabet
 * This simple class allow to organizate a set of strings that complements the code.
 * Contain some getters like Size() and GetAlphabet().
 */

class Alphabet {
private:
  std::set<std::string> all_alphabets_;
public:

  Alphabet();
  ~Alphabet();
  
  void SetAlphabet(std::string alphabet);
  int Size();
  std::set<std::string> GetAlphabet();
};

