#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool Less(int a, int b) {
	return a < b;
}
void Print(vector<int>v) {
	for (auto i : v) {
		cout << i << " ";
	}cout << endl;
}

void main() {
	vector<int>v = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int>v2{ 5,2,7,22,8,76 };
	Print(v);
	//delete element
	v.erase(v.begin());
	Print(v);
	//incert element

	v.insert(v.begin(), { 7,8,9,10 });
	Print(v);
	v.insert(v.begin(), v2.begin(), v2.end());
	Print(v2);
	sort(v2.begin(), v2.end(), Less);
	Print(v2);
	
}