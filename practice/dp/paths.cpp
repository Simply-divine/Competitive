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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int a[n+1][n+1];
	REP(i,1,n)REP(j,1,n)cin>>a[i][j];
	int sum[n+1][n+1];
	sum[0][0] = 0;
	REP(i,0,n)sum[i][0]=sum[0][i]=0;
	REP(i,1,n){
		REP(j,1,n){
			sum[i][j] = max(sum[i-1][j],sum[i][j-1])+a[i][j];
			//cout<<sum[i][j]<<nl;
		}
	}
	cout<<sum[n][n];
	return 0;
}




