#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define SQ(a) (a)*(a)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
int main()
{
	ll a,b,n,k;
	vector<pair<ll,ll>> vec;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&a,&b);
		vec.PB(MP(a,b));
	}
	sort(vec.begin(),vec.end());
	REP(i,0,n){
		k-=vec[i].second;
		if(k<=0){
		printf("%lld\n",vec[i].first);
		break;
		}
	}
	 return 0;
}



