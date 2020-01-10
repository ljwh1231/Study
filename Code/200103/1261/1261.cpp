#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

int n, m;
int a[105][105];
int dist[105][105];
bool check[105][105];

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

void dijk(){
    dist[0][0]=0;
    check[0][0]=true;

    priority_queue <pair<pair<int,int>, int> > pq; // ((val, x), y)
    pq.push(make_pair(make_pair(0,0),0)); // (0,0,0)
    
    while(!pq.empty()){
        int cnt = -pq.top().first.first;
        int x = pq.top().first.second;
        int y = pq.top().second;
        pq.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ncnt = cnt + a[nx][ny];

            if(0<=nx && nx<n && 0<=ny && ny<m){
                if(check[nx][ny]==false){
                    check[nx][ny]=true;
                    dist[nx][ny]=ncnt;
                    pq.push(make_pair(make_pair(-ncnt,nx), ny));
                }
            }
        }
    }
}

int main(){
    cin >> m >> n;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            a[i][j] = s[j]-'0';
            dist[i][j]=INF;
        }
    }

    dijk(); // (0,0) start

    cout << dist[n-1][m-1]; // (n,m) end

    return 0;
}