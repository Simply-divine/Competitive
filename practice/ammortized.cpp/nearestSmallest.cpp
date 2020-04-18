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
	REP(i,0,n-1)cin>>a[i];
	stack<int> st;
	st.push(a[0]);
	int f = 0;
	int nearest[n];
	// to find nearest smallest element we first add the elements in the increasing order in the stack and if we come to value which is 
	//less than the top of the stack, we remove the element from the top untill the situation satisfies.The element on the top will
	// then be the smaller number nearest to current number and preceding it.
	REP(i,1,n-1){
		while(!st.empty()&&a[i]<=st.top()){
			st.pop();
		}
		if(st.empty()){
			nearest[i] = -1;
			st.push(a[i]);	
		}
		else{
			nearest[i] = st.top();
			st.push(a[i]);
		}
	}
	REP(i,1,n-1){
		cout<<nearest[i]<<nl;
	}
	return 0;
}




