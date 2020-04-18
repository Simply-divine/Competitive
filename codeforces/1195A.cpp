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
	int n,k;
	cin>>n;
	cin>>k;
	int cnt[k+1]={0};
	REP(i,0,n-1){
		int temp;
		cin>>temp;
		cnt[temp]++;
	}
	int ans=0;
	REP(i,1,k){
		if(cnt[i]%2==0){
			ans+=cnt[i]/2;
		}
		else ans+=cnt[i]/2+1;
	}
	if(n%2==0){
		ans-=n/2;
	}	
	else ans-=(n/2+1);
	if(ans<=0){
		cout<<n<<nl;
	}
	else
		cout<<(n-ans)<<nl;
	return 0;
}




