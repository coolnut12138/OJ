ţ�ͣ�����������
#include <iostream>
using namespace std;

int getTotalCount(int month)
{
    int num = 0;
    if(month <= 2){
        return 1;
    }
    return getTotalCount(month - 1) + getTotalCount(month - 2);
}

int main()
{
    int month = 0;
    while(cin >> month){
        cout << getTotalCount(month) << endl;
    }
    return 0;
}


//ͨ���ƥ��
���ӣ�https://www.nowcoder.com/questionTerminal/43072d50a6eb44d2a6c816a283b02036
��Դ��ţ����

#include <iostream>
#include <string>
using namespace std;

bool isMatch(const char *str1, const char *str2)
{
    if(*str1 == '\0' && *str2 == '\0'){
        return true;
    }
    if(*str1 == '\0' || *str2 == '\0'){
        return false;
    }
    
    if(*str1 == '?'){
        //�ʺ�ֻƥ��һ���ַ�
        return isMatch(str1 + 1, str2 + 1);
    }
    if(*str1 == '*'){
        //�Ǻ�ƥ��0�������ַ�
        return (isMatch(str1 + 1, str2) || isMatch(str1 + 1, str2 + 1) || isMatch(str1, str2 + 1));
    }
    if(*str1 == *str2){
        return isMatch(str1 + 1, str2 + 1);
    }
    return false;
}

int main()
{
    string str1, str2;
    while(cin >> str1 >> str2){
        if(isMatch(str1.c_str(), str2.c_str())){
            cout << "true" << endl;
        }else {
            cout << "false" << endl;
        }
    }
    return 0;
}