#include <iostream>
#include <stdexcept>
#include "A_STAR.hpp"

using std::endl;
using std::invalid_argument;

int main() {
  vector<vector<State>> grid;
  try {
    A_STAR Pathfinder /*("file.txt")*/;
    Pathfinder.Search(0, 0, 7, 6);
    grid = Pathfinder.GetGrid();
    std::cout << grid;
    // uncomment to show the points of the detected path
    // std::cout << Pathfinder.getPath();
  } catch (const invalid_argument &e) {
    std::cout << e.what() << endl;
  }
  std::cout << "Exit correctly\n";
  return 0;
}