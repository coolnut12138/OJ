给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{ 2, 3, 4, 2, 6, 2, 5, 1 }及滑动窗口的大小3，那么一共存在6个滑动窗口，
他们的最大值分别为{ 4, 4, 6, 6, 6, 5 }； 针对数组{ 2, 3, 4, 2, 6, 2, 5, 1 }的滑动窗口有以下6个：
{ [2, 3, 4], 2, 6, 2, 5, 1 }，{ 2, [3, 4, 2], 6, 2, 5, 1 }，{ 2, 3, [4, 2, 6], 2, 5, 1 }，
{ 2, 3, 4, [2, 6, 2], 5, 1 }，{ 2, 3, 4, 2, [6, 2, 5], 1 }，{ 2, 3, 4, 2, 6, [2, 5, 1] }。
class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> ret;
		if (size == 0){
			return ret;
		}
		int max;
		//从一开始遍历到最后一个滑动窗口的开始
		for (size_t i = 0; i < num.size() - size + 1; i++){
			max = num[i];
			//注意判读滑动窗口的上限是i+size
			for (size_t j = i; j < i + size; j++){
				//判断滑动窗口中的最大值
				if (max < num[j]){
					max = num[j];
				}
			}
			ret.push_back(max);
		}
		return ret;
	}
};