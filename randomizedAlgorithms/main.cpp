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
void swap(vector<tipo>&v, int i, int j){
    tipo temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

template<typename tipo>
void permuteWithAll(vector<tipo> &v){
    for (int i = 0; i < v.size(); i++) {
        swap(v, i, (rand() % v.size()));
    }
}

template<typename tipo>
set<tipo> randomSample2(vector<tipo> v1, int indexLimit, int sampleSize){
    if (sampleSize==0){
        set<tipo> s = {};
        return(s);
    }
    else{
       set<tipo> s = randomSample2(v1, indexLimit-1, sampleSize-1);
       tipo elem = v1[rand()%v1.size()];
       if(s.count(elem)==1){
           s.insert(v1[indexLimit]);
       }
       else{
           s.insert(elem);
       }
        return s;
    }
}
template<typename tipo>
set<tipo> randomSample(vector<tipo> v1,  int sampleSize){
    return randomSample2(v1, v1.size()-1, sampleSize);
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<float> v1 = {1,2,3,4,5,6,7,8,9,10};
    visualizarVector(v1);
    permuteWithAll(v1);
    visualizarVector(v1);

    set<float> s = randomSample(v1, 4);

    return 0;
}
