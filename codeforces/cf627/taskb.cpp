#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
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
const int MAXN = 100005;
ll mod=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		int a[n];
		int mark[5001];
		rep(i,0,5000)mark[i] = -1;
		bool f = false;
		int cnt[5001] = {0};
		rep(i,0,n-1){
			cin>>a[i];
			cnt[a[i]]++;
		}
		if ( n < 3){
			cout<<"NO"<<nl;
			continue;
		}
		rep(i,0,n-1){
			if (mark[a[i]]!=-1){
				if ( i - mark[a[i]] >= 2){
					f = true;
					break;			
				}else if ( cnt[a[i]] > 2){
					f = true;
					break;
				}
			} 
			mark[a[i]] = i;
		}
		if( f ){
			cout<<"YES"<<nl;
		}
		else cout<<"NO"<<nl;
	}


	return 0;
}




