#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    int q;
    string name;
    int value;
    cin>>n;
    map <string,int> m;
    for(int i=0;i<n;i++){
        cin>>q>>name;
        switch(q){
            case 1:
            cin>>value;
            m[name]+=value;
            break;
            case 2:
            m.erase(name);
            break;
            case 3:
            cout<<m[name]<<'\n';
            
        }
    }
    return 0;
}



