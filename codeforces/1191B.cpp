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
	string a,b,c;
	cin>>a>>b>>c;
	if(a[1]==b[1]&&b[1]==c[1]){
		if(a[0]==b[0]&&a[0]==c[0]){
			cout<<"0"<<nl;
			return 0;
		}
		if(a[0]==b[0]||a[0]==c[0]||b[0]==c[0]){
			cout<<"1"<<nl;
			return 0;
		}
		vi temp;
		temp.PB(a[0]);
		temp.PB(b[0]);
		temp.PB(c[0]);
		sort(temp.begin(),temp.end());
		if(temp[1]-temp[0]==1&&temp[2]-temp[1]==1){
			cout<<"0"<<nl;
			return 0;
		}
		else if(temp[1]-temp[0]==1||temp[2]-temp[1]==1||temp[1]-temp[0]==2||temp[2]-temp[1]==2||temp[2]-temp[0]==2){
			cout<<"1"<<nl;
			return 0;
		}
		else{
			cout<<"2"<<nl;
			return 0;
		}
	}
	else{
		if(a[1]==b[1]||b[1]==c[1]||a[1]==c[1]){
			if(a[1]==b[1]){
				if(abs(a[0]-b[0])<=2){
					cout<<"1"<<nl;
					return 0;


				}
				else{
					cout<<"2"<<nl;
					return 0;	
				}
			}
			if(b[1]==c[1]){
				if(abs(b[0]-c[0])<=2){
					cout<<"1"<<nl;
					return 0;
				}
				else{
					cout<<"2"<<nl;
					return 0;
				}
			}
			if(a[1]==c[1]){
				if(abs(a[0]-c[0])<=2){
					cout<<"1"<<nl;
					return 0;
				}
				else{
					cout<<"2"<<nl;
					return 0;
				}
			}

		}
		else{
			cout<<"2"<<nl;
		}
	}	
	
	return 0;
}




