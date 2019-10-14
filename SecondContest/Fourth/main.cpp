#include <iostream>
#include <vector>
#include <istream>
#include <fstream>
#include <algorithm>

//unsigned int cur = 0;
/*unsigned int nextRand24(unsigned long long firstElement, unsigned long long secondElement) {
    cur = static_cast<unsigned int>(cur * firstElement + secondElement);
    return cur >> 8;
}

unsigned int nextRand32(unsigned long long firstElement, unsigned long long secondElement) {
    unsigned int firstvar = nextRand24(firstElement, secondElement),
            secondvar = nextRand24(firstElement, secondElement);
    return (firstvar << 8) ^ secondvar;
}*/

size_t Partition(std::vector<int>& data, size_t leftSide, size_t rigthSide) {
    std::swap(data[leftSide], data[data.size()/2] );
    size_t pivot = data[leftSide];
    size_t left = leftSide -1, right = rigthSide + 1;
    while (true) {

        do {
            left++;
        } while (data[left] < pivot);

        do {
            right--;
        } while (data[right] > pivot);


        if(left >= right)
            return right;

        std::swap(data[left], data[right]);
        /*if(left <= right){
            std::swap(data[left], data[right]);
            ++left;
            --right;
        }*/
    }
    //return left;
}

void Qselect(std::vector<int> &data, size_t leftSide, size_t rigthSide){
    if(rigthSide <= leftSide)
        return;
    size_t order = Partition(data, leftSide, rigthSide);
    if( order >= data.size()/2){
        Qselect(data, leftSide, order);
    }
    else{
        Qselect(data, order + 1, rigthSide);
    }
}


int main() {
    /*std::ios_base::sync_with_stdio(false);
    size_t count;
    unsigned long long firstElement, secondElement;
    std::cin >> count;
    std::cin >> firstElement >> secondElement;
    std::vector<unsigned int> data;
    data.reserve(count);
    for (size_t index = 0; index < count; ++index) {
        data.push_back(nextRand32(firstElement, secondElement));
    }*/


    /*//1,1,2
    //3,1,2
    //3,4,2
    //1,1,1
    std::vector<int>data = {570, 913, 604, 844, 537, 633, 348, 432, 519, 270};
    Qselect(data, 0, data.size()-1);
    std::cout<<data[data.size()/2];*/



    std::string qwert = "";
    std::ifstream in("../testData.txt");
    std::vector<std::vector<int>> data(1000, std::vector<int>(10));
    if (in.is_open()){
        for (int i = 0; i < 1000; ++i) {
            for (int j = 0; j < 10; ++j) {
                in>>data[i][j];
            }
        }
    }
    in.close();

    std::ofstream out("../testResult");
    size_t midle = 10;
    if(out.is_open()){
        for (int i = 0; i < 1000; ++i) {
            out<<"Test № "<< i + 1<<"\n";

            for(int j=0; j<10; ++j)
                out<<data[i][j]<<" ";

            out<<"\n";
            out<<"Sort arra = ";
            out<<"\n";

            std::vector<int> qwe(data[i]);
            std::sort(qwe.begin(), qwe.end());

            for(int j=0; j<10; ++j)
                out<<qwe[j]<<" ";
            out<<"\n";

            size_t med = 5;

            Qselect(data[i], 0, data[i].size()-1);
            int answer1 = data[i][5];
            int answer2  = qwe[5];

            out<<"Answer 1 = " << answer1 << " Answer 2 = "<< answer2<<"\n";
            if(answer1 == answer2)
                out<<"TRUE";
            else {
                out << "FALSE";
                qwert+=std::to_string(i) + " ";
            }


            out<<"\n";
            out<<"\n";
            out<<"\n";
        }
    }
    out.close();
    std::cout<<qwert;

    return 0;
}

