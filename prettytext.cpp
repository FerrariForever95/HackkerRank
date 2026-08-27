#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
    cout <<nouppercase<< hex << showbase << A<<"\n";
    cout << fixed << setprecision(2) << showpos << B<<"\n";
    cout << setprecision(9) << C<<"\n";
    
	}
	return 0;

}
