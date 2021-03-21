#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int cases;
    cin >> cases;
    for (int cur_case = 1; cur_case <= cases; ++cur_case){
        int r,c;
        cin >> r >> c;
        vector<vector<int>> grid(r+1, vector<int>(c+1));

        int max_h = 0;
        int max_row, max_col;
        for (int rc = 0; rc < r; ++rc){
            for (int cc = 0; cc < c; ++cc){
               int cur_height;
               cin >> cur_height;
               grid[rc][cc] = cur_height;
               max_h = max(max_h, cur_height);
            }
        }
        vector<set<pair<int, int>>> height_set(max_h+1);
        for (int rc = 0; rc < r; ++rc){
            for (int cc = 0; cc < c; ++cc){
               height_set[grid[rc][cc]].insert(make_pair(rc, cc));
            }
        }
        long long ans = 0;
        int move_r[4] = {0,0,1,-1};
        int move_c[4] = {1,-1,0,0};

        while (max_h > 0){
            for (auto it = height_set[max_h].begin(); it != height_set[max_h].end(); ++it){
                for (int i = 0; i < 4; ++i){
                    int new_row = (*it).first + move_r[i];
                    int new_col = (*it).second + move_c[i];
                    if (new_row >= 0 && new_col >= 0 && new_row < r && new_col < c) {
                        int adjust_height = grid[new_row][new_col];
                        if (adjust_height < max_h){
                            auto remove_find = height_set[adjust_height].find(make_pair(new_row, new_col));
                            height_set[adjust_height].erase(remove_find);
                            ans += (long long)(max_h - adjust_height - 1);
                            height_set[max_h - 1].insert(make_pair(new_row, new_col));
                            grid[new_row][new_col] = max_h - 1;
                        }
                    }
                }
            }
            max_h -= 1;
        }
        cout << "Case #" << cur_case << ": " << ans << endl;
    }
    return 0;
}
