// #include <bits/stdc++.h>
// #include <sstream>
// #include <unordered_map>
// using namespace std;
// vector<pair<string,string>> solve(vector<pair<string,string>> &v,string query)
// {
//     int n = v.size();
//     istringstream ss(query);
//     vector<string> q;
//     string word;
//     while (ss >> word)
//     {
//         q.push_back(word);
//     }
//     map<string, string> mp;
//     for(int i = 0;i<n;i++)
//     {
//         mp[v[i].first] = v[i].second;
//     }
//     string action = q[0],prop = q[1],val = q[2];
//     if(action == "edit")
//     {
//         // mp.erase(mp.find(q[1]));
//         if(mp.find(q[1])!=mp.end())mp[q[1]] = q[2];
//     }else
//     {
//         if(mp.find(prop)!=mp.end())mp.erase(prop);
//     }
//     vector<pair<string,string>> ans;
//     for(auto it:mp)
//     {
//         ans.push_back({it.first,it.second});
//     }
//     return ans;
// }
// int main()
// {
//     vector<pair<string,string>> v = {{"name","John"},{"lastName","Bliss"},{"city","Florida"}};
//     string query = "delete city Florida";
//     vector<pair<string,string>> ans = solve(v,query);
//     for(auto it:ans)
//     {
//         cout<<it.first<<" "<<it.second<<endl;
//     }
//     return 0;
// }
function solve(obj, operation, prop, newValue) {
    let map = new Map(obj);

    if (operation === "edit") {
        if (map.has(prop)) {
            map.set(prop, newValue);
        }
    } else {
        if (map.has(prop)) {
            map.delete(prop);
        }
    }

    let ans = [];
    map.forEach((value, key) => {
        ans.push([key, value]);
    });

    return ans;
}

let data = [["name", "John"], ["lastName", "Bliss"], ["city", "Florida"]];
let ans = solve(data, "delete", "city", "Seattle");

ans.forEach(item => {
    console.log(item[0], item[1]);
});