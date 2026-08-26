#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Element {
	string tagname;
	string attributename;
	string value;
};
Element parser(string command, Element e) {
	int i=0;
	int s=0;
	string tagname;
	string attributename;
	string value;
	bool completion=false;
	if(command[0]=='<' && command[command.length()-1]=='>') {
		for(int s=0; s<command.length(); s++) {
			if(command[s]=='/') {
				completion=true;
			}


		}
		if(completion!=false){

		i=1;
		while(command[i]!=' ') {
			tagname+=command[i];
			i++;

		}
		i++;
		while(command[i]!=' ') {
			attributename+=command[i];
			i++;
		}

		while(command[i]!='=') {
			i++;
		}
		i++;
		while(command[i]!='"') {
			i++;
		}
		i++;
		while(command[i]!='"') {
			value+=command[i];
			i++;
		}



		cout<<tagname<<" "<<attributename<<" "<<value;
	}
	}
	e.tagname=tagname;
	e.attributename=attributename;
	e.value=value;
	return e;

}
int main() {
	int n;
	int q;
	cin>>n>>q;
	struct Element e[n];
	for(int i=0; i< n ; i++) {
		string command;
		getline(cin,command);
		parser(command,e[i]);
		

	}

}
