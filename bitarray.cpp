#include <bits/stdc++.h>
using namespace std;

int main() {
    long long S, P, Q, N;
    cin >> S >> P >> Q >> N;

    const long long MOD = 1LL << 31;

    set<long long> seen;

    long long x = S % MOD;

    for (long long i = 0; i < N; i++) {

        if (seen.count(x)) {
            break;
        }

        seen.insert(x);

        x = (x * P + Q) % MOD;
    }

    cout << seen.size() << endl;

    return 0;
}
