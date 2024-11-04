#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a = "12.5";
    int b = stoi(a);

    string c = to_string(b) + "feef";
    cout << c;
    return 0;
}