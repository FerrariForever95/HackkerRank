#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string parser(string command){
    int i=0;
     string tagname;
        string attributename;
        string value;
    if(command[0]=='<' && command[command.length()-1]=='>'){
        i=1;
        while(command[i]!=' '){
            tagname+=command[i];
            i++;
            
        }
        i++;
        while(command[i]!=' '){
            attributename+=command[i];
            i++;
        }
         
         while(command[i]!='='){
             i++;
         }
         i++;
         while(command[i]!='"'){
             i++;
         }
         i++;
         while(command[i]!='"'){
             value+=command[i];
             i++;
         }
        
        
    
     cout<<tagname<<" "<<attributename<<" "<<value;
    }
    
    return tagname,attributename,value;
}
int main(){
    int n;
    int q;
    string commands[n];
    cin>>n>>q;
    for(int i=0; i< n ; i++){
    string command;
    getline(cin,command);
    commands[i]+=parser(command);
    commands+="%";
    
    }
    
}
im getting theree
