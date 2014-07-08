/*
 * =====================================================================================
 *
 *       Filename:  coin_change2_DP.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/08/14 21:45:14
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

const int MAXN = 100;
int N, S;
vector<int> value(MAXN), min_state(MAXN), max_state(MAXN);
vector<int> min_path(MAXN), max_path(MAXN);

void dp_min(int s) {
    min_state[0] = 0;
    int ma = 1 << 30;
    cout << ma << endl;
    for (int i = 1; i <= s; ++i)
        min_state[i] = ma;

    for (int i = 1; i <= s; ++i) {
        for (int j = 0; j < N; ++j) {
            if (value[j] <= i) {
                if (min_state[i - value[j]] + 1 < min_state[i]) {
                    //cout << min_state[i - value[j]] + 1 << endl;
                    min_state[i] = min_state[i - value[j]] + 1;
                    min_path[i] = i - value[j];
                }
            }
        }
    }
        
}

void print_path(int s) {
    if (s <= 0 )
        return;
    cout << "P: " << s - min_path[s] << endl;
    print_path(min_path[s]);
}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; ++i) {
        cin >> value[i];
    }
    dp_min(S);
    cout << "min num: " << min_state[S] << endl;
    print_path(S);
}
