//
// Created by jc on 15/01/16.
//
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;

typedef struct adj{
    int id,w;
    adj(){
    }
    adj(int id,int w):id(id),w(w){
    }
    bool operator<(const adj& v)const{
        return w<v.w;
    }
    bool operator>(const adj& v)const{
        return w>v.w;
    }
    bool operator==(const adj& v)const{
        return w==v.w;
    }

}Adj;
int d[110];
Adj g[110][110];
int dist[110];
int dijkstra(int s,int t,int n){
    priority_queue<Adj> q;
    for (int i = 1; i <=n; ++i) {
        dist[i] = ~(1<<31);
    }
    dist[s] = 0;
    q.push(Adj(s,dist[0]));
    while (!q.empty()){
        Adj u = q.top();
        q.pop();
        for (int i = 0; i < d[u.id]; ++i) {
            Adj v = g[u.id][i];
            if(dist[u.id]+v.w < dist[v.id]){
                dist[v.id] =dist[u.id]+v.w;
                q.push(Adj(v.id,dist[v.id]));
            }
        }
    }
    return dist[t] == ~(1<<31)?-1:dist[t];
}

int main(){
    int n,m,u,v,t;
    while(1){
        scanf("%d %d",&n,&m);
        if(n == 0)
            break;
        memset(d,0, sizeof(d));
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d",&u,&v,&t);
            g[u][d[u]].id = v;
            g[u][d[u]++].w  = t;
        }
        scanf("%d %d",&u,&v);
        printf("%d\n",dijkstra(u,v,n));
    }
}
