/*
As in editorial

*/

#include<bits/stdc++.h>
#include <iomanip>
#include <vector>
#include<cstdio>
#include <cstdlib>
#include <complex>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;
#define ll long long


#define pii pair<long long, long long>
#define endl "\n"

#define EPS 1e-7
#define OO 100000000

#define on(i,n) i=i|(1<<n)
#define off(i,n) i=i& (~(1<<n))

typedef  complex<double> point;
#define X real()
#define Y imag()

#define vec(a,b) (b-a)
#define angle(a) (atan2(((a).Y),((a).X)))

#define length(a) (hypot(((a).real()),((a).imag())))
#define normalize(a) ((a)/(length(a)))

#define dotp(a,b) ((conj(a)*(b)).real())
#define crossp(a,b) ((conj(a)*(b)).imag())
#define same(a,b) ((dcmp(((a).X),((b).X))==0 )&& (dcmp(((a).Y),((b).Y))==0))

#define lengthSqr(a) (dp((a),(a)))

#define rotateO(p,ang) ((p)*exp(poll(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;

#define goleft(L,R)  L, (L+R)/2 ,idx*2
#define goright(L,R) (L+R)/2+1, R, idx*2+1

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double PI= acos(-1.0);
long double fixAngle(long double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp( double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }


bool comp(pair<pii,string> &x, pair<pii,string> &y){

    return x.first.first*y.first.second>x.first.second*y.first.first;
}



int main(){


    int n;
    cin>>n;
    vector<pair<pii,string>> data(n);
    for(int i=0; i<n; i++){
        cin>>data[i].second;
        int a=0;
        for(auto x:data[i].second){
            if(x=='s'){
                a++;
            }
        }
        data[i].first={a,data[i].second.size()-a};
    }
    sort(data.begin(),data.end(),comp);


    ll ans=0;
    ll add=0;
    string nw; for(auto s:data){nw+=s.second; }
    //cout<<nw<<endl;
    for(int i=0; i<nw.size(); i++){
        if(nw[i]=='s')add++;
        else ans+=add;


    }
    cout<<ans<<endl;
}
