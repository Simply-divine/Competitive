#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<queue>
#include<list>
#include<sstream>
#include<algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define SQ(a) (a)*(a)
#define nl "\n"
#define DEBUG printf("hello\n")
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main()
{
	
	/*cout<<"indexed set"<<nl;
	indexed_set s;
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(-1121);
	auto i = s.find_by_order(0);
	cout<<*i<<nl;
	auto j = s.order_of_key(3);
	cout<<j<<nl;
	*/
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int m;
	//vi a,b;
	cin>>n>>m;
	int a[n],b[n];
	REP(i,0,n-1){
		int x;
		cin>>x;
		a[i] = (x);
	}
	REP(i,0,m-1){
		int x;
		cin>>x;
		b[i] = x;
	}
	sort(a,a+n);
	sort(b,b+m);
	int i = 0;
	int j = 0;
	vi c;
	while(i<n&&j<m){
	//	DEBUG;
		if(a[i]<b[j])i++;
		else if(a[i]>b[j])j++;
		else{
			DEBUG;
			c.PB(a[i]);
			i++;
			j++;		
		}
	}
	for(auto x:c){
		cout<<x<<nl;
	}
	return 0;
}



