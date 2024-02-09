#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
void moveZeroes(vector<int>& nums) {
        int count =0;
        for(int i=0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++) {
                if(nums[j] != 0) {
                swap(nums[i],nums[j]);
                }
            }
                if(nums[i] == 0) {
                    count++;
                }
        }
        cout<<count;
        sort(nums.begin(),nums.end() - count);
    }
int main()
{
    vector<int> v = {1,0,1,0,9,3,0,5};
    // vector<int> v = {1,2,3,4,5,6,8,7,9,12};
    cout << v.size() << endl;
    //  for (int i =0; i < v.size(); i++){
    //     for (int j =i+1; j < v.size(); j++){ 
    //     if(v[j]% 2 == 0) {
    //         swap(v[i],v[j]);
    //     }
    //     }
    // }
    // int ct = 0;
    //  for (int i =0; i < v.size(); i++){
    //     for (int j =i+1; j < v.size(); j++){ 
    //     if(v[j] != 0) {
    //         swap(v[i],v[j]);
    //     }
    //     if(v[i] == 0) {
    //         ct++;
    //     }
    //     }
    // }
    // cout<< ct <<endl;
    // sort(v.begin(),v.end() - ct);
    moveZeroes(v);
    for(int i: v) {
        cout<< i <<" ";
    }
    return 0;
}