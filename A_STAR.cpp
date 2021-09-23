#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include "A_STAR.hpp"

using std::cout;
using std::endl;
using std::invalid_argument;
using std::string;
using std::istringstream;
using std::ifstream;
using std::getline;

bool operator==(const Node &n1, const Node &n2) {
  return (n1.x == n2.x && n1.y == n2.y);
}

A_STAR::A_STAR(string path) : path{path} {
  ReadFile();
  ReadGrid();
  node.g = 0;
}

vector<vector<int>> A_STAR::ReadFile() {
  ifstream InputFile(path);
  if (InputFile) {
    string line;
    while (getline(InputFile, line))
      board.push_back(ParseLine(line));
    return board;
  }
  throw invalid_argument("Exception: can not read the file!");
}

vector<int> A_STAR::ParseLine(string line) {
  int num;
  char c;
  vector<int> LineInt;
  istringstream LineStream(line);
  while (LineStream >> num >> c)
    LineInt.push_back(num);
  return LineInt;
}

void A_STAR::ReadGrid() {
  grid.clear();
  for (auto y : board) {
    vector<State> Line;
    for (auto x : y) {
      if (x == 0)
        Line.push_back(State::Empty);
      else if (x == 1)
        Line.push_back(State::Obstacle);
    }
    grid.push_back(Line);
  }
}

vector<vector<int>> A_STAR::GetBoard() { return board; }
vector<vector<State>> A_STAR::GetGrid() { return grid; }

bool A_STAR::ChckPoint(const Node &n) {
  return (n.x >= 0 && n.x < grid.size() && n.y >= 0 && n.y < grid[0].size());
}

void A_STAR::Search(int x1, int y1, int x2, int y2) {
  node.x = x1;
  node.y = y1;
  node.h = heuristic(x1, y1, x2, y2);
  node.g = 0;
  node.f = node.g + node.h;
  goal.x = x2;
  goal.y = y2;
  if (!(ChckPoint(node) && ChckPoint(goal)))
    throw invalid_argument(
        "Exception: points passed is out of range of the grid!");
  if (grid[x1][y1] != State::Empty)
    throw invalid_argument(
        "Exception: the given start/stop point should be empty!");
  PathToGoal.push_back(node);
  grid[x1][y1] = State::Start;
  while (!(node == goal)) {
    StepMove();
    if (node == goal)
      grid[node.x][node.y] = State::End;
    else
      grid[node.x][node.y] = State::Path;
  }
}

void A_STAR::findNeighbours(vector<Node> &v1) {
  auto current = node;
  current.g += 1;
  for (int cnt = 0; cnt < 4; cnt++) {
    current.x = node.x + delta[cnt][0];
    current.y = node.y + delta[cnt][1];
    current.h = heuristic(current.x, current.y, goal.x, goal.y);
    current.f = current.g + current.h;
    if (ChckPoint(current) && grid[current.x][current.y] == State::Empty)
      v1.push_back(current);
  }
}
void A_STAR::StepMove() {
  vector<Node> vec{};
  findNeighbours(vec);
  sort(vec.begin(), vec.end(),
       [](auto n1, auto n2) -> bool { return (n1.g + n1.h) > (n2.g + n2.h); });

  if (vec.empty()) {
    grid[node.x][node.y] = State::Close;
    PathToGoal.pop_back();
    node = PathToGoal.back();
    grid[node.x][node.y] = State::Empty;
    return;
  }
  node = vec.back();
  PathToGoal.push_back(node);
  vec.pop_back();
}

bool A_STAR::equal(Node &n1, Node &n2) const {
  return (n1.x == n2.x && n1.y == n2.y);
}

vector<Node> A_STAR::getPath() const { return PathToGoal; }

int A_STAR::heuristic(int x1, int y1, int x2, int y2) {
  return (abs(x2 - x1) + abs(y2 - y1));
}
