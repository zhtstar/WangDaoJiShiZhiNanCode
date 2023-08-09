#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//习题3.4 奥运排序问题
//金牌总数 < 奖牌总数 < 金牌人口比例 < 奖牌人口比例 
struct Country {
	int id;
	int gold;
	int medal;
	float goldRate;
	float medalRate;
	int rank[4];
};

bool compareGold(Country x, Country y) {
	return x.gold > y.gold;
}
bool compareMedal(Country x, Country y){
	return x.medal > y.medal;
}
bool compareGoldRate(Country x, Country y){
	return x.goldRate > y.goldRate;
}
bool compareMedalRate(Country x, Country y){
	return x.medalRate > y.medalRate;
}

const int N = 10000;
Country arr[N];

int main()
{
	int N, M;
	vector<int> num;
	while (cin >> N >> M) { //国家数N，要求排名的国家数M, 国家号从0到N-1
		for (int i = 0; i < N; i++) { //N行给定国家或地区的奥运金牌数，奖牌数，人口数（百万）
			int gold, medal, people;
			cin >> gold >> medal >> people;
			arr[i].id = i;
			arr[i].gold = gold;
			arr[i].medal = medal;
			arr[i].goldRate = (double)gold / (double)people;
			arr[i].medalRate = (double)medal / (double)people;
		}
		//给出M个国家号
		for (int j = 0; j < M; j++) {
			int temp = 0;
			cin >> temp;
			num.push_back(temp);
		}
		for (int i = 0; i < 4; i++) {
			switch (i) {
			case 0:
				sort(arr, arr + N, compareGold);
				break;
			case 1:
				sort(arr, arr + N, compareMedal);
				break;
			case 2:
				sort(arr, arr + N, compareGoldRate);
				break;
			case 3:
				sort(arr, arr + N, compareMedalRate);
				break;
			}

			arr[0].rank[i] = 1;
			for (int j = 1; j < N; j++) {
				if (i == 0 && arr[j].gold == arr[j - 1].gold) {
					arr[j].rank[i] = arr[j - 1].rank[i];
				}
				else if (i == 1 && arr[j].medal == arr[j - 1].medal) {
					arr[j].rank[i] = arr[j - 1].rank[i];
				}
				else if (i == 2 && arr[j].goldRate == arr[j - 1].goldRate) {
					arr[j].rank[i] = arr[j - 1].rank[i];
				}
				else if (i == 3 && arr[j].medalRate == arr[j - 1].medalRate) {
					arr[j].rank[i] = arr[j - 1].rank[i];
				}
				else {
					arr[j].rank[i] = j + 1;
				}
			}
		}

		for (int j = 0; j < M; j++) {
			for (int i = 0; i < N; i++) {
				if (arr[i].id == num[j]) {
					int minRank = min(min(arr[i].rank[0], arr[i].rank[1]), min(arr[i].rank[2], arr[i].rank[3]));
					cout << minRank << ":";
					if (minRank == arr[i].rank[0]) {
						cout << 1 << endl;
					}
					else if (minRank == arr[i].rank[1]) {
						cout << 2 << endl;
					}
					else if (minRank == arr[i].rank[2]) {
						cout << 3 << endl;
					}
					else {
						cout << 4 << endl;
					}
					break;
				}
			}
		}
		cout << endl;
	}
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Country {
	int id;
	int gold;
	int total;
	double population;
	int rank[4];
};

// 自定义比较函数
bool compareGold(const Country& a, const Country& b) {
	return a.gold > b.gold;
}

bool compareTotal(const Country& a, const Country& b) {
	return a.total > b.total;
}

bool compareGoldPerCapita(const Country& a, const Country& b) {
	return (double)a.gold / a.population > (double)b.gold / b.population;
}

bool compareTotalPerCapita(const Country& a, const Country& b) {
	return (double)a.total / a.population > (double)b.total / b.population;
}

int main() {
	int N, M;
	while (cin >> N >> M) {
		vector<Country> countries(N);
		for (int i = 0; i < N; i++) {
			countries[i].id = i;
			cin >> countries[i].gold >> countries[i].total >> countries[i].population;
		}

		vector<int> query(M);
		for (int i = 0; i < M; i++) {
			cin >> query[i];
		}

		// 排序并计算排名
		for (int i = 0; i < 4; i++) {
			switch (i) {
			case 0: // 金牌总数
				sort(countries.begin(), countries.end(), compareGold);
				break;
			case 1: // 奖牌总数
				sort(countries.begin(), countries.end(), compareTotal);
				break;
			case 2: // 金牌人口比例
				sort(countries.begin(), countries.end(), compareGoldPerCapita);
				break;
			case 3: // 奖牌人口比例
				sort(countries.begin(), countries.end(), compareTotalPerCapita);
				break;
			}

			countries[0].rank[i] = 1;
			for (int j = 1; j < N; j++) {
				if (i == 0 && countries[j].gold == countries[j - 1].gold) {
					countries[j].rank[i] = countries[j - 1].rank[i];
				}
				else if (i == 1 && countries[j].total == countries[j - 1].total) {
					countries[j].rank[i] = countries[j - 1].rank[i];
				}
				else if (i == 2 && (double)countries[j].gold / countries[j].population == (double)countries[j - 1].gold / countries[j - 1].population) {
					countries[j].rank[i] = countries[j - 1].rank[i];
				}
				else if (i == 3 && (double)countries[j].total / countries[j].population == (double)countries[j - 1].total / countries[j - 1].population) {
					countries[j].rank[i] = countries[j - 1].rank[i];
				}
				else {
					countries[j].rank[i] = j + 1;
				}
			}
		}

		// 输出结果
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (countries[j].id == query[i]) {
					int minRank = min(min(countries[j].rank[0], countries[j].rank[1]), min(countries[j].rank[2], countries[j].rank[3]));
					cout << minRank << ":";
					if (minRank == countries[j].rank[0]) {
						cout << "1";
					}
					else if (minRank == countries[j].rank[1]) {
						cout << "2";
					}
					else if (minRank == countries[j].rank[2]) {
						cout << "3";
					}
					else {
						cout << "4";
					}
					cout << endl;
					break;
				}
			}
		}

		cout << endl; // 每组数据后加一个空行
	}

	return 0;
}*/


/*
//习题3.3 小白鼠排队
struct Mouse {
	int weight;
	string color;
};

bool compare(Mouse x, Mouse y) {
	return x.weight > y.weight;
}

const int N = 100;
Mouse arr[N];

int main()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr[i].weight >> arr[i].color;
	}
	sort(arr, arr + num, compare);
	for (int i = 0; i < num; i++) {
		cout << arr[i].color << endl;
	}

	return 0;
}*/

/*
//习题3.2 整数奇偶排序
int main()
{
	int arr[10];
	int temp, i=0, j=9;
	for (int k = 0; k < 10; k++) {
		cin >> temp;
		if (temp % 2 == 1) {//奇数
			arr[i] = temp;
			i++;
		}
		else {
			arr[j] = temp;
			j--;
		}
	}
	sort(arr, arr + i, greater<int>());
	sort(arr + i, arr + 10);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}*/


/*
//习题3.1 特殊排序
int main()
{
	int n;
	while (cin >> n) {
		vector<int> nums;
		for (int i = 0; i < n; i++) {
			int temp = 0;
			cin >> temp;
			nums.push_back(temp);
		}
		sort(nums.begin(), nums.end());
		cout << nums[n - 1] << endl;
		nums.pop_back();
		if (nums.size() == 0) {
			cout << -1 << endl;
			return 0;
		}
		for (int i = 0; i < nums.size(); i++) {
			cout << nums[i] << " ";
		}
		cout << endl;
	}

	return 0;
}*/

/*
//例题3.3 
struct Student {
	int num;
	string name;
	int score;
};

//降序
bool compare0(Student x, Student y) {
	if (x.score == y.score) {
		return x.num < y.num; //因为num始终要升序排列，这里要用小于号
	}
	else {
		return x.score > y.score; //因为score始终要升序排列，这里要用大于号
	}
}

//升序
bool compare1(Student x, Student y) {
	if (x.score == y.score) {
		return x.num < y.num; //因为num始终要升序排列，这里要用小于号
	}
	else {
		return x.score < y.score; //因为score始终要升序排列，这里要用小于号
	}
}
const int N = 10000;
Student arr[N];

int main()
{
	int num, method;
	while (cin >> num >> method) {
		for (int i = 0; i < num; i++) {
			arr[i].num = i;
			cin >> arr[i].name >> arr[i].score;
		}
		if (method == 0) {
			sort(arr, arr + num, compare0);
			for (int i = 0; i < num; i++) {
				cout << arr[i].name << " " << arr[i].score << endl;
			}
		}
		else {
			sort(arr, arr + num, compare1);
			for (int i = 0; i < num; i++) {
				cout << arr[i].name << " " << arr[i].score << endl;
			}
		}
	}


	return 0;
}*/


/*
//例题3.2 成绩排序
struct Student {
	int number;
	int score;
};

bool compare(Student x, Student y) {
	if (x.score == y.score) {
		return x.number < y.number;
	}
	else {
		return x.score < y.score;
	}
}

const int N = 100;
Student arr[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].number >> arr[i].score;
	}
	sort(arr, arr + n, compare);
	for (int i = 0; i < n; i++) {
		cout << arr[i].number << " " << arr[i].score << endl;
	}

	return 0;
}*/


/*
//例题3.1 排序
const int N = 100;
int main()
{
	int n = 0;
	cin >> n;
	int nums[N];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	sort(nums, nums+n);
	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;

	return 0;
}*/