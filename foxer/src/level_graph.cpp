#include "foxer/game/level/level_graph.hpp"

namespace fox {

LevelGraph::LevelGraph(int V) {
  this->V = V;
  adjacents = new std::list<unsigned short>[V];
  distance = new std::vector<short>[V];

  for (int i = 0; i < V; ++i)
    distance[i].resize(V);

  for (int i = 0; i < V; ++i) {
    for (int j = i + 1; j < V; ++j) {
      distance[i][j] = SHRT_MAX;
      distance[j][i] = SHRT_MAX;
    }
    distance[i][i] = 0;
  }
}

LevelGraph::~LevelGraph() {
  delete[] distance;
  delete[] adjacents;
}

void LevelGraph::add_edge(unsigned short v, unsigned short w) {
  adjacents[v - 1].push_back(w - 1);
  adjacents[w - 1].push_back(v - 1);
}

void LevelGraph::bfs(unsigned short s) {
  bool *visited = new bool[V];
  unsigned short *father = new unsigned short[V];

  for (int i = 0; i < V; ++i)
    visited[i] = false;

  std::list<unsigned short> queue;

  visited[s] = true;
  father[s] = s;
  queue.push_back(s);

  while (!queue.empty()) {
    unsigned short current = queue.front();
    queue.pop_front();

    if (distance[s][current] > distance[s][father[current]] + 1)
      distance[s][current] = distance[s][father[current]] + 1;

    for (std::list<unsigned short>::iterator i = adjacents[current].begin();
         i != adjacents[current].end(); ++i)
      if (!visited[*i]) {
        visited[*i] = true;
        father[*i] = current;
        queue.push_back(*i);
      }
  }

  delete[] father;
  delete[] visited;
}

void LevelGraph::print_distances() {
  for (int i = 0; i < V; ++i) {
    std::cout << "{ ";
    for (int j = 0; j < V; ++j)
      std::cout << distance[i][j] << " ";
    std::cout << "}" << std::endl;
  }
}

void LevelGraph::apsp() {
  for (int i = 0; i < V; ++i)
    bfs(i);
}

} // namespace fox
