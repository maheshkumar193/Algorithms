#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
class P{
	public:
		ll x,y;
		P(ll a=0,ll b=0){
			x=a;
			y=b;
		}
		void read(){
			cin>>x>>y;
		}
		void print(){
			cout<<x<<" "<<y<<"\n";
		}
		P operator-(const P &p){
			return P(x-p.x,y-p.y);
		}
		void operator -=(const P &p){
			x-=p.x;
			y-=p.y;
		}
		ll operator *(const P &p){
			return x*p.y-y*p.x;
		}
		~P(){
		}
};
bool cmp(P & p1,P & p2){
	if(p1.x!=p2.x){
		return p1.x<p2.x;
	}
	return p1.y<p2.y;
}
int main()
{
	int n;
	cin>>n;
	vector<P> points(n);
	for(int i=0;i<n;i++){
		points[i].read();
	}
	sort(points.begin(),points.end(),cmp);
	vector<P> up,down;
	P p1 = points[0], p2 = points[n-1];
    up.push_back(p1);
    down.push_back(p1);
    for(int i=1;i<n;i++){
    	if(i==n-1 || (points[i]-p1)*(p2-points[i])<=0){
    		int m = up.size();
    		while(m>=2 && (up[m-1]-up[m-2])*(points[i]-up[m-1])>0){
    			m--;
    			up.pop_back();
    		}
    		up.push_back(points[i]);
    	}
    	if(i==n-1 || (points[i]-p1)*(p2-points[i])>=0){
    		int m = down.size();
    		while(m>=2 && (down[m-1]-down[m-2])*(points[i]-down[m-1])<0){
    			m--;
    			down.pop_back();
    		}
    		down.push_back(points[i]);
    	}
    }
	set<pair<ll,ll>> ans;
	for(int i=0;i<up.size();i++){
		ans.insert({up[i].x,up[i].y});
	}
	for(int i=down.size()-2;i>0;i--){
		ans.insert({down[i].x,down[i].y});
	}
	int sz = ans.size();
	cout<<sz<<"\n";
	for(auto i:ans){
		cout<<i.f<<" "<<i.s<<"\n";
	}
	return 0;
}

