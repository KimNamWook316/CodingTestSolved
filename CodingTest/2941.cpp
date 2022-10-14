#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> croatian = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int main()
{
    string input;
    cin >> input;

    for (int i = 0; i < croatian.size(); ++i)
    {
        while (true)
        {
            int index = input.find(croatian[i]);

            if (index == string::npos)
                break;

            input.replace(index, croatian[i].length(), "#");
        }
    }

    cout << input.length();

    return 0;
}