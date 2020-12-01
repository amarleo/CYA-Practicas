#include <iostream>
#include <string>
#include <set>

/**
 * \class Grammar
 */

class Grammar {
private:
  int number_of_terminals_;
  int number_of_no_terminals_;
  int number_of_productions_;
  std::string alphabet_;
  std::set<std::string> collection_noterminal_;
  std::string initial_noterminal_;
  std::string productions_;
  std::set<std::string> collection_productions_;

public:

  Grammar();
  Grammar(std::string alphabet, std::set<std::string> collection_noterminal, std::string initial_noterminal, std::set<std::string> collection_productions);
  ~Grammar();

  void SetAlphabet(std::string alphabet);
  void SetNoTerminals(std::set<std::string> collection_noterminal);
  void SetInitialNoTerminal(std::string initial_noterminal);
  void SetProductions(std::string production);

  void writeGrammarFile(std::string file);
};

