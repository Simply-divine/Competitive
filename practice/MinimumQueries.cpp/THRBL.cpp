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
int K = 25;
int a[50001];
int st[50001][25];
void precalc(int n){
	for(int i = 0; i < n-1; i++){
		st[i][0] = a[i];
	}
	for(int j = 1; j <= K;j++)	
		for(int i = 0; i+(1<<j) <= n; i++){
			st[i][j] = max(st[i][j-1],st[i +(1<<(j-1))][j-1]);
		}

}	
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	REP(i,0,n-1)cin>>a[i];
	int cnt = 0;
	precalc(n);
	while(m-->0){
		int l,r;
		cin>> l>>r;
		l--;
		r--;
		if( l == r){
			cnt++;
			continue;
		}

		int len = r - l-1;
		int i;	
		for( i = 0; (1<<i)<=len;i++);
		i--;
		int ans = max(st[l][i],st[r - (1<<i)][i]);
		if(ans<=a[l]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}




