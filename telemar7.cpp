//
// Created by jc on 25/01/16.
//
#include <stdio.h>
#include <queue>
using namespace std;
int linhas[1000001];
typedef struct func{
    int id;
    int v;
    int cont;
    func(int id):id(id){
        v = 0;
        cont = 0;
    }
    func(){}
    bool operator <(const func& f)const{
        if(f.v != v)
            return v > f.v;
        else
            return id > f.id;
    }
}Func;

int main(){
    priority_queue <Func> q;
    Func resp[1001];
    int n,l;
    scanf("%d %d",&n,&l);
    for (int j = 0; j <n ; ++j) {
        q.push(Func(j+1));
    }
    for (int i = 0; i < l; ++i) {
        scanf("%d",&linhas[i]);
    }

    for (int k = 0; k <l ; ++k) {
        Func f = q.top();
        q.pop();
        f.v+=linhas[k];
        f.cont++;
        q.push(f);
    }

    while(!q.empty()){
        Func f = q.top();
        q.pop();
        resp[f.id -1] = f;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n",resp[i].id,resp[i].cont);
    }

}
