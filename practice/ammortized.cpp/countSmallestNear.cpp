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
	int n;
	cin>>n;
	int a[n];
	set<int> ts;
	//there are two variations in these type of problems. One is to find closest smallest on the left side. and another one is to find
	//smallest closest element in the entire array itself. This code solves the latter.
	REP(i,0,n-1){
		cin>>a[i];
		ts.insert(a[i]);
	}
	REP(i,0,n-1){
		auto smaller = ts.lower_bound(a[i]);
		if(smaller == ts.begin())
			cout<<-1<<endl;
		else{
			cout<<*(--smaller)<<nl;
		}
	}

	return 0;
}




