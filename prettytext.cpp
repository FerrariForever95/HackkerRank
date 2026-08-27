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
        int x=(int)A;
        
    cout << setw(0)<<nouppercase << hex << showbase << x << "\n";

        cout << right<<fixed << setprecision(2) << showpos
             << setfill('_') << setw(15) << B << "\n";

        cout <<noshowpos<<uppercase<< scientific << setprecision(9) << C << "\n";
    
	}
	return 0;

}
