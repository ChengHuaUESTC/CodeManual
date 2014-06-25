
/*
 * =====================================================================================
 *
 *       Filename:  01knapsack.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/25/14 10:59:48
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


#define MAXLEN 100
 
vector<vector<int> > f(MAXLEN + 1, vector<int>(MAXLEN + 1, 0) );
vector<int> v(MAXLEN + 1), w(MAXLEN + 1), d(MAXLEN + 1);

void dp(int n, int k) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            f[i][j] = f[i-1][j];
            if (j >= w[i]) {
                int temp = f[i-1][j-w[i]] + v[i];
                f[i][j] = temp > f[i][j] ? temp : f[i][j];
            }
        }
    }
}

void dp_d(int n, int k) {
    for (int i = 1; i <= n; ++i) {
        for (int j = k; j >= w[i]; --j) {
            int tmp = d[j - w[i]] + v[i];
            if (tmp > d[j]) d[j] = tmp;
        }
    }
}

int main() {
     
    int N, W;
    cin >> N;
    cin >> W; //N=3, W=10
    int i, temp;
    for (i = 1; i <= N; ++i) {
        cin >> temp;
        v[i] = temp;
    }
    for (i = 1; i <= N; ++i) {
        cin >> temp;
        w[i] = temp;
    }
    dp(N, W);
    cout << "Max Value: " << f[N][W] << endl;

    dp_d(N, W);                                                                                                                          
    cout << "Max Value: " << f[N][W] << endl;
}    
