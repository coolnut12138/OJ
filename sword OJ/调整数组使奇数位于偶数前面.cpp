//解法一：
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> oushu;
		vector<int> jishu;
		for (size_t i = 0; i < array.size(); i++){
			if (array[i] % 2 != 0){
				jishu.push_back(array[i]);
			}
			else{
				oushu.push_back(array[i]);
			}
		}
		for (size_t i = 0; i < oushu.size(); i++){
			jishu.push_back(oushu[i]);
		}
		array = jishu;
	}
};

//解法二：冒泡排序
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		for (int i = 0; i < array.size(); i++){
			for (int j = array.size() - 1; j > i; j--){
				if (array[j] % 2 == 1 && array[j - 1] % 2 == 0){
					swap(array[j], array[j - 1]);
				}
			}
		}
	}
};