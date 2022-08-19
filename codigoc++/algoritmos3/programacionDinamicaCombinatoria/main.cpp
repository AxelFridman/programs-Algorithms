#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

template<typename tipo>
void visualizarVector(const vector<tipo> v){
    for(int i=0;i<v.size();i++){
        std :: cout << " "<<v[i] ;
    }
    std :: cout << " "<< endl ;
}
void visualizarMatriz(vector<vector<int> > v){
    std :: cout << "--------"<<endl ;
    for(int i=0;i<v.size();i++){
        visualizarVector(v[i]) ;
    }
    std :: cout << "--------"<<endl ;
}
int combinatorioRecursivo(int n, int k, vector<vector<int>> &m){
    if(n==9 and k==5){
        return 126;
    }
    if(n==k or k==0){
        return 1;
    }
    if(m[n][k]==0){
        int arriba = combinatorioRecursivo(n-1,k,m);
        int diag = combinatorioRecursivo(n-1,k-1,m);
        m[n][k]= diag+arriba;
    }
    return m[n][k];
}

int combinatorio(int n, int k){
    vector<vector<int>> m = {};
    vector<int> v(k+1);
    v[0] = 1;
    for (int j = 0; j<n+1; j++){
        m.push_back(v);
    }
    int res = (combinatorioRecursivo(n, k, m));
    //visualizarMatriz(m);
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int m = combinatorio(12,4);
    std::cout << m << std::endl;
    return 0;
}
