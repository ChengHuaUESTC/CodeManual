/*
 * =====================================================================================
 *
 *       Filename:  coin_change_memo.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/08/14 22:22:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  NDSL UESTC
 *
 * =====================================================================================
 */

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
const int MAXN = 1000;
vector<int> value(MAXN), status(MAXN);
int N, S;

int dp(int s) {
    if (status[s] != -1) return status[s];
    status[s] = 1 << 30;
    for(int i = 0; i < N; ++i) {
        if (value[i] <= s) {
            int tmp = dp(s - value[i]) + 1;
            status[s] = status[s] < tmp ? status[s] : tmp;
        }
    }
    return status[s];
}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; ++i) {
        cin >> value[i];
    }
    for (int i = 0; i <= S; ++i) {
        status[i] = -1;
    }
    
    status[0] = 0;
    dp(S);
    cout << "min num: " << status[S] << endl;
}
