#include <iostream>
#include <string>
#include <set>

/**
 * \class Grammar
 */

class Grammar {
private:
  int number_productions_ = 0;
  std::set<std::string> alphabet_;
  std::set<std::string> collection_noterminal_;
  std::string initial_noterminal_;
  std::string productions_;
  std::set<std::string> collection_productions_;

public:

  Grammar();
  Grammar(std::set<std::string> alphabet, std::set<std::string> collection_noterminal, std::string initial_noterminal, std::set<std::string> collection_productions);
  ~Grammar();

  void SetAlphabet(std::string alphabet);
  void SetNoTerminals(std::set<std::string> collection_noterminal);
  void SetInitialNoTerminal(std::string initial_noterminal);
  void SetProductions(std::string production);
  
  void IncreaseNumberProductions() {number_productions_++;} 

  int GetNumberProducts();
  int GetAlphabetSize();
  int GetNoTerminalSize();
  std::string GetInitialNoTerminal();

  std::set<std::string> GetAlphabet();
  std::set<std::string> GetCollectionNoTerminal();
  std::set<std::string> GetCollectionProductions();

  void writeGrammarFile(std::string file, Grammar& grammar);
};

