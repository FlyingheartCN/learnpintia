#include <iostream>
using namespace std;

int main() {
	int N, mnt, i;
	int Counts[51] = { 0 };
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> mnt;
		Counts[mnt]++;
	}
	for (i = 0; i < 52; i++) {
		if (Counts[i]!=0) {
			cout << i << ":" << Counts[i] << endl;
		}
	}
	return 0;
}
/*使用g++ 5.4.0一切正常
  不知道PTA那边什么情况
  请使用clang++提交*/
