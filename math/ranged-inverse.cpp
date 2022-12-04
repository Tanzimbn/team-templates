const int N = 1e5 + 5;
int inv[N];
void range_mod_inverse(int n, int mod) {
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = mod - 1LL * (mod / i) * inv[mod % i] % mod;
    }
}
