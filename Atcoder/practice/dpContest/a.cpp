// Author : Hardik Upadhyay
// college: SVNIT 
// slogan : Ab to phod dunga
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,b) for(int i=0;i<b;i++)
#define rrep(i,b) for(int i = b - 1; i >= 0; i--)
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
const int INF = 1e9 + 5;
//int dp[MAXN][2]; // dp[i][j] --> min cost to reach stone i with last leap of j+1
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	int h[n];
	for(int i = 0; i < n; i++) cin>>h[i];
	vector<int> dp(n,INF);
	dp[0] = 0;
	for(int i = 0; i < n ; i++){
		for(int ki = 1; ki <= k; ki++){
				int j = i + ki;
				if( i + ki < n)
				dp[j] = min(dp[j],	dp[i] + abs(h[i] - h[j]));
		}
	}
	cout<<dp[n-1]<<nl;
	return 0;

}

