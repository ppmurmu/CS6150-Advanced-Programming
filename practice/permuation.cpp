// #include <iostream>
// #include <vector>
// using namespace std;

// bool checkExists(vector<int> &curr, int n)
// {
//     auto it = find(curr.begin(), curr.end(), n);
//     return (it != curr.end());
// }

// vector<vector<int>> recursion(vector<int> &a, vector<vector<int>> curr)
// {
//     if (curr.size() == a.size())
//     {
//         return curr;
//     }

//     for (int i = 0; i < a.size(); i++)
//     {
//         // ddoesnt exxist in curr
//         if (checkExists(curr, a[i]) == false)
//         {
//             curr.push_back(a[i]);
//             recursion(a, curr);
//             curr.pop_back();
//         }
//     }
// }

// int main()
// {
//     vector<int> a = {1, 2, 3};

//     vector<int> res = recursion(a, {});

//     for (int i = 0; i < res.size(); i++)
//     {
//         cout <<
//     }
// }