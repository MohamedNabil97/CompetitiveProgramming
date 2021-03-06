#include <bits/stdc++.h>
#include <vector>
#include<cstdio>
#include <cstdlib>
#include <complex>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;

#define lp(i,n) for(ll i=0; i<n; i++)
#define ll long long
#define pb push_back
#define mp make_pair

#define pii pair<ll,ll>
#define pdd pair<double,double>
#define ff first
#define ss second
#define nl "\n"

#define EPS 1e-7
#define OO 1000000000

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
#define crossp(a,b) ((conj(a)*b).imag())
#define same(a,b) ((dcmp(((a).X),((b).X))==0 )&& (dcmp(((a).Y),((b).Y))==0))

#define lengthSqr(a) (dp((a),(a)))

#define rotateO(p,ang) ((p)*exp(poll(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

#define debugme freopen("out.txt","w",stdout)
#define endp return 0;

#define goleft(L,R)  L, (L+R)/2 ,idx*2
#define goright(L,R) (L+R)/2+1, R, idx*2+1
const double PI= acos(-1.0);
long double fixAngle(long double A){return A > 1 ? 1 : (A < -1 ? -1 : A);}
double dcmp( double a,double b){return fabs(a-b)<EPS?0 : a>b? 1:-1; }

const int MAXN=4*1000006;
map<int,int> rnk;

int segtree[4*MAXN];

void update(int L, int R, int idx, int t, int val){

    if(t>R || t<L) return;

    if(L==R && L==t) {
        segtree[idx]+=val;
        return;
    }
    update(L,(L+R)/2,idx*2,t,val);
    update((L+R)/2+1,R,idx*2+1,t,val);

    segtree[idx]=max(segtree[idx*2],segtree[idx*2+1]);
}

int query(int L, int R,int idx,int tl,int tr){
     if(tl>R || tr<L) return 0;

    if(L>=tl && R<=tr) {
        return segtree[idx];
    }
    return max(query(L,(L+R)/2,idx*2,tl,tr),query((L+R)/2+1,R,idx*2+1,tl,tr));


}
int currentk(){
    return segtree[1];
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> nums(n);
    lp(i,n){
        scanf("%d",&nums[i]);
        rnk[nums[i]];
    }
    int r=0;
    for(auto &x:rnk){
        x.ss=r++;
    }
    for(int &x: nums) x=rnk[x];
    int e=0;
    ll ans=0;
    update(0,MAXN,1,nums[0],1);
    for(int s=0; s<nums.size(); s++){
        while(s>e){
            e++;
            update(0,MAXN,1,nums[e],1);
        }
        while(currentk()<k && e<nums.size()-1){
            e++;
            update(0,MAXN,1,nums[e],1);
        }

        if(currentk()>=k){
            ll temp=nums.size()-e;
        ans+=temp;
        }
        update(0,MAXN,1,nums[s],-1);




    }
     printf("%lld", ans);


}
