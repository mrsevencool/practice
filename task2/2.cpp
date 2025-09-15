#include <iostream>
#include <vector>

// обход в глубину для пометки связной компоненты
void DFS(int v, const std::vector<std::vector<int>>& graph, std::vector<bool>& visited) {
  visited[v] = true;
  for (int u : graph[v]) {
    if (!visited[u]) {
      DFS(u, graph, visited);
    }
  }
}

int main() {
  int n = 0;
  int m = 0;

  std::cout << "Введите число узлов сети (N) и рёбер (M):";
  std::cin >> n >> m;  // читаем число узлов и рёбер
  std::cout << "Введите рёбра:";

  std::vector<std::vector<int>> graph(n); // список смежности
  for (int i = 0; i < m; ++i) {
    int u = 0;
    int v = 0;
    std::cin >> u >> v;
    --u; --v; // переходим к индексам с нуля
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  std::vector<bool> visited(n, false); // отмечаем посещённые вершины
  int components = 0;

  // считаем количество компонент связности
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      DFS(i, graph, visited); // запускаем dfs из новой вершины
      ++components;
    }
  }

  std::cout << "Число необходимых связей: " << (components - 1) << std::endl; // нужно добавить (k - 1) рёбер
  return 0;
}