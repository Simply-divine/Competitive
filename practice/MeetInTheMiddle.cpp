#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define SQ(a) (a)*(a)
#define DEBUG printf("hello\n")
#define nl "\n";

using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n;
	int a[n];
	REP(i,0,n-1)cin>>a[i];
	cin>>k;
	time_t start,end;
	time(&start);
	int first = n/2;
	int second = n -first;
       	vector<int> firstf,seconds;	
	int sum=0;
	REP(i,0,(1<<first)-1){
		sum=0;
		REP(j,0,first-1){
			if(i&(1<<j)){
				sum+=a[j];
			}
		}
		firstf.PB(sum);
	}
	sum=0;
	REP(i,0,(1<<second)-1){
		sum=0;
		REP(j,0,second-1){
			if(i&(1<<j)){
				sum+=a[j+n/2];
			}	
		}
		seconds.PB(sum);
	}
	sort(firstf.begin(),firstf.end());
	sort(seconds.begin(),seconds.end());
	int i = 0,j=0;
	for(auto x:firstf){
		auto p = find(seconds.begin(),seconds.end(),k-x);
		if(p!=seconds.end()){	
			cout<<"Yes"<<nl;
			return 0;
		}
	}
	cout<<"No"<<nl;
	time(&end);
	cout<<"Time taken "<<double(end-start)<<setprecision(5)<<nl;
	return 0;
}




