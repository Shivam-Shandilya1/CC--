#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 26;
const int S = 111'111;
void dists(int w[N][N], char word[S]) {
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            w[i][j] = 0;

    for (char *t = word; *t; t++) {
        for (int c = *t - 'a', i = 0; i <= c; i++) {
            w[i][c]++;
            for (int j = c + 1; j < N; j++)
                w[i][j] = max(w[i][j], w[i][j - 1]);
        }
    }
}

void solve() {
    static int d[N][N][N], w[N][N];
    static char word[S];

    int n, q;
    scanf("%d%d", &n, &q);
    for (int t = 0; t < N; t++) 
        for (int i = 0; i < N; i++)
            for (int j = i; j < N; j++) d[t][i][j] = 0;

    while (n--) {
        scanf("%s", word);
        dists(w, word);
        for (int i = 0; i < N; i++)
            for (int j = i; j < N; j++)
                d[1][i][j] = max(d[1][i][j], w[i][j]);
    }

    for (int t = 1; t < N; t++)
        for (int i = 0; i < N; i++)
            for (int j = i; j < N; j++)
                for (int k = i; k <= j; k++)
                    d[t][i][j] = max(d[t][i][j], d[t-1][i][k] + d[1][k][j]);

    ll ans = 0;
    for (int m = 0, t = min(N-1, q); m < N; m++)
        for (int l = 0; l <= t; l++)
            ans = max(ans, d[l][0][m] + d[t-l][m][N-1] + d[1][m][m] * ll(q-t));

    printf("%lld\n", ans);
}

int main() {
    int t;
    for (scanf("%d", &t); t--; solve());
}
