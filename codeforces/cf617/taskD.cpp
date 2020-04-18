#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
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
	int n,a,b,k;
	cin>>n>>a>>b>>k;
	int mon[n];
	rep(i,0,n-1) cin>>mon[i];
	int cnt = 0;
	rep(i,0,n-1){
		int rem = mon[i]%(a+b);
		if(rem>0 && rem<=a)cnt++;
		else {
			if(rem == 0){
				k-=(b/(2*a)+1);
				if(k>=0){
					cnt++;
				}
			}
			else{
				k -= rem/(2*a);
				if(k>=0){
					cnt++;
				}
			}
		}
	}
	cout<<cnt<<nl;
	return 0;
}




