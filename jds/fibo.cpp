#include <iostream>
using namespace std;

int fibonacci(int num);
int count1 = 0;
int count2 = 0;
int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int num = 0;
	int input = 0;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> input;
		fibonacci(input);
		cout << count1 << ' ' << count2 << endl;
		count1 = 0; count2 = 0;
	}

	return 0;
}

int fibonacci(int n) {
	if (n == 0) {
		count1++;
		return 0;
	}
	if (n == 1) {
		count2++;
		return 1;
	}

	return fibonacci(n - 1) + fibonacci(n - 2);
}
