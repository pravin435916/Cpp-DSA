class Solution {
public:
    vector<string> sortPeople(vector<string>& n, vector<int>& h) {
        // vector<pair<int, string>> people;
        // for (int i = 0; i < n.size(); i++) {
        //     people.push_back({h[i], n[i]});
        // }
        // sort(people.begin(), people.end(), [](pair<int, string> a, pair<int, string> b) {
        //     return a.first > b.first;
        // });
        // vector<string> res;
        // for (auto x : people) {
        //     res.push_back(x.second);
        // }
        // return res;
         int ne = n.size();
    for (int i = 0; i < ne; i++) {
        for (int j = i + 1; j < ne; j++) {
            if (h[i] < h[j]) {
                swap(h[i], h[j]);
                swap(n[i], n[j]);
            }
        }
    }
    return n;

    }
};