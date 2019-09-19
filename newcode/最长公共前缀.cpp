#include <iostream>
#include <vector>
#include <string>
using namespace std;

string LonggestPre(vector<string>& ss){
    if(ss.size() == 0){
        return "";
    }
    string tmp = ss[0];
    for(int i = 1; i < ss.size(); i++){
        while(ss[i].find(tmp) != 0){
            tmp = tmp.substr(0, tmp.size() - 1);
            if(tmp.empty()){
                return "";
            }
        }
    }
    return tmp;
}

int main()
{
    vector<string> ss;
    for(string str; cin >> str; ss.push_back(str)){}
    cout << LonggestPre(ss) << endl;
    return 0;
}