/*
 * =====================================================================================
 *
 *       Filename:  lis.cpp
 *
 *    Description:  longest increasing subsequence
 *
 *        Version:  1.0
 *        Created:  06/25/14 17:03:51
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

#define MAXN 100
vector<int> d(MAXN);
vector<int> v(MAXN);

int dp(int n) {
    int total = 1;
    d[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int tmp = 0;
        for (int j = 1; j < i; ++j) {
            if (v[j] < v[i]) {
                tmp = tmp > d[j] ? tmp : d[j];
                //cout << tmp << endl;
            }
        }
        d[i] = tmp + 1;
        total = total > d[i] ? total : d[i];
    }
    return total;
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int tmp;
        cin >> tmp;
        v[i] = tmp;
    }
    int num = dp(N);
    cout << "NUM: " << num << endl;
}
