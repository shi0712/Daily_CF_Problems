#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
void solve(){
	int n, k;
	cin >> n >> k;
	cout << (5 + (n - 1) * 6) * k << '\n';
	for(int i = 1; i <= n; i ++){
		int t = 1 + (i - 1) * 6;
		cout << k * t << " " << k * (t + 1) << " " << k * (t + 2) << " " << k * (t + 4) << '\n';
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --){
		solve();
	}
}  
