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
template<typename tipo>
tipo sumFrom_UpTo(vector<tipo> v, int l, int r){
    tipo total = 0;
    for (int i = l; i < r; i++) {
        total = total + v[i];
    }
    return (total);
}

template<typename tipo>
vector<tipo> reducirBordes(vector<tipo> v, int i, int j, tipo currentSum){
    while(v[i]<0 and i<v.size()){
        currentSum = currentSum - v[i];
        i = i+1;
    }
    while (v[j-1]<0 and j-1 > i){
        currentSum = currentSum - v[j-1];
        j = j - 1;
    }
    vector<tipo> res = {i , j, currentSum};
    return res;
}

template<typename tipo>
vector<tipo> maxSubarray2(vector<tipo> v, int leftIndex, int rightIndex, int currentSum){
    if(leftIndex==rightIndex or rightIndex<leftIndex){
        vector<tipo> res = {leftIndex, rightIndex, 0};
        return (res);
    }
    vector<tipo> vectorAfuera = reducirBordes(v, leftIndex, rightIndex, currentSum);
    leftIndex = vectorAfuera[0];
    rightIndex = vectorAfuera[1];
    currentSum = vectorAfuera[2];
    vector<tipo> adentroIzq = maxSubarray2(v, leftIndex+1, rightIndex, currentSum - v[leftIndex]);
    vector<tipo> adentroDer = maxSubarray2(v, leftIndex, rightIndex-1, currentSum - v[rightIndex-1]);

    if(adentroIzq[2]>=currentSum and adentroIzq[2]>=adentroDer[2]){
        leftIndex = adentroIzq[0];
        rightIndex = adentroIzq[1];
        currentSum = adentroIzq[2];
    }
    else if (adentroDer[2]>=currentSum and adentroDer[2]>=adentroIzq[2]){
        leftIndex = adentroDer[0];
        rightIndex = adentroDer[1];
        currentSum = adentroDer[2];
    }
    vector<tipo> res = {leftIndex, rightIndex, currentSum};
    return (res);
}
template<typename tipo>
vector<tipo> maxSubarray3(vector<tipo> v){
    tipo bestSum = 0;
    tipo currentSum = 0;
    int bestStart = 0;
    int bestEnd = 0;
    int currentStart =  0;
    for (int currentEnd=0; currentEnd<v.size(); currentEnd++){
        if(currentSum>=0){
            currentSum = currentSum + v[currentEnd];
        }
        else{
            currentStart = currentEnd;
            currentSum = v[currentEnd];
        }
        if(currentSum>bestSum){
            bestStart = currentStart;
            bestSum = currentSum;
            bestEnd = currentEnd;
        }
    }
    vector<tipo> res = {bestStart, bestEnd, bestSum};
    return (res);
}

template<typename tipo>
vector<tipo> maxSubarray(vector<tipo> v){
    vector<tipo> res = maxSubarray2(v, 0, v.size(), sumFrom_UpTo(v, 0, v.size()));
    return (res);
}

int main() {
    vector<int> v1 = {-21,-32, 12, -1, 40, -1, 3, 2, -10, 500, -20, 21};
    visualizarVector(v1);
    // std::cout << sumFrom_UpTo(v1, 0, v1.size()) << std::endl;
    vector<int> res = maxSubarray3(v1);
    //vector<int> res = reducirBordes(v1, 0, v1.size(), sumFrom_UpTo(v1, 0, v1.size()) );
    //vector<int> res2 = reducirBordes(v1, res[0], res[1], res[2]);
    visualizarVector(res);
    return 0;
}
