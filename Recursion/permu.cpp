#include <iostream>
#include <string>
using namespace std;

void permutation(string s, string t, string ans)
{
    if (ans.length() == 2)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        permutation(s.substr(0, j) + t.substr(j + 1), t, ans + s[j]);
    }
}

int main()
{
    permutation("abc", "def", "");
    return 0;
}
