#include<bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6.4 MB, 在所有 C++ 提交中击败了84.98% 的用户
//2021.2.21二刷
void dfs(vector<string> &res, string &digits, int i, int n, unordered_map<int, vector<char>> &m, string &tmp){
    if(i == n){
        res.push_back(tmp);
        return;
    }
    int c = digits[i] - '0';
    for(auto &ch:m[c]){
        tmp += ch;
        dfs(res, digits, i + 1, n, m, tmp);
        tmp.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    int n = digits.size();
    vector<string> res;
    if(n == 0)return res;
    unordered_map<int, vector<char>> m;
    m[2] = {'a', 'b', 'c'};
    m[3] = {'d', 'e', 'f'};
    m[4] = {'g', 'h', 'i'};
    m[5] = {'j', 'k', 'l'};
    m[6] = {'m', 'n', 'o'};
    m[7] = {'p', 'q', 'r', 's'};
    m[8] = {'t', 'u', 'v'};
    m[9] = {'w', 'x', 'y', 'z'};
    string tmp;
    dfs(res, digits, 0, n, m, tmp);
    return res;
} 

// 执行用时：4 ms, 在所有 C++ 提交中击败了49.75% 的用户     稳定后大概是这样
// 内存消耗：6.5 MB, 在所有 C++ 提交中击败了59.16% 的用户
map<int, vector<char>> table;
vector<string> res;
string tmp;
void traverseNum(string s, int n){
    if(n == (int)s.size())res.push_back(tmp);
    else{
        if(n == 0)tmp = "";
        for(auto &c:table[s[n] - '0']){
            tmp += c;
            traverseNum(s, n + 1);
            tmp.pop_back();//注意这行不要忘了，因为在循环中，马上会再次加上一个字符并递归，但是前后两次迭代时tmp应该是不变的，所以要减去
        }
    }
}
vector<string> firstletterCombinations(string digits) {
    if(digits.empty())return {};
    table[2] = {'a', 'b', 'c'};
    table[3] = {'d', 'e', 'f'};
    table[4] = {'g', 'h', 'i'};
    table[5] = {'j', 'k', 'l'};
    table[6] = {'m', 'n', 'o'};
    table[7] = {'p', 'q', 'r', 's'};
    table[8] = {'t', 'u', 'v'};
    table[9] = {'w', 'x', 'y', 'z'};
    traverseNum(digits, 0);
    return res;
}

int main(){
    letterCombinations("23");
}