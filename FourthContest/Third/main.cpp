#include <iostream>
#include <vector>


struct Vertex {
    int a;
    std::vector<int> next;
    std::vector<int> capacity;
    bool visited;
};

bool isCorrect(int first, int second, int first_kik, int second_kik) {

    if((first == first_kik && second == second_kik) || (first == second_kik && second_kik == second))
        return false;

    return true;
}

bool BFS(std::vector<Vertex> &graph, int first_kik, int second_kik, int& count, int current) {

    std::cout<<"curent = " << current + 1 << "count = " << count<<"\n";

    if(count == graph.size() - 1)
        return false;


    std::vector<int> nextvertex;

    for(int i=0; i<graph[current].next.size(); ++i){
        if(isCorrect(current, graph[current].next[i], first_kik, second_kik) && !graph[graph[current].next[i]].visited){
            graph[graph[current].next[i]].visited = true;
            //++count;
            nextvertex.push_back(graph[current].next[i]);
        }
    }

    for(int i=0; i < nextvertex.size(); ++i){
        if(!BFS(graph, first_kik, second_kik, ++count, nextvertex[i]))
            return false;
    }

    return true;
}


void clean(std::vector<Vertex> &graph) {
    for (auto &i : graph)
        i.visited = false;
}

void Solve(std::vector<Vertex> &graph,  std::vector<std::vector<int>> data) {

    int max = INT32_MAX;
    for(int i=0; i<data.size(); ++i){
        graph[data[i][0]].visited = true;
        int count = 0;
        if(BFS(graph, data[i][0], data[i][1], count, data[i][0])){
            if(data[i][2] < max)
                max = data[i][2] + 1;
            std::cout<<"now is "<< data[i][0] + 1<< " "<<data[i][1] + 1<<"\n";
        }
        clean(graph);
    }

    std::cout<<"SOLVE = "<<max;
}

int ReadNum() {
    int x;
    std::cin >> x;
    return x;
}

std::vector<std::vector<int>> ReadGraph(int m) {

    std::vector<std::vector<int>> data(m, std::vector<int>(3));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 3; ++j) {
            int x = ReadNum();
            data[i][j] = x - 1;
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

    for (int i = 0; i < citis; ++i) {
        Vertex vertex = Vertex();
        vertex.visited = false;
        vertex.a = i;
        graph[i] = vertex;
    }

    for (int i = 0; i < ways; ++i) {

        graph[data[i][0]].next.push_back(data[i][1]);
        graph[data[i][0]].capacity.push_back(data[i][2]);

        graph[data[i][1]].next.push_back(data[i][0]);
        graph[data[i][1]].capacity.push_back(data[i][2]);

    }

    std::cout << "\n";

    for (int i = 0; i < citis; ++i) {
        for (int j = 0; j < graph[i].next.size(); ++j)
            std::cout << "from = " << graph[i].a + 1 << " to " << graph[i].next[j] + 1 << " cap = "
                      << graph[i].capacity[j] + 1 << "\n";
        std::cout << "\n";
    }

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";

    Solve(graph, data);

    /*graph[data[2][0]].visited = true;
    int count = 0;
    std::cout<<BFS(graph, data[2][0], data[2][1], count, data[2][0]);*/

    return 0;
}