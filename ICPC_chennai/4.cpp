#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin >> n;
		int x,cnt=0;
		for(int i=0;i<n;i++){
			cin >> x;
			if(x==-1){
				cnt++;
			}
		}
		double a=1;
		double d=0.5;
		cout << a+(cnt-1)*d << "\n";
	}
	return 0;
}
