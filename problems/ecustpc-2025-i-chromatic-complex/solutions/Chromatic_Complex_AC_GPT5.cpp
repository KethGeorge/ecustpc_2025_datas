#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9;

// 0-1 BFS：从(sx,sy)出发计算到所有点的最小代价
// 代价规则：若“起点或终点”为水('1')则该步代价为1；
//           若两端均为陆地('0')则代价为0；岩浆('2')不可走。
static inline int edge_cost(char a, char b) {
    return (a=='1' || b=='1') ? 1 : 0;
}

vector<int> zero_one_bfs(const vector<string>& g, int n, int m, int sx, int sy) {
    auto id = [m](int x, int y){ return x*m + y; };
    vector<int> dist(n*m, INF);
    if (g[sx][sy]=='2') return dist; // 起点不可走，保持INF

    deque<int> dq;
    int s = id(sx, sy);
    dist[s] = 0;
    dq.push_back(s);

    const int dx[4] = {1,-1,0,0};
    const int dy[4] = {0,0,1,-1};

    while(!dq.empty()){
        int u = dq.front(); dq.pop_front();
        int x = u / m, y = u % m;
        if (g[x][y]=='2') continue; // 安全判断

        for(int dir=0; dir<4; ++dir){
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if (g[nx][ny]=='2') continue; // 岩浆不可走
            int w = edge_cost(g[x][y], g[nx][ny]);
            int v = id(nx, ny);
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                if (w==0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
    return dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if(!(cin >> T)) return 0;
    while(T--){
        int n, m, C, K;
        cin >> n >> m >> C >> K;

        int sx, sy; // 1-based in input
        cin >> sx >> sy;
        --sx; --sy;

        vector<string> grid(n);
        for(int i=0;i<n;i++) cin >> grid[i];

        vector<pair<int,int>> gem(C);
        for(int i=0;i<C;i++){
            int x,y; cin >> x >> y;
            --x; --y;
            gem[i] = {x,y};
        }

        // 1) 起点到所有格子的最短代价
        vector<int> distS = zero_one_bfs(grid, n, m, sx, sy);

        // 取到每颗宝石的距离
        vector<int> ds(C, INF);
        for(int i=0;i<C;i++){
            int x = gem[i].first, y = gem[i].second;
            if (x>=0 && x<n && y>=0 && y<m)
                ds[i] = distS[x*m + y];
        }

        // 2) 每颗宝石到其它宝石的最短代价
        vector<vector<int>> d(C, vector<int>(C, INF));
        for(int i=0;i<C;i++){
            auto di = zero_one_bfs(grid, n, m, gem[i].first, gem[i].second);
            for(int j=0;j<C;j++){
                d[i][j] = di[gem[j].first * m + gem[j].second];
            }
        }

        // 如果从起点可达的宝石数小于K，则直接-1（因为不同连通分量之间不可达）
        int reachable = 0;
        for(int i=0;i<C;i++) if (ds[i] < INF) ++reachable;
        if (reachable < K){
            cout << -1 << '\n';
            continue;
        }

        // 3) 状态压缩DP
        int N = 1<<C;
        vector<vector<int>> dp(N, vector<int>(C, INF));

        for(int i=0;i<C;i++){
            if (ds[i] < INF){
                dp[1<<i][i] = min(dp[1<<i][i], ds[i]);
            }
        }

        for(int mask=0; mask<N; ++mask){
            for(int i=0;i<C; ++i){
                int cur = dp[mask][i];
                if (cur >= INF) continue;
                for(int j=0;j<C; ++j){
                    if (mask & (1<<j)) continue;
                    if (d[i][j] >= INF) continue;
                    int nmask = mask | (1<<j);
                    dp[nmask][j] = min(dp[nmask][j], cur + d[i][j]);
                }
            }
        }

        int ans = INF;
        for(int mask=0; mask<N; ++mask){
            if (__builtin_popcount((unsigned)mask) < K) continue;
            for(int i=0;i<C;i++){
                ans = min(ans, dp[mask][i]);
            }
        }

        if (ans>=INF) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}
