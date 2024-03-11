#include <iostream>
#include <vector>
using namespace std;

void findPermutations(vector<int>& arr, vector<int>& res) {
    if (arr.size() == 0) {
        for (int num : res) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    
    for (int i = 0; i < arr.size(); i++) {
        int num = arr[i];
        vector<int> remaining = arr;
        remaining.erase(remaining.begin() + i);
        res.push_back(num);
        findPermutations(remaining, res);
        res.pop_back();
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> res;
    findPermutations(arr, res);

    return 0;
}
