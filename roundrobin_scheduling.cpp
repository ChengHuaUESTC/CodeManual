/*
 * =====================================================================================
 *
 *       Filename:  roundrobin_scheduling.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/26/14 09:37:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  NDSL UESTC
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
using namespace std;

#define MAXN 512
vector<vector<short> >  schedule(MAXN, vector<short>(MAXN, 0) );

void dc(const int k) {
    int i, j, t;
    int n, n2;

    n = 2;
    schedule[0][0] = 1; schedule[0][1] = 2;
    schedule[1][0] = 2; schedule[1][1] = 1;
    
    for (t = 1; t < k; t++, n *= 2) {
        n2 = n * 2;
        for (i = n; i < n2; ++i) 
            for (j = 0; j < n; ++j)
                schedule[i][j] = schedule[i-n][j] + n;

        for (i = 0; i < n; ++i)
            for (j = n; j < n2; ++j)
                schedule[i][j] = schedule[i + n][j - n];

        for (i = n; i < n2; ++i)
            for (j = n; j < n2; ++j)
                schedule[i][j] = schedule[i - n][j-n];
    }
}

int main() {
    int k, N;
    int i, j;
    cin >> k;
    N = 1 << k;
    dc(k);
    for (i = 0; i < N; ++i) {
        for (j = 1; j < N; ++j)
            cout << schedule[i][j] << " ";
        cout << endl;
    }
}
