题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

//思路：从头开始找空格的个数，从尾部逐一替换
//因为从头直接换的话每一次移动都要牵扯到后面所有的元素都要移动
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int count = 0;
        for(int i = 0; i < length; i++){
            if(str[i] == ' '){
                count++;
            }
        }
        
        for(int i = length - 1; i >= 0; i--){
            if(str[i] != ' '){
                str[i + 2*count] = str[i];
            }else{
                count--;
                str[i + 2*count] = '%';
                str[i + 2*count + 1] = '2';
                str[i + 2*count + 2] = '0';
            }
        }
	}
};