#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "IITM__peter_new";
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == '_' && s[i + 1] == '_')
        {
            s[i] = '#';
            s[i + 1] = '.';
            i++;
            continue;
        }
        if (s[i] == '_')
        {
            s[i] = '#';
        }
    }
    cout << s;
}