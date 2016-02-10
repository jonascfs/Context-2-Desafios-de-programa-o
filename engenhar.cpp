#include <stdio.h>
#include <string.h>
using namespace std;

int fnet[200][200];
int pred[305];
int q[305];
int marc[305];
int g[305][305];

int n,m,k,l,c,j=1,t,nmarcados;
void dfs(int n,int v){
    int j;
    marc[v]=1;
    nmarcados++;
    //if( nmarcados == n ) return;
    if( pred[t]!=-1) return;
    for(j=0;j < n;j++){
        if(g[v][j] > 0 && marc[j]==0){
            pred[j]=v;
            dfs(n,j);
        }
    }

}

int fff(int n,int s, int t){
    int cont=0;
    while (1){
        for (int i=0;i<n;i++){
            pred[i]=-1;
            marc[i]=0;
        }
        nmarcados=0;
        dfs(n,0);
        if (pred[t]==-1) break;
        for (int i=t;pred[i]!=-1;i=pred[i]){
            g[pred[i]][i]--;
            g[i][pred[i]]++;
        }
        cont++;
    }
    return cont;
}

int main(){
    int c,p,aux;
    scanf("%d",&c);
    for (int k = 0; k < c; ++k) {
        nmarcados = 0;
        memset(g,0,sizeof(g));
        memset(marc,0,sizeof(marc));
        scanf("%d",&n);
        for (int i = 1; i <=n; ++i) {
            scanf("%d",&p);
            for (int j = 1; j <=p; ++j) {
                scanf("%d",&aux);
                if(aux!=i)
                    g[i][aux+n] = 1;
            }
        }
        for (int i = 1; i <=n; ++i) {
            g[0][i] = 1;
            g[i+n][2*n+1] = 1;
        }

        fff(n+n+2,0,n+n+1);
        printf("Instancia %d\n",k+1);

        if(fff(n+n+2,0,n+n+1) == n)
        if(flag)
            printf("%s\n\n","pair programming");
        else
            printf("%s\n\n","extreme programming");
        //printf("%d\n",fff(n+n+2,0,n+n+1));
    }
}