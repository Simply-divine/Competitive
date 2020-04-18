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
float a[100001];
float st[100001][25];
float st1[100001][25];
int K = 25;
void precalcMin(int n){
	REP(i,0,n-1){
		st[i][0] = a[i]; 
	}
	for(int j = 1; j <=K;j++){
		for(int i = 0; i+(1<<j) <= n;i++){

			st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}
void precalcMax(int n){
	REP(i,0,n-1){
		st1[i][0] = a[i];	
	}
	for(int j = 1; j<=K;j++){
		for(int i = 0; i +(1<<j)<=n;i++){
			st1[i][j] = max(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
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
	int q;
	cin>>q;
	precalcMin(n);
	precalcMax(n);
	while(q-->0){
		int l,r;
		cin>>l>>r;
		int len = r - l + 1;
		int i;
		for( i = 0; (1<<i)<=len;i++);
		i--;
		float maxQuery = max(st1[l][i],st1[r-(1<<i)+1][i]); 
		float minQuery = min(st[l][i],st[r-(1<<i)+1][i]);
		int l1 = l - 0;
		int k1 = 1,k2 = 1;
		for( k1 = 0; (1<<k1)<=l1;k1++);
		k1--;
		int l2 = (n-1) - (r+1) + 1 ;	
		for( k2 = 0; (1<<k2)<=l2;k2++);
		k2--;	
		float maxRem = 0;
		if(l > 0)
			maxRem = max(st1[0][k1],st1[ l - (1<<k1)][k1]);
		if( r < n-1)
			maxRem = max(maxRem,max(st1[r+1][k2],st1[ n - (1<<k2)][k2]));
		float ans;
		ans= max( maxRem + minQuery , minQuery + (maxQuery - minQuery)/2);		
		printf("%.1f\n",ans);
		
	}
	return 0;
}




