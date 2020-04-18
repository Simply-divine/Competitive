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
ll mod = 1000000009;
int value[1000];
int n;
vi coins;
void solve(int k){
	value[0]=1;
	for(int x =1;x<=k;x++)value[x] = 0;
	for(int x = 1; x<=k;x++){
		for(int c:coins){
			if(x-c>=0){
				value[x]+=value[x-c];
				value[x]%=mod;
			}
		}
	}
}
	
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	REP(i,0,n-1){
		int temp;
		cin>>temp;
		coins.PB(temp);
	}
	int k;
	cin>>k;
	solve(k);
	cout<<value[k]<<nl;	
	return 0;
}




