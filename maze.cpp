/*
 * =====================================================================================
 *
 *       Filename:  maze.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/26/14 14:49:07
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
#include <queue>
#include <string.h>

using namespace std;

const int MAXN = 5;
int m = MAXN, n = MAXN;

vector<vector<int> > mapp(MAXN, vector<int>(MAXN) );
const char name[4] = {'U', 'R', 'D', 'L'};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

typedef struct state_t {
    int data;
    int action;
    int father;
}state_t;

const int STATE_MAX = MAXN * MAXN;
state_t nodes[STATE_MAX];

bool visited[STATE_MAX];

void hashset_init() {
    memset(visited, 0, sizeof(visited) );
}

bool hashset_find(const state_t &s) {
    return visited[s.data] == true;
}

void hashset_insert(const state_t &s) {
    visited[s.data] = true;
}

const state_t END = {24, -1, -1};
bool state_is_target(const state_t &s) {
    return s.data == END.data;
}

int action_cur;
#define ACTION_BEGIN 0
#define ACTION_END 4
int x, y;

void state_extend_init(const state_t &s) {
    action_cur = ACTION_BEGIN;
    x = s.data / n;
    y = s.data % n;
}

bool state_extend(const state_t &s, state_t &next) {
    while (action_cur < ACTION_END) {
        const int nx = x + dx[action_cur];
        const int ny = y + dy[action_cur];
        cout << "extend" << nx << " " << ny << endl;

        if (nx >= 0 && nx < m && ny >= 0 && ny < n && !mapp[nx][ny]) {
            next.data = nx * n + ny;

            if (!hashset_find(next) ) {
                next.action = action_cur;
                next.father = s.data;
                nodes[next.data] = next;

                action_cur++;
                return true;
            }
        }
        action_cur++;
    }
    return false;
}

int bfs(state_t &start) {
    queue<state_t> q;
    hashset_init();

    start.action = -1;
    start.father = -1;

    nodes[start.data] = start;
    hashset_insert(start);//the node start has visited
    if (state_is_target(start))
        return start.data;

    q.push(start);
    while (!q.empty() ) {
        const state_t s = q.front(); q.pop();
        state_t next;
        cout << s.data << " " << endl;

        state_extend_init(s);
        while (state_extend(s, next) ) {
            if (state_is_target(next) ) {
                return next.data;
            }
            q.push(next);
            cout << "push next" << endl;
            hashset_insert(next);
        }
    }
    return -1;
}

void print_path(const int end) {
    if (nodes[end].father == -1) {
        cout << "(" << end / n << ", " << end % n << ")";
        return;
    }
    print_path(nodes[end].father);
    cout << "(" << end / n << ", " << end % n << ")";
}

int main() {
    state_t start = {0, -1, -1};
    int i, j, input;
    int end; 
    for (i = 0; i < MAXN; ++i) {
        for ( j = 0; j < MAXN; ++j) {
            cin >> input;
            mapp[i][j] = input;
        }
    }
    end = bfs(start);
    if (end == -1) cout << "no path to end." << endl;
    else print_path(end);
    
    return 0;

}
/* 
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
 */
