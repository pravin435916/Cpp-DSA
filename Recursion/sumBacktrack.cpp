#include <iostream>
using namespace std;

void board(int target, int arr[], string ans, int sum, int last)
{
    if (sum == target)
    {
        cout << ans << endl;
        return;
    }
    if (sum > target) return;
    for (int i = last; i < 6; i++){  //use last for check forward
        sum += arr[i];
        board(target, arr, ans + to_string(arr[i]), sum, i + 1);
        sum -= arr[i]; // backtrack
    }
}

int main()
{
    int arr[6] = {2,3,5,1,6};
    board(10, arr, "", 0, 0);
    return 0;
}
