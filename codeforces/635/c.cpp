// Author : Hardik Upadhyay
// college: SVNIT 
// slogan : Ab to phod dunga
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,a,b) for(int i = a ; i >= b; i--)
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define sq(a) (a)*(a)
#define nl "\n"
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,
//tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int MAXN = 100005;
ll mod=1000000007;
bool vis[2*MAXN] = {false};
vector<vi> adj(2*MAXN);
int h[2*MAXN] = {0},s[2*MAXN] = {0};
void dfs(int src,int level){
	vis[src] = true;
	h[src] = level;
	s[src] = 1;
	for(auto& x: adj[src]){
		if(!vis[x]){
			dfs(x,level + 1);
			s[src]+=s[x];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	// vector<vi> adj(n);
	// priority_queue<int> q;
	// vector<int> answers(n);
	// n--;
	for(int i = 0; i < n- 1; i++){
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0,1);
	int sum[n];
	for(int i = 0; i < n; i++){
		sum[i] = h[i] - s[i];
	}
	sort(sum, sum + n);

	reverse(sum,sum + n);
	ll tot = 0;
	for(int i = 0; i < k; i++){
		tot += sum[i];
	}
	cout<<tot;
	return 0;
}
