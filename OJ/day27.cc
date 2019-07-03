//��ʹ�������������ӷ�
//����һ��
class Solution {
public:
    int Add(int num1, int num2)
    {
        //�����Լ�
        if(num1 > 0){
            while(num1--){
                num2++;
            }
        }
        else if(num1 < 0){
            while(num1++){
                num2--;
            }
        }
        return num2;
    }
};
//��������λ����
1������������൱��ÿһλ��ӣ��������ǽ�λ��
2�����������룬������һλ���൱����ý�λ��
3�������������Ľ�����
class Solution {
public:
    int Add(int num1, int num2)
    {
        while(num2 != 0){
            int sum = num1 ^ num2;    //������
            int carry = (num1 & num2) << 1;//��������һλ�ý�λ
            num1 = sum;
            num2 = carry;
        }
        return num1;
    }
};


//���������ߣ��ж��ǲ���������
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    while(cin >> a >> b >> c){
        if((a + b > c) && (a + c > b) && (b + c > a) && (abs(a - b) < c) && (abs(a - c) < b) && (abs(b - c) < a)){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}