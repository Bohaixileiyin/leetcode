#include <bits/stdc++.h>
using namespace std;

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
// 内存消耗：6 MB, 在所有 C++ 提交中击败了92.84% 的用户
string replaceSpace(string s) {
    string res;
    for(auto ch:s){
        if(ch == ' '){
            res += "%20";
        }else{
            res += ch;
        }
    }
    return res;
}

int main(){
    cout << "print sth." << endl;
}