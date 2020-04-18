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
	cin>>n>>k;
	int a[n];
	REP(i,0,n-1)cin>>a[i];
	int maxSum = 0;
	//brute force
	// move from 0 to n-k
	// add 0 to k-1 (you want exactly k elements sum)
	// find its maximum
	REP(i,0,n-k){
		int sum = 0;
		REP(j,0,k-1){
			sum+=a[j+i];		
		}
		maxSum = max(sum,maxSum);
	}
	cout<<maxSum<<nl;
	return 0;
}




