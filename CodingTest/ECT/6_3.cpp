// Sort >> p.180 성적이 낮은 순서대로 학생 출력하기

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
	string name;
	int score;

	bool operator < (const Student& val)
	{
		return score < val.score;
	}
};

int main()
{
	vector<Student> vecSt;
	stringstream ss;
	string buf;
	int n;
	cin >> n;
	cin.ignore();
	vecSt.reserve(n);

	for (int i = 0; i < n; ++i)
	{
		Student student;
		getline(cin, buf);

		ss.str(buf);
		ss >> student.name >> student.score;

		buf.clear();
		ss.clear();

		vecSt.push_back(student);
	}

	sort(vecSt.begin(), vecSt.end());

	for (int i = 0; i < n; ++i)
	{
		cout << vecSt[i].name << " ";
	}

	return 0;
}
