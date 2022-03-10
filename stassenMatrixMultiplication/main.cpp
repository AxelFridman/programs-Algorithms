#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

template<typename tipo>
vector<vector<tipo>> generar4partes(vector<vector<tipo>> M, int indX, int indY){
    vector<vector<tipo>> m11 = {{}};
    vector<vector<tipo>> m12 = {{}};
    vector<vector<tipo>> m21 = {{}};
    vector<vector<tipo>> m22 = {{}};

    for (int i = 0; i < indY; ++i) {
        vector<tipo> v = {};
        for (int j = 0; j < indX; ++j) {
            v.push_back(M[i][j]);
        }
        m11.push_back(v);
    }
    return m11;
}

template<typename tipo>
vector<vector<tipo>> strassenMultiplication(vector<vector<tipo>> A, vector<vector<tipo>> B, int indX, int indY){
    indX = indX/2;
    indY = indY/2;
    //generar4partes();
    //generar10submatricez()
}

#include <algorithm>
using namespace std;




int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<vector<int>> m={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<vector<int>> m11 = generar4partes(m, 2, 2);
    return 0;
}
