// Author : Hardik Upadhyay
// college: SVNIT 
// slogan : Ab to phod dunga
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define SQ(a) (a)*(a)
#define nl "\n"
#define INF std::numeric_limits<int>::max()
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int MAXN = 100005;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int t1 = 0; t1 < t; t1++){
		int n;
		cin>>n;
		int s[n],e[n];
		rep(i,0,n-1){
			cin>>s[i];
			cin>>e[i];
		}
		map<int,int> mp;
		char ans[n];
		bool impossible = false;
		for(int i = 0; i < n; i++){
			for(int j = s[i] ; j < e[i]; j++){
				 mp[j]++;
			 		if(mp[j]>2){
						impossible = true;
					}	 
			}
		}
		if(impossible) {
			cout<<"Case #"<<(t1+1)<<": "<<"IMPOSSIBLE"<<nl;
		}	
		else{
			vector<tuple<int,int,int>> v;
			for(int i = 0; i < n; i++){
						v.PB(make_tuple(s[i],e[i],i));
			}
			sort(v.begin(),v.end());
			int lastC = -1;
			for(int i = 0; i < n; i++){
				if(get<0>(v[i]) < lastC){
					ans[get<2>(v[i])] = 'J';
				}
				else{
					ans[get<2>(v[i])] = 'C';
					if( lastC < get<1>(v[i])) lastC = get<1>(v[i]);
				}
			}
			cout<<"Case #"<<(t1+1)<<": ";
			for(int i =0; i < n; i++){
					cout<<ans[i];
			}
			cout<<nl;
		}
	}
	return 0;
}

