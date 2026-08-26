#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
 int n,q;
 cin>>n>>q;
 vector<vector<int>> a;
 for(int i=0;i<n;i++){
     int size;
     cin>>size;
     a.push_back(vector<int>(size));
     for(int io=0;io<size;io++){
         int value;
         cin>>value;
         a[i][io]=value;
     }
     
 }
 int ans[q];
 for(int i=0;i<q;i++){
     int x,y;
     
     cin>>x>>y;
     ans[i]=a[x][y];
 }
	for(int i=0;i<q;i++){
	    cout<<ans[i]<<"\n";
	}
	return 0;
}
