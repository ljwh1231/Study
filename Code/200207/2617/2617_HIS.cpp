#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector <int> v[101];
vector <int> r[101];

bool check[101];
bool check_rev[101];
int cnt, cnt_rev;

void dfs(int x){
    check[x]=true;
    
    for(int i=0; i<v[x].size(); i++){
        int nx = v[x][i];
        if(!check[nx]){
            cnt++;
            dfs(nx);
        }
    }
}

void dfs_rev(int x){
    check_rev[x]=true;

    for(int i=0; i<r[x].size(); i++){
        int nx = r[x][i];
        if(!check_rev[nx]){
            cnt_rev++;
            dfs_rev(nx);
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;

        v[a].push_back(b);
        r[b].push_back(a);
    }
    
    int mid = (n+1)/2;
    int ans=0;

    for(int i=1; i<=n; i++){
        // init
        cnt=0;
        cnt_rev=0;
        memset(check, 0, sizeof(check));
        memset(check_rev, 0, sizeof(check_rev));

        dfs(i);
        dfs_rev(i);

        if(mid <= cnt || mid <= cnt_rev){
            ans++;
        }
    }

    cout << ans;
    return 0;
}