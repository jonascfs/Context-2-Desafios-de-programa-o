//
// Created by jc on 15/01/16.
//
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <stdio.h>

using namespace std;

typedef struct edge{

    edge(int i,int j, int w):i(i),j(j),w(w){}
    edge(){}
    int i,j,w;

    bool operator<(const edge& v)const{
        return w>v.w;
    }
    bool operator>(const edge& v)const{
        return w<v.w;
    }
    bool operator==(const edge& v)const{
        return w==v.w;
    }
}Edge;
vector<int>pset;
Edge g[10100];
void initSet(int _size){
    pset.resize(_size);
    for (int i = 0; i < _size; ++i) {
        pset[i] = i;
    }
}

int findSet(int i){
    return pset[i] == i? i : (pset[i] = findSet(pset[i]));
}
void unionSet(int i, int j){
    pset[findSet(i)] = findSet(j);
}
bool isSameSet(int i,int j){
    return findSet(i) == findSet(j);
}

int kruskal(int n,int m){
    initSet(n);
    priority_queue<Edge> q;
    int cont = 0;
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        q.push(g[i]);
    }
    while (!q.empty()){
        Edge e = q.top();
        q.pop();
        if(!isSameSet(e.i,e.j)){
            cont++;
            sum+=e.w;
            unionSet(e.i,e.j);
        }
        if(cont == n+1)
            return sum;
    }
    return sum;
}

int main(){
    int n,m,p,q,u;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d",&g[i].i,&g[i].j,&g[i].w);
    }
    printf("%d",kruskal(n,m));
    
}