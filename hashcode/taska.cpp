#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define MAXN 100005
#define MP make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define SQ(a) (a)*(a)
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
	int s, n;
	cin>>s>>n;
	int a[n+1];
	int dp[s+1];
	rep(i,1,n){
		cin>>a[i];
	}
	ll max = 0;
	dp[0] = 1;
	int best[s+1];
	for(int i = 0; i <=s;i++){
		for(int j = 1; j <=n ; j++){
			if(dp[i] == 1&& i+a[j]<s){
				dp[i+a[j]] = 1;
				best[a[j]+i] = j;
			}
		}	
	}
	int ans = -1;
	for(int i = s; i>=0;i--){
		if(dp[i] == 1){
			ans = i;
			break;
		}
	}
	cout<<ans<<nl;
	while( ans > 0){
		cout<<a[best[ans]]<<" ";
		ans -=a[best[ans]]; 
	}

	return 0;
}




