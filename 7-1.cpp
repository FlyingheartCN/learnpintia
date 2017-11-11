#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[])
{
	int K;
	vector<int> vec;
	cin >> K;
	//读取第一行，数量
	int amount;
	for (int i = 0; i<K; ++i){
		cin >> amount;
		vec.push_back(amount);
	}
	//逐个读取标准输入，一次一个数，加到vector后面
	int summary = 0;
	int max = 0;
	for (int i = 0; i<vec.size(); ++i)
	{
		summary += vec[i];//把这个数加进summary里面
		if (summary>max){
			max = summary;//如果新的和数比之前的max更大，那就是它，否则仍然为现在的max
		}
		if (summary<0)
		{
			summary = 0;
		}
	}
	cout << max << endl;
	return 0;
}
