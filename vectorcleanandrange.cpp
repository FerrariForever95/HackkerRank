#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector <int> v;
    int n;
    cin>>n;
    int e;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
        
    }
    cin>>e;
    v.erase(v.begin()+(e-1));
    int start;
    int end;
    cin>>start>>end;
    v.erase(v.begin()+(start-1),v.begin()+(end-1));
    cout<<v.size()<<"\n";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
