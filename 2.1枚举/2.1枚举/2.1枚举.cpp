#include<iostream>
#include<vector>
using namespace std;

//习题2.3 Old Bill
int main()
{
	int N = 0;
	int X, Y, Z;
	while (cin >> N) {
		cin >> X >> Y >> Z;
		int i, flag = 0;
		for (i = 9; i >= 1; i--) {
			for (int j = 9; j >= 0; j--) {
				int money = i * 10000 + X * 1000 + Y * 100 + Z * 10 + j;
				if (money % N == 0) {
					flag = 1;
					cout << i << " " << j << " " << money / N << endl;
					break;
				}
			}
			if (flag == 1) {
				break;
			}
		}
		if (flag == 0) {
			cout << 0 << endl;
		}
	}

	return 0;
}

/*
//习题2.2 百钱白鸡
int main()
{
	int n, x, y, z;
	cin >> n;
	for (x = 0; x <= n/5; x++) {
		for (y = 0; y <= n/3; y++) {
			for (z = 0; z <= n*3; z++) {
				if (5 * x + 3 * y + (float)z / 3 <= n && x + y + z == 100) {
					cout << "x=" << x << ",y=" << y << ",z=" << z << endl;
				}
			}
		}
	}

	return 0;
}*/


/*
//习题2.1 与7无关的数
bool WG(int num) {
	if (num % 7 == 0) {
		return true;
	}
	while (num != 0) {
		if (num % 10 == 7) {
			return true;
		}
		num /= 10;
	}
	return false;
}
int main()
{
	long res = 0;
	int n = 0;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		if (!WG(i)) {
			res += i * i;
		}
	}
	cout << res << endl;

	return 0;
}
*/


/*
//2.3 对称平方数1
bool dc(int num) {
	vector<int> nums;
	while (num!=0) {
		nums.push_back(num % 10);
		num /= 10;
	}
	for (int i = 0, j = nums.size() - 1; i < nums.size() / 2; i++, j--) {
		if (nums[i] != nums[j]) {
			return false;
		}
	}
	return true;
}

int main()
{
	for (int i = 0; i <= 256; i++) {
		if (i * i < 10) {
			cout << i << endl;
		}
		else {
			if (dc(i*i)) {
				cout << i << endl;
			}
		}
	}


	return 0;
}
*/


/*
//2.2反序数
int main()
{
	for (int a = 1; a <= 9; a++) {
		for (int b = 0; b <= 9; b++) {
			for (int c = 0; c <= 9; c++) {
				for (int d = 0; d <= 9; d++) {
					int num1 = a * 1000 + b * 100 + c * 10 + d;
					int num2 = d * 1000 + c * 100 + b * 10 + a;
					if (num1 * 9 == num2) {
						cout << num1 << endl;
					}
				}
			}
		}
	}
	return 0;
}
*/

/*
//2.1 abc abc+bcc = 532
int main()
{
	for (int a = 1; a <= 9; a++) {
		for (int b = 0; b <= 9; b++) {
			for (int c = 0; c <= 9; c++) {
				if (100 * a + 110 * b + 12 * c == 532) {
					cout << a << " " << b << " " << c << endl;
				}
			}
		}
	}

	return 0;
}
*/