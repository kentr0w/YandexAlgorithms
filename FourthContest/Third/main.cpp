#include <iostream>
#include <vector>


struct Vertex {
    std::vector<int> next;
    std::vector<int> capacity;
    bool visited;
};

bool isCorrect(int first, int second, int first_kik, int second_kik) {
    return !((first == first_kik && second == second_kik) ||
    (first == second_kik && second_kik == second));
}

bool BFS(std::vector<Vertex> &graph, int first_kik, int second_kik,
        unsigned long &count, int current) {
    if (count == graph.size() - 1)
        return false;
    std::vector<int> nextvertex;
    for (size_t index = 0; index < graph[current].next.size(); ++index) {
        if (isCorrect(current, graph[current].next[index], first_kik, second_kik) &&
            !graph[graph[current].next[index]].visited) {
            graph[graph[current].next[index]].visited = true;
            nextvertex.push_back(graph[current].next[index]);
        }
    }
    for (int element : nextvertex) {
        if (!BFS(graph, first_kik, second_kik, ++count, element))
            return false;
    }
    return true;
}

void clean(std::vector<Vertex> &graph) {
    for (auto &element : graph)
        element.visited = false;
}

void Solve(std::vector<Vertex> &graph, std::vector<std::vector<int>> data) {

    int max = INT32_MAX;
    bool isChange = false;
    for (size_t index = 0; index < data.size(); ++index) {
        graph[data[index][0]].visited = true;
        unsigned long count = 0;
        if (BFS(graph, data[index][0], data[index][1], count, data[index][0])) {
            if (data[index][2] < max) {
                max = data[index][2] + 1;
                isChange = true;
            }
        }
        clean(graph);
    }
    isChange ? std::cout << max : std::cout << -1;
}

int ReadNum() {
    int num;
    std::cin >> num;
    return num;
}

std::vector<std::vector<int>> ReadGraph(int ways) {

    std::vector<std::vector<int>> data(ways, std::vector<int>(3));

    for (int i = 0; i < ways; ++i) {
        for (int j = 0; j < 3; ++j) {
            int num = ReadNum();
            data[i][j] = num - 1;
        }
    }
    return data;
}

int main() {

    int citis, ways;
    citis = ReadNum();
    ways = ReadNum();
    auto data = ReadGraph(ways);

    std::vector<Vertex> graph(citis);


    for (int index = 0; index < citis; ++index) {
        Vertex vertex = Vertex();
        vertex.visited = false;
        graph[index] = vertex;
    }

    for (int index = 0; index < ways; ++index) {
        graph[data[index][0]].next.push_back(data[index][1]);
        graph[data[index][0]].capacity.push_back(data[index][2]);
        graph[data[index][1]].next.push_back(data[index][0]);
        graph[data[index][1]].capacity.push_back(data[index][2]);
    }

    Solve(graph, data);

    return 0;
}