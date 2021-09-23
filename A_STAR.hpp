#ifndef A_STAR_HPP
#define A_STAR_HPP

#include <iostream>
#include <string>
#include <vector>
using std::endl;
using std::string;
using std::vector;

enum class State { Empty, Obstacle, Start, Path, End, Close };

struct Node {
  uint32_t x;
  uint32_t y;
  uint32_t g; // cost function value
  uint32_t h; // heuristic value
  uint32_t f;
  friend bool operator==(const Node &n1, const Node &n2);
};

class A_STAR {
private:
  string path;
  vector<vector<int>> board;
  vector<vector<State>> grid;
  Node node;
  Node goal;
  vector<Node> PathToGoal;
  const int delta[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  vector<int> ParseLine(string line);
  vector<vector<int>> ReadFile();
  // check if this point belongs to the Grid
  bool ChckPoint(const Node &);
  void StepMove();
  int heuristic(int x1, int y1, int x2, int y2);
  void ReadGrid();
  bool equal(Node &n1, Node &n2) const;
  void findNeighbours(vector<Node> &v1);

public:
  A_STAR(string path = "file.txt");
  vector<std::vector<State>> GetGrid();
  vector<vector<int>> GetBoard();
  void Search(int x1, int y1, int x2, int y2);
  vector<Node> getPath() const;
  friend std::ostream &operator<<(std::ostream &out, vector<vector<int>> board);
  friend std::ostream &operator<<(std::ostream &out, vector<vector<State>> Grid);
  friend std::ostream &operator<<(std::ostream &out, const vector<Node> v);
};

inline std::ostream &operator<<(std::ostream &out, vector<vector<int>> board) {
  for (auto x : board) {
    for (auto y : x)
      out << " " << y << " ";
    out << endl;
  }
  return out;
}
inline std::ostream &operator<<(std::ostream &out, vector<vector<State>> Grid) {
  for (auto x : Grid) {
    for (auto y : x) {
      switch (y) {
      case State::Empty:
        out << " E ";
        break;
      case State::Obstacle:
        out << " O ";
        break;
      case State::Start:
        out << " S ";
        break;
      case State::Close:
        out << " E ";
        break;
      case State::Path:
        out << " P ";
        break;
      case State::End:
        out << " F ";
        break;
      }
    }
    out << endl;
  }
  return out;
}
inline std::ostream &operator<<(std::ostream &out, const vector<Node> v) {
  out << "size of path = " << v.size() << endl;
  for (auto it : v)
    out << "x = " << it.x << " , y = " << it.y << " , h = " << it.h
        << " , f = " << it.f << endl;
  return out;
}
#endif