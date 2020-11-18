#include <iostream>
#include <string>
#include <set>

/**
 * \class Alphabet
 * This simple class allow to organizate a set of strings that complements the code.
 */

class Alphabet {
private:
  std::set<std::string> all_alphabets_;
public:

/**
 * \fn Default Constructor of the class Alphabet
 */
  Alphabet();
/**
 * \fn Default destructor of the class Alphabet
 */
  ~Alphabet();
  
  void SetAlphabet(std::string alphabet);
  int Size();
  std::set<std::string> GetAlphabet();
};

