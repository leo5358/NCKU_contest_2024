#include<bits/stdc++.h>
#define ll long long 
#define fin ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int closestPower(int n, int p){
	int k=0;
	ll closest=1;
	while(true){
		ll power =pow(p,k);
		if(power>n){
			return abs(n-closest)<abs(n-power) ? k-1:k;
		}
		closest=power;
		k++;
	}
}
int main(){
    fin
    int n, p;
    cin >> n >> p;
    int coin=1;
    int nearest=closestPower(n,p);

   int weight=pow(p,nearest);
   while(weight	!= n){
   		if(abs(weight-n)>p){
   			weight+=p;
   			coin+=2;
   		}
   		else if(abs(weight-n)<p){
   			coin+=(weight-n)*2;
   			weight += (weight-n);
   		}
   		else if(abs(weight-n)==p){
   			coin +=2;
   			weight += p;
   		}
   }
    


    cout<<coin<<endl;
}
