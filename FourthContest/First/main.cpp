#include <iostream>
#include <vector>


void Solve(std::vector<std::vector<bool>>& data, int i_start, int j_start, int i_finish, int j_finish){


}

int DFS(std::vector<std::vector<bool>>& data, int i_start, int j_start, int i_finish, int j_finish){

    return -1;
}



std::vector<std::vector<bool>> ReadData(int n, int m){
    std::vector<std::vector<bool>> data(n, std::vector<bool>(m));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            char x;
            std::cin>>x;
            if(x=='.')
                data[i][j] = true;
            else
                data[i][j] = false;
        }
    }
    return data;
}

int ReadNums(){
    int x;
    std::cin>>x;
    return x;
}

int main() {
    int n, m, i_start, j_start, i_finish, j_finish;
    n = ReadNums();
    m = ReadNums();
    auto data = ReadData(n, m);
    i_start = ReadNums();
    j_start = ReadNums();
    i_finish = ReadNums();
    j_finish = ReadNums();


    for(int i=0; i<data.size(); ++i) {
        for(int j=0; j<data[i].size(); ++j){
            std::cout<<data[i][j]<<" ";
        }
        std::cout<<"\n";
    }

    return 0;
}