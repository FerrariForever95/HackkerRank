#include <iostream>
#include <vector>
using namespace std;

int main() {

    unsigned int N, S, P, Q;

    cin >> N >> S >> P >> Q;

    const unsigned int MOD = 1u << 31;

    vector<bool> seen(MOD, false);

    unsigned int x = S % MOD;
    unsigned int distinct = 0;

    for (unsigned int i = 0; i < N; i++) {

        if (!seen[x]) {
            seen[x] = true;
            distinct++;
        }

        x = ((unsigned long long)x * P + Q) % MOD;
    }

    cout << distinct << endl;

    return 0;
}
