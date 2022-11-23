#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
	string Name;
	int Korean;
	int English;
	int Math;
};

bool cmp (const Student& lhs, const Student& rhs)
{
	if (lhs.Korean == rhs.Korean)
	{
		if (lhs.English == rhs.English)
		{
			if (lhs.Math == rhs.Math)
			{
				if (lhs.Name == rhs.Name)
					return false;

				return lhs.Name < rhs.Name;
			}
			return lhs.Math > rhs.Math;
		}
		return lhs.English < rhs.English;
	}
	return lhs.Korean > rhs.Korean;
}

int main()
{
	vector<Student> s;
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string name;
		int korean, english, math;
		cin >> name >> korean >> english >> math;
		s.push_back({ name, korean, english, math });
	}

	sort(s.begin(), s.end(), cmp);

	for (const auto& e : s)
		cout << e.Name << "\n";

	return 0;
}