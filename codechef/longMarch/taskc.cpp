#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define MAXN 100005
#define MP make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
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
ll mod=1000000009;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	int cnt=0;
	while(t-->0){
		int r,c;
		cin>>r>>c;
		int sr =r,sc = c;
		int mid = (r+c)/2;
		int steps=0;
		if(r==1 && c==1){} 
		else if (r==c)steps++;
		else steps+=2;
		steps +=55;
		cout<<steps<<nl;
		if(!(r==1&&c==1)){
			if(r!=c)cout<<mid<<" "<<mid<<nl;
			cout<<"1"<<" 1"<<nl;
		}
		for(int i = 2; i<=8;i++){
			int row = i,col = i;
			while( row >1 && col < 8 ){
				cout<<row<<" "<<col<<nl;
				row--;
				col++;
			}
			while( col >1 && row < 8){
				cout<<row<<" "<<col<<nl;
				row++;
				col--;
			}
			while(row >= i){
				cout<<row<<" "<<col<<nl;
				row--;
				col++;
			}
		}
	}
	return 0;
}




