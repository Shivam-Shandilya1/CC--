#include <bits/stdc++.h>
using namespace std;

struct Tower {
    int min_block; // minimum block number
    vector<int> blocks; // blocks in the tower
};

bool operator<(const Tower &a, const Tower &b) {
    return a.min_block > b.min_block;
}

int main() {
    int n;
    cin >> n;
    vector<Tower> towers(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        towers[i].blocks.resize(k);
        for (int j = 0; j < k; j++) {
            cin >> towers[i].blocks[j];
        }
        sort(towers[i].blocks.begin(), towers[i].blocks.end()); // sort blocks
        towers[i].min_block = towers[i].blocks[0];
    }
    sort(towers.begin(), towers.end()); // sort towers by minimum block number

    int s = 0, c = 0;
    while (towers.size() > 1) {
        int split = 0;
        Tower a = towers[towers.size()-1], b = towers[towers.size()-2];
        if (a.min_block > b.min_block) {
            split = 1;
            s++;
        }
        c++;
        vector<int> new_blocks;
        new_blocks.reserve(a.blocks.size() + b.blocks.size());
        new_blocks.insert(new_blocks.end(), a.blocks.begin() + split, a.blocks.end());
        new_blocks.insert(new_blocks.end(), b.blocks.begin(), b.blocks.end());
        Tower new_tower = { new_blocks[0], new_blocks };
        towers.pop_back();
        towers.pop_back();
        towers.push_back(new_tower);
        sort(towers.begin(), towers.end());
    }

    cout << s << " " << c << endl;
    return 0;
}
