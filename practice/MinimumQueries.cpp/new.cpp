#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define SQ(a) (a)*(a)
#define DEBUG printf("hello\n")
#define nl "\n"
#define INF std::numeric_limits<int>::max()
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
	tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
ll mod=1000000009;
int a[10000];
int st[10000][25];
int K = 25;

void precalc(int n){
	REP(i, 0, n-1){
		st[i][0] = a[i];
	}
	REP( j, 1, K){
		for(int i = 0; i +(1<<j)<=n;i++){
			st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		} 
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	REP(i,0,n-1)cin>>a[i];
	int t;
	cin>>t;
	precalc(n);
	while(t-->0){
		int l,r;
		cin>>l>>r;
		int len = (r - l + 1);
		int k = 0;
		//cout<<len;
		for(k = 0;(1<<k)<=len;k++);
		k--;
		int ans = min(st[l][k],st[r - (1<<k) + 1][k]);
		cout<<ans<<nl;
	}
	return 0;
}




