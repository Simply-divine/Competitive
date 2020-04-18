#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define sq(a) (a)*(a)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int binarySearch(int a[],int key,int lo,int hi){
	while(lo<=hi){
		int k = (lo+hi)/2;
		if(a[k]==key){
			return k;
		}
		if(key<a[k])hi = key-1;
		else lo = key+1;	
	}
	return -1;
}
int binarySearch(vi a,int key,int lo,int hi){
	int k = 0;
	int n = a.size();
	for(int b = n/2;b>=1;b/=2){
		while(k+b<n&&key>=a[k+b])k+=b;
	}
	if(a[k]==key){
		return k;
	}
	else return -1;
}
bool ok(int x){
	if(x>10000)return 1;
	else return 0;	
}
struct P{
int x;
int y;
bool operator<(const P &p){
	if(p.x!=x)return x<p.x;
	else return y<p.y;
}
};
bool comp(P a,P b){
	if(a.y!=b.y)return a.y<b.y;
       	else return a.x<b.x;	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int pi = -1;
	for(ll i = 100000;i>=1;i/=2){
		while(!ok(pi+i))pi+=i;
	}
	cout<<"smallest true  value"<<pi+1<<"\n\n";
	int e[]={1,3,5,6,9};
	int z = lower_bound(e,e+5,5)-e;
	cout<<"binary search\n";
	if(z<5&&e[z]==5){
		cout<<z<<"\n\n";
	}
	cout<<z<<"\n\n";
	vector<int> v;
	v.pb(1);
	v.pb(2);
	v.pb(3);
	cout<<"binarySearch in vector "<<binarySearch(v,3,0,2)<<"\n";
//	cout<<" last element is "<<v.back()<<endl; 
//	sort(v.begin(),v.end());
	sort(v.rbegin(),v.rend());
	random_shuffle(v.begin(),v.end());
	cout<<"Random shuffling"<<endl;
	for(auto a:v){
		cout<<a<<"\n";
	}
	cout<<endl<<endl;
	vector<P> v1;
	P p1;
	p1 = {1,2};
	v1.pb(p1);
	v1.pb({2,1});
	sort(v1.begin(),v1.end(),comp);;
	for(auto x:v1){
		cout<<x.x<<" ";
		cout<<x.y<<"\n";
	}
	unordered_set<int> s;
	cout<<"set iterator"<<endl;
	s.insert(5);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(3);
	for(auto it = s.begin();it!=s.end();it++){
		cout<<*it;
	}
	cout<<endl;
	//cout<<s.count(3)<<endl;
	//s.erase(s.find(3));
	map<string,int> m;
	m["monkey"] = 2;
	m["bananas"] = 1;
	cout<<m["monkey"]<<endl;//2
	cout<<m["mokey"]<<endl;//0
	if(m.count("monkey")){
		//key exists;
		cout<<"Key exists"<<endl;
	}
	//sort(m.begin(),m.end());
	for(auto x:m){
		cout<<x.first<<" "+x.second<<"\n";
	}
	for(auto x:s)
		cout<<x<<endl;
	return 0;
}



