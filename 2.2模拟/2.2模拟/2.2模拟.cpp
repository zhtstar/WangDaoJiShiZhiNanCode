#include<iostream>
#include <string>
#include<vector>
#include <iomanip>
#include<map>
#include <algorithm>
using namespace std;

//ϰ��2.11 ׹�������
struct ant {
	int pos;    //0-100
	int dir;    //-1, 0, 1
	bool flag;    //indicate ant A

	bool operator < (const ant& A) const {
		return pos < A.pos;
	}
};

vector<ant> vec;

void dump()
{
	for (auto c : vec)
		cout << "(" << ((c.flag) ? "*" : "") << c.pos << "," << c.dir << ") ";
	cout << endl;
}

void move()
{
	/* move */
	for (auto& a : vec) {
		if (a.dir == -1)
			a.pos -= 1;
		else if (a.dir == 1)
			a.pos += 1;
	}

	/* 3 ants meet */
	for (int i = 0; i < (int)(vec.size() - 2); i += 3) {
		if (vec[i].pos == vec[i + 1].pos && vec[i + 1].pos == vec[i + 2].pos)
			swap(vec[i].dir, vec[i + 2].dir);
	}

	/* 2 ants meet */
	for (int i = 0; i < (int)(vec.size() - 1); i++) {
		if (vec[i].pos > vec[i + 1].pos) {
			swap(vec[i].flag, vec[i + 1].flag);
			swap(vec[i], vec[i + 1]);
		}
	}

	/* drop */
	for (auto it = vec.begin(); it != vec.end(); ) {
		if (it->pos <= 0 || it->pos >= 100)
			it = vec.erase(it);
		else
			++it;
	}
}

bool isDrop()
{
	for (auto c : vec)
		if (c.flag)
			return false;
	return true;
}

int main()
{
	int n;

	while (cin >> n) {
		vec.clear();

		for (int i = 0; i < n; ++i) {
			ant a;
			a.flag = false;
			cin >> a.pos >> a.dir;
			if (a.dir == 0)
				a.flag = true;
			vec.push_back(a);
		}

		sort(vec.begin(), vec.end());

		int cnt = 0;
		while (!isDrop()) {
			if (vec.size() == 1 && vec[0].dir == 0)
				break;
			//dump();
			move();
			++cnt;
		}

		if (isDrop())
			cout << cnt << endl;
		else
			cout << "Cannot fall!" << endl;
	}

	return 0;
}


//ϰ��2.10 ·����ӡ
int main1()
{
	int n = 0;
	cin >> n;
	string s;
	while (n != 0) {
		cin >> s;
		int num = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] - 'a' >= 0 && s[i] - 'a' <= 25) {
				cout << s[i];
			}
			else {
				num++;
				cout << endl;
				for (int j = 0; j < num; j++) {
					cout << " ";
				}
			}
		}
		cout << endl;
	}

	return 0;
}


/*
//ϰ��2.9 Grading
int main()
{
	//P, T, G1, G2, G3, GJ
	//20 2 15 13 10 18
	float nums[6];
	float res = 0;
	for (int i = 0; i < 6; i++) {
		cin >> nums[i];
	}
	if (abs(nums[2] - nums[3]) <= nums[1]) {
		res = ((float)nums[2] + nums[3]) / 2;
		cout << fixed << setprecision(1) << res << endl;
		return 0;
	}
	if (abs(nums[2] - nums[4]) <= nums[1] && abs(nums[3] - nums[4]) <= nums[1]) {
		//res = max(nums[2], nums[3], nums[4]);
		res = max(max(nums[2], nums[3]), nums[4]);
	}
	else if (abs(nums[2] - nums[4]) > nums[1] && abs(nums[3] - nums[4]) > nums[1]) {
		res = nums[5];
	}
	else {
		res = abs(nums[2] - nums[4]) < abs(nums[3] - nums[4]) ? abs(nums[2] - nums[4]) / 2 : abs(nums[3] - nums[4]) / 2;
	}
	cout << fixed << setprecision(1) << res << endl;

	return 0;
}*/


/*
//����2.11 XXX����
int main()
{
	int n;
	while (cin >> n) {
		if (n == 1) {
			cout << 0 << endl;
			return 0;
		}
		int res = 0;
		while (n != 1) {
			if (n % 2 == 1) {
				n = (3 * n + 1) / 2;
				res += 1;
			}
			else {
				n = n / 2;
				res += 1;
			}
		}
		cout << res << endl;
	}

	return 0;
}*/


/*
//����2.10 �ֻ�����
int main()
{
	int nums[26] = { 1,2,3,1,2,3, 1,2,3, 1,2,3, 1,2,3, 1,2,3,4, 1,2,3,1,2,3,4 };
	string s;
	while (cin >> s) {
		int res = 0;
		//res = nums[s[0] - 'a'];
		//for (int i = 1; i < s.size(); i++) {
		//	//���ﲻ��Ҫ����ǰ��������Ҫ����ĸ��ͬ�������ҲҪ����ǰ��������ĸ��ͬ������ͬһ�������ϣ���ʱҲ��Ҫ�ȴ�
		//	if (s[i]-s[i - 1]==nums[s[i]-'a']-nums[s[i-1]-'a']) {
		//		res += nums[s[i] - 'a'];
		//		res += 2;
		//	}
		//	else {
		//		res += nums[s[i] - 'a'];
		//	}
		//}

		//����д����һЩ
		for (int i = 0; i < s.size(); i++) {
			res += nums[s[i] - 'a'];
			if (i != 0 && s[i] - s[i - 1] == nums[s[i] - 'a'] - nums[s[i - 1] - 'a']) {
				res += 2;
			}
		}
		cout << res << endl;
	}

	return 0;
}*/


/* �˽���ȷ����Ҳ˵����һ�㣬�´��������Ӽ������Ŀ����Ҫֱ�Ӿ�ȥ����ô���Ǹ�����������ǿ��Կ����ñ����ķ�ʽ������㡣�����ʼ��ÿһ����������Ϊ0�������Ҫ�Ƴ��͸�ֵΪ1������ѯ���ж��ٸ�0����
//����2.9 ʣ�µ���
const int N = 10000;
int main()
{
	int num, n;
	int nums[N];

	while (cin >> num >> n) {
		for (int i = 0; i < n; i++) {
			int left, right;
			cin >> left >> right;
			for (int i = left; i <= right; i++) {
				if (nums[i] == 0)
					nums[i] = 1;
			}
		}
		int res = 0;
		for (int i = 0; i <= num; i++) {
			if (nums[i] == 0) {
				res += 1;
			}
		}
		cout << res << endl;
	}

	return 0;
}*/


/*
* //����2.9 ʣ�µ��� �˽ⲻ��ȷ
const int N = 200;

int main()
{
	int num, n;
	int nums[N];
	while (cin >> num >> n) {
		for (int i = 0; i < n; i++) {
			cin >> nums[i*2] >> nums[i*2 + 1];
		}
		int res = 0;
		if(n>2)
			res = nums[1] - nums[0] + 1;
		for (int i = 2; i < n; i += 2) {
			if (nums[i] > nums[i - 1]) {//����ȫ�ڢٵ��ұ�
				res += (nums[i + 1] - nums[i] + 1);
			}
			if (nums[i] <= nums[i - 1] && nums[i+1] > nums[i - 1]) {//�ڲ���ȫ�ڢٵ��ұ�
				res += (nums[i + 1] - nums[i - 1]);
			}
			else if (nums[i+1] < nums[i - 2]) {//����ȫ�ڢٵ����
				res += (nums[i + 1] - nums[i] + 1);
			}
			else if (nums[i] < nums[i - 2] && nums[i + 1] >= nums[i - 2]) {//�ڲ���ȫ�ڢٵ����
				res += (nums[i - 2] - nums[i]);
			}
			else if (nums[i] >= nums[i - 2] && nums[i + 1] <= nums[i]) {

			}
			else {
				res -= (nums[i - 1] - nums[i - 2] + 1);
				res += (nums[i + 1] - nums[i] + 1);
			}
		}
		cout << num - res - 1 << endl;
	}


	return 0;
}*/

/*
//ϰ��2.8 ������
int isLearYear(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return 1;
	}
	return 0;
}

int main()
{
	int n, y, m, d;
	cin >> n;
	map<int, int> maps = { {1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };
	for (int i = 0; i < n; i++) {
		cin >> y >> m >> d;
		//��������һ
		d += 1;
		//���·ݴ���
		if (isLearYear(y) == 1 && m == 2) {
			if (d > (maps[m] + 1)) {//����Ҫע����߲������Ⱥ�˳�򣬷���d�����ֵ
				d -= (maps[m] + 1);
				m += 1;
			}
		}
		else {
			if (d > maps[m]) {//����Ҫע����߲������Ⱥ�˳�򣬷���d�����ֵ
				d -= maps[m];
				m += 1;
			}
		}
		//����ݴ���
		if (m > 12) {
			y += 1;
			m -= 12;
		}
		printf("%d-%02d-%02d\n", y, m, d);
	}

	return 0;
}*/


/*
//ϰ��2.7 Day of Week
// �������ڼ������ڼ�
string getDayOfWeek(int d, int m, int y) {
	static map<int, string> days = {{0, "Sunday"},{1, "Monday"},{2, "Tuesday"},{3, "Wednesday"},{4, "Thursday"},{5, "Friday"},{6, "Saturday"}};

	static map<string, int> months = {{"January", 1},{"February", 2},{"March", 3},{"April", 4},	{"May", 5},{"June", 6},{"July", 7},{"August", 8},{"September", 9},{"October", 10},{"November", 11},{"December", 12}};

	int a = (14 - m) / 12;
	y -= a;
	m = m + 12 * a - 2;
	int dayOfWeek = (d + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

	return days[dayOfWeek];
}

int main() {
	int d, y;
	string m;
	while (cin >> d >> m >> y) {
		int monthNumber = 0;
		//map<string, int> map2 = { {"January",1},{"February",2},{"March",3},{"April",4},{"May",5},{"June",6},{"July",7},{"August",8},{"September",9},{"October",10},{"November",11},{"December ",12} };
		//monthNumber = map2[m];
		if (m == "January") monthNumber = 1;
		else if (m == "February") monthNumber = 2;
		else if (m == "March") monthNumber = 3;
		else if (m == "April") monthNumber = 4;
		else if (m == "May") monthNumber = 5;
		else if (m == "June") monthNumber = 6;
		else if (m == "July") monthNumber = 7;
		else if (m == "August") monthNumber = 8;
		else if (m == "September") monthNumber = 9;
		else if (m == "October") monthNumber = 10;
		else if (m == "November") monthNumber = 11;
		else if (m == "December") monthNumber = 12;
		string dayOfWeek = getDayOfWeek(d, monthNumber, y);
		cout << dayOfWeek << endl;
	}
	return 0;
}*/



/*
//20 October 2036
int isLearYear(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return 1;
	}
	return 0;
}

int main()
{
	int d1, y1;
	string m1;
	//map<string, int> maps = { {"January",31},{"February",28},{"March",31},{"April",30},{"May",31},{"June",30},{"July",31},{"August",31},{"September",30},{"October",31},{"November",30},{"December ",31}};
	map<int, int> maps = { {1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };
	map<int, string> map1 = { {1,"Monday"},{2,"Tuesday"},{3,"Wednesday"},{4,"Thursday"},{5,"Friday"},{6,"Saturday"},{0,"Sunday"} };
	map<string, int> map2 = { {"January",1},{"February",2},{"March",3},{"April",4},{"May",5},{"June",6},{"July",7},{"August",8},{"September",9},{"October",10},{"November",11},{"December ",12} };
	int point = 0;
	for (int i = 1; i < 1000; i++) {
		if (isLearYear(i) == 1) {
			point += 366;
		}
		else {
			point += 365;
		}
	}

	while (cin >> d1 >> m1 >> y1) {
		int res = point;
		for (int i = 1000; i < y1; i++) {
			if (isLearYear(i) == 1) {
				res += 366;
			}
			else {
				res += 365;
			}
		}
		for (int i = 1; i < map2[m1]; i++) {
			if (isLearYear(y1) == 1 && i == 2) {
				res += (maps[i]+1);
			}
			else {
				res += maps[i];
			}
		}
		res += d1;

		cout << map1[res % 7] << endl;
	}
	
	return 0;
}*/

/*
//ϰ��2.6 ���ڲ�ֵ
int isLearYear(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return 1;
	}
	return 0;
}

int main()
{
	//20110412
	//20110422
	int a, b;
	cin >> a >> b;
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	map<int, int> maps = { {1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };
	int y1 = a / 10000, m1 = (a % 10000) / 100, d1 = (a % 10000) % 100;
	int y2 = b / 10000, m2 = (b % 10000) / 100, d2 = (b % 10000) % 100;

	int res1 = 0, res2 = 0;
	//�����С����������һ��ĵڼ���
	for (int i = 1; i < m1; i++) {
		if (isLearYear(y1) == 1 && i == 2) {
			res1 += (maps[i]+1);
		}
		else {
			res1 += maps[i];
		}
	}
	res1 += d1;

	//�ȼ���ϴ�����������ݵ�����
	for (int i = y1; i < y2; i++) {
		if (isLearYear(i) == 1) {
			res2 += 366;
		}
		else {
			res2 += 365;
		}
	}

	for (int i = 1; i < m2; i++) {
		if (isLearYear(y2) == 1 && i == 2) {
			res2 += (maps[i] + 1);
		}
		else {
			res2 += maps[i];
		}
	}
	res2 += d2;

	cout << abs(res2 - res1) + 1 << endl;

	return 0;
}*/


/*
//����2.8 �����ۼ�
int isLearYear(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return 1;
	}
	return 0;
}
int main()
{
	int n;
	cin >> n;
	int y, m, d, num;
	map<int, int> maps = { {1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };
	for (int i = 0; i < n; i++) {
		cin >> y >> m >> d >> num;
		num += d;
		d = 0;
		while (num >= 365) {
			if (isLearYear(y + 1) == 1 && num >= 366) {
				y += 1;
				num -= 366;
			}
			if (isLearYear(y + 1) == 0 && num >= 365) {
				y += 1;
				num -= 365;
			}
		}
		int k = 0;
		for (k = m; k <= 12; k++) {
			if (isLearYear(y) == 1 && k == 2 && num >= 29) {
				num -= (maps[k] + 1);
			}
			else if (num >= maps[k]) {
				num -= maps[k];
			}
			else {
				break;
			}
			if (k == 12 && num > 0) {
				k = 0;
				y += 1;
			}
		}
		if (num == 0) {
			printf("%d-%02d-%02d\n", y, k-1, maps[k-1]);
		}
		else {
			printf("%d-%02d-%02d\n", y, k, num);
		}
	}

	return 0;
}*/


/*
//����2.7 ��ӡ����
int isLearYear(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return 1;
	}
	return 0;
}

int main()
{
	int y, n, res1, res2;
	map<int, int> maps = { {1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };
	while (cin >> y >> n) {
		int i = 0, temp = 0;
		for (i = 1; i <= 12; i++) {
			if (temp >= n) {
				break;
			}
			if (i == 2 && isLearYear(y) == 1) {
				temp += (maps[i] + 1);
			}
			else {
				temp += maps[i];
			}
		}
		int d = i == 3 && isLearYear(y)==1 ? n - (temp - maps[i - 1] - 1) : n - (temp - maps[i - 1]);
		
		printf("%d-%02d-%02d\n", y, i - 1, d);
	}

	return 0;
}*/



/*
//����2.6 ����ĵڼ���
int isLearYear(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return 1;
	}
	return 0;
}

int main()
{
	int y, m, d;
	map<int, int> maps = { {1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};
	while (cin >> y >> m >> d) {
		int res = 0;
		for (int i = 1; i < m; i++) {
			if (i == 2 && isLearYear(y)==1) {
				res += (maps[i] + 1);
			}
			else {
				res += maps[i];
			}
		}
		res += d;
		cout << res << endl;
	}

	return 0;
}*/

/*
//ϰ��2.5 Hello World for U
int main()
{
	//n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N } with n1 + n2 + n3 - 2 = N.
	string s;
	while (cin >> s) {
		int N = s.size();
		//cout << N << endl;
		int n1, n2, n3, flag=0;
		for (int n = 3; n <= N; n++) {
			for (int k = n; k >= 0; k--) {
				if (2 * k + n - 2 == N) {
					n1 = n3 = k;
					n2 = n;
					flag = 1;
					break;
				}
			}
			if (flag == 1) {
				break;
			}
		}
		//cout << n1 << " " << n2 << " " << n3 << endl;
		for (int i = 0, j = N - 1; i < n1-1; i++, j--) {
			cout << s[i];
			for (int j = 0; j < n2 - 2; j++) {
				cout << " ";
			}
			cout << s[j] << endl;
		}
		for (int k = n1 - 1; k < n1 - 1 + n2; k++) {
			cout << s[k];
		}
		cout << endl;
	}
}
*/

//ϰ��2.4 Repeater


/*
//����2.5 ����
int main()
{
	char arr[80][80];
	int num = 0;
	char a, b;
	while (cin >> num >> a >> b) {
		for (int i = 0; i <= num / 2; i++) {
			int j = num - i - 1;
			int len = num - i * 2;
			char c;
			if ((num/2-i) % 2 == 0) {
				c = a;
			}
			else {
				c = b;
			}
			for (int k = 0; k < len; k++) {
				arr[i][k + i] = c;
				arr[k + i][i] = c;
				arr[j][j - k] = c;
				arr[j - k][j] = c;
			}
		}
		if (num != 1) {
			arr[0][0] = ' ';
			arr[0][num - 1] = ' ';
			arr[num - 1][0] = ' ';
			arr[num - 1][num - 1] = ' ';
		}
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				cout << arr[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}
*/


/*
//����2.4 �������
int main()
{
	int h = 0;
	cin >> h;
	int len = h + 2 * (h - 1);
	for (int i = 0; i < h; i++) {
		int b = h + 2 * i;
		int a = len - b;
		for(int j = 0; j < a; j++) {
			cout << " ";
		}
		for (int k = 0; k < b; k++) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}*/