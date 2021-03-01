#include<iostream>
#include <cmath>
#include<climits>
#include <queue>

using namespace std;
const int INF = INT_MAX/2;

typedef struct Node {
    int capacity, cost;
} Node;

Node newNode(int capacity, int cost) {
    Node n;
    n.capacity=capacity;
    n.cost=cost;
    return n;
}

struct match{
    int winner;
    int loser;
    int cost=0;
};

struct edge{
    int to;
    int capacity=0;
    int cost=0;
};


int wins[205];
int parents[205];
int dist[205];
bool visited[205];



void shortest_paths(vector<vector<edge>>& G,int s, int V){
    for(int i=0;i<V;i++){
        parents[i]=-1;
        dist[i]=INF;
        visited[i]=false;
    }
    dist[s]=0;

    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int u=q.front();
        q.pop();
        visited[u]=false;
        for(edge edge1:G[u]){
            if(edge1.capacity>0 && dist[edge1.to]>dist[u]+edge1.cost){
                dist[edge1.to]=dist[u]+edge1.cost;
                parents[edge1.to]=u;
                if(visited[edge1.to]==false){
                    visited[edge1.to]=true;
                    q.push(edge1.to);
                }
            }
        }
    }
}

edge& findedge(vector<edge>& Gpart,int to){
    for (edge& edge1 : Gpart) {
        if (edge1.to == to) {
            return edge1;
        }
    }
}
bool mincost(vector<vector<edge>>& G,int s, int t, int V, int F,int k,int money,int C){
    int flow=0;
    int cost=0;
    while(flow<F){
        shortest_paths(G,s,V);
        if(dist[t]==INF){
            break;
        }
        int f=F-flow;
        int c=t;
        while(c!=s){
            for(edge edge1:G[parents[c]]){
                if(edge1.to==c){
                    f=min(f,edge1.capacity);
                }
            }
            c=parents[c];
        }

        flow+=f;
        cost+=f*dist[t];
        c=t;
        while(c!=s){
            findedge(G[c],parents[c]).capacity+=f;
            findedge(G[parents[c]],c).capacity-=f;
            c=parents[c];
        }
    }
    if(flow<F){
        return false;
    }
    for(edge edge1:G[V-1]){
        if(edge1.to==1){
            if(edge1.capacity<k){
                return false;
            }
        }
    }
    cost-=C*(F-k);
    if(cost<=money){
        return true;
    }
    return false;
}

int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int B,n;
        cin >> B;
        cin >> n;
        if(n>1){
            bool p2=true;
            bool p3=false;
            int F=n*(n-1)/2;
            int C=1;
            int V=n+2;
            double d = 1.0 * (n-1)/2;
            int k=ceil(d);
            for(int j=0;j<V;j++){
                wins[j]=0;
            }
            vector<match> matches{F};
            for(int h=0;h<F;h++){
                int a,b,c,d;
                cin>>a>>b>>c>>d;
                C+=d;
                wins[c+1]+=1;
                match match1;
                if(a==c){
                    match1.winner=a+1;
                    match1.loser=b+1;
                }
                else{
                    match1.winner=b+1;
                    match1.loser=a+1;
                }
                match1.cost=d;
                matches[h]=match1;
            }
            int maximum=wins[1];
            for(int r=2;r<n+1;r++){
                if (wins[r]>maximum){
                    p3=true;
                    break;
                }
            }
            k=max(k,wins[1]+1);
            while(k<n && p2 && p3){
                vector<vector<edge>> G(V);
                for(int i=1;i<n+1;i++){
                    if(wins[i]>0){
                        edge edge2;
                        edge2.to=i;
                        edge2.capacity=wins[i];
                        G[0].push_back(edge2);
                        edge edge3;
                        edge3.to=0;
                        G[i].push_back(edge3);
                    }
                }

                for(match match1:matches){
                    edge edge3;
                    edge3.to=match1.loser;
                    edge3.capacity=1;
                    edge3.cost=match1.cost;
                    G[match1.winner].push_back(edge3);
                    edge edge4;
                    edge4.to=match1.winner;
                    edge4.cost=-match1.cost;
                    G[match1.loser].push_back(edge4);
                }
                edge edge5;
                edge5.capacity=k;
                edge5.to=V-1;
                G[1].push_back(edge5);
                edge edge6;
                edge6.capacity=k;
                edge6.cost=C;
                edge6.to=V-1;
                for (int o = 2 ; o < 1 + n; o++) {
                    G[o].push_back(edge6);
                }
                edge edge8;
                edge8.to=1;
                G[V-1].push_back(edge8);
                for(int i=2;i<n+1;i++){
                    edge edge7;
                    edge7.to=i;
                    edge7.cost=-C;
                    G[V-1].push_back(edge7);
                }



                if(mincost(G,0,V-1,V,F,k,B,C)){
                    cout <<"TAK"<<endl;
                    p2=false;
                }
                k+=1;
            }
            if(!p3) cout<<"TAK"<< endl;
            else if(p2) cout<<"NIE"<<endl;
        }
        else{
            cout<<"TAK"<<endl;
        }
    }
}
