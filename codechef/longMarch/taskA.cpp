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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,n,m;
	cin>>t;
	while(t-->0){
		cin>>n;
		cin>>m;
		int cnt[m]={0};
		int ind[n],sum[n];
		bool vis[m]  = {false};
		rep(i,0,n-1){
			cin>>ind[i];
			vis[ind[i] - 1] = true;
		}
		rep(i,0,n-1){
			cin>>sum[i];
		}
		int mn = 100001;
		rep(i,0,n-1){
			cnt[ind[i] - 1] += sum[i];
		}
		rep(i,0,m-1){
			if(vis[i] == true){
				mn = min(mn,cnt[i]);	
			}
		}
		if(mn!=100001){
			cout<<mn<<nl;
		}
		else{
			cout<<"error"<<nl;
		}
	}
	return 0;
}




