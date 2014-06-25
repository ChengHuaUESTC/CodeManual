/*
 * =====================================================================================
 *
 *       Filename:  mcss.cpp
 *
 *    Description:  maximum continuous subsequence sum
 *
 *        Version:  1.0
 *        Created:  06/24/14 21:35:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  NDSL UESTC
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int LEN = 1000000;
vector<int> ivect(LEN);
vector<int> vd(LEN);

int L, R;
int mcss_seq(int lhs, int rhs) {
    int total = -10000;
    for (int i = lhs; i <= rhs; ++i) {
        if (vd[i-1] > 0) {
            vd[i] = vd[i-1] + ivect[i];
            if (vd[i] > total) {
                R = i;
                total = vd[i];
            }
        }
        else {
            vd[i] = ivect[i];
            if (vd[i] > total) {
                R = i;
                total = vd[i];
            }
        }
        cout << "total=" << total << endl;
    }
    return total;
}

int main() {
    //ivect = {0, 2, -3, 2, 3, -4, 2, 3, -3, 1};
    ivect.push_back(0);
    int a;
    for (int i=1; i <= 9; ++i) {
        cin >> a;
        ivect[i] = a;
    }
    int total = mcss_seq(1, 9);
    cout << total << endl;
    cout << L << endl;
    cout << R << endl;
    return 0;
}
