#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    set<int>s;
    cin>>n;
    for(int i=0;i<n;i++){
        int q,value;
        cin>>q>>value;
        switch(q){
            case 1:
            s.insert(value);
            break;
            case 2:
            s.erase(value);
            break;
            case 3:
            set<int>::iterator itr=s.find(value);
            if(*itr==value){
                cout<<"Yes"<<"\n";
                
            }
            else{
                cout<<"No"<<"\n";
            }
            
            
        }
    }
        
    return 0;
}



