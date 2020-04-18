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
	// better approach for constant length windows.
	int n,k;
	cin>>n>>k;
	int a[n];
	REP(i,0,n-1)cin>>a[i];
	int maxSum= 0;
	//calculate the first window
	REP(i,0,k-1)
		maxSum+=a[i];
	int windowSum = maxSum;
	REP(i,k,n-1){
		windowSum +=a[i]-a[i-k];
		maxSum = max(windowSum,maxSum);
	}
	cout<<maxSum<<nl;
	return 0;
}




