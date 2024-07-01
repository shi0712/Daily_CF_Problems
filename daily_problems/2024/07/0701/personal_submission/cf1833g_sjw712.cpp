#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
const int N = 2e5 + 10, M = N * 2;
int n, deep, dep[N], sz[N], pa[N];
vector<pii> g[N];
map<int, vector<int>> mp;
bool used[N];
void dfs(int u, int fa){
	pa[u] = fa;
	mp[dep[u]].push_back(u);
	deep = max(deep, dep[u]);
	sz[u] = 1;
	for(auto i: g[u]){
		int j = i.x;
		if(j == fa) continue;
		dep[j] = dep[u] + 1;
		dfs(j, u);
	}
}
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i ++) g[i].clear();
	memset(used, 0, sizeof used);
	mp.clear();
	for(int i = 1; i < n; i ++){
		int a, b;
		cin >> a >> b;
		g[a].push_back({b, i});
		g[b].push_back({a, i});
	}
	dep[1] = 0;
	dfs(1, 0);
	vector<int> ans;
	while(deep > 0){
		deep --;
		for(auto i: mp[deep]){
			int cnt = 0, id;
			for(auto j: g[i]){
				if(j.x == pa[i]){
					id = j.y;
					continue;
				}
				if(!used[j.x]) cnt += sz[j.x];
			}
			if(cnt > 2) return cout << -1 << '\n', void();
			if(cnt == 2){
				if(i == 1) continue;
				else{
					ans.push_back(id);
					used[i] = true;
				}
			}
			if(i == 1 && cnt != 2) return cout << -1 << '\n', void();
			sz[i] += cnt;
		}
	}
	cout << ans.size() << '\n';
	for(int i : ans) cout << i << " ";
	cout << '\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --){
		solve();
	}
}  
