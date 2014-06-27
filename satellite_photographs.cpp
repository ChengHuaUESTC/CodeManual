/*
 * =====================================================================================
 *
 *       Filename:  satellite_photographs.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/27/14 14:23:07
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
const int MAXN = 10;
vector<vector<char> > mapp(MAXN, vector<char>(MAXN) );
vector<vector<bool> > state(MAXN, vector<bool>(MAXN, true) );
int count1 = 0;
int W, H;

void dfs(int i, int j) {
    //cout << "cout = " << count << endl;
    if (i < 0 || i >= W || j < 0 || j >= H)
        return;

    if (mapp[i][j] == '.' || state[i][j] == false)
        return;

    count1++;
    state[i][j] = false;
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
}

int main() {
    cin >> W >> H;
    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < H; ++j) {
            char ch;
            cin >> ch;
            mapp[i][j] = ch;
        }
    }

    int max = 0;
    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < H; ++j) {
            count1 = 0;
            dfs(i, j);
            if (count1 > max) max = count1;
        }
    }
    cout << "max = " << max << endl;
    return 0;
}





