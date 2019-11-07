#include <iostream>
#include <vector>


struct Vertex{
    int a;
    std::vector<Vertex*> next;
    std::vector<int> capacity;
    bool visited;
};

bool isEquals(Vertex* vertex1, Vertex* vertex2){

    return true;
}

bool BFS(std::vector<Vertex>& graph, Vertex* currnt, Vertex* kik, int count){

    if(count == graph.size()-1)
        return false;

    int k = count;

    for(int i=0; i<currnt->next.size(); ++i){
        if(!isEquals(currnt, kik) && !currnt->next[i]->visited) {
            currnt->next[i]->visited = true;
            ++k;
        }
        else {
            continue;
        }
    }

    if(k == count)
        return true;

    for(auto & i : currnt->next)
        if(!BFS(graph, i, kik, k))
            return false;
    return true;
}


void clean(std::vector<Vertex>& graph){
    for(auto & i : graph)
        i.visited = false;
}

void Solve(std::vector<Vertex>& graph){
    int max = INT32_MAX;
    for(int i=0; i< graph.size(); ++i){
        for(int j=0; j<graph[i].next.size(); ++j){
            if(BFS(graph, &graph[i], graph[i].next[j], 0)) {
                if (max > graph[i].capacity[j]) {
                    max = graph[i].capacity[j];
                }
            }
            clean(graph);
        }
    }
    std::cout<<"SOLVE = "<<max;

}

int ReadNum(){
    int x;
    std::cin>>x;
    return x;
}

std::vector<std::vector<int>> ReadGraph(int m){
    std::vector<std::vector<int>> data(m, std::vector<int>(3));

    for(int i=0; i<m; ++i){
        for(int j=0; j<3; ++j) {
            int x = ReadNum();
            data[i][j] = x - 1;
        }
    }
    return data;
}

int main() {

    int citis, ways;
    ways = ReadNum();
    citis = ReadNum();
    auto data = ReadGraph(ways);

    std::vector<Vertex> graph(citis);

    for(int i=0; i<citis; ++i){
        Vertex vertex = Vertex();
        vertex.visited = false;
        vertex.a = i;
        graph[i] = vertex;
    }

    for(int i=0; i<ways; ++i){
        graph[data[i][0]].next.push_back(&graph[data[i][1]]);
        graph[data[i][0]].capacity.push_back(data[i][2]);

        graph[data[i][1]].next.push_back(&graph[data[i][0]]);
        graph[data[i][1]].capacity.push_back(data[i][2]);
    }


    for(int i=0; i<citis; ++i){
        for(int j=0; j<graph[i].next.size(); ++j)
            std::cout<<"from = " <<graph[i].a + 1<<" to "<<graph[i].next[j]->a + 1<<" cap = "<<graph[i].capacity[j] + 1<<"\n";
    }

   Solve(graph);

    return 0;
}