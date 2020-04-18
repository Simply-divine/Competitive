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
ll mod=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout<<(((1LL<<60)%mod)*23)%mod<<nl;
	cout<<((1LL<<60)*23)%mod<<nl;
	int temp = 1;
	rep(i,0,59)temp*=2,temp%=mod;
	cout<<temp<<nl;
	return 0;
}




