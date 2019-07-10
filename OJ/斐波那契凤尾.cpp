// write your code here cpp
/*cout << 's' << setw(8) << 'a' << endl;
则在屏幕显示
s        a
//s与a之间有7个空格，setw()只对其后面紧跟的输出产生作用，如上例中，表示'a'共占8个位置，不足的用空格填充。若输入的内容超过setw()设置的长度，则按实际长度输出。
setw()默认填充的内容为空格，可以setfill()配合使用设置其他字符填充。
如
cout << setfill('*') << setw(5) << 'a' << endl;
则输出：
****a //4个*和字符a共占5个位置。*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a[100001] = { 0 };
	int n;
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i < 100001; i++){
		a[i] = (a[i - 1] + a[i - 2]) % 1000000;
	}
	while (cin >> n){
		if (n < 37){
			cout << a[n] << endl;
		}
		else{
			cout << setw(6) << setfill('0') << a[n] << endl;
		}
	}
	return 0;
}
