#include <string>
#include <stack>
#include <iostream>
#include <vector>

using namespace std;

bool IsPPAP(const std::string& input)
{
    if (input == "P")
        return true;

    stack<char> stk;
    string ppap;

    bool check = false;
    for (int i = 0; i < input.length(); ++i)
    {
		stk.push(input[i]);

        if (!check && stk.size() >= 4)
        {
            for (int j = 0; j < 4; ++j)
            {
                ppap += stk.top();
                stk.pop();
            }

            if (ppap == "PAPP")
            {
                stk.push('P');
            }
            else
            {
                for (int j = 3; j >= 0; --j)
                {
                    stk.push(ppap[j]);
                }
            }
			ppap = "";
        }
        else
        {
            check = false;
        }
    }

    if (stk.size() == 1 && stk.top() == 'P')
        return true;
    else
        return false;
}

int main()
{
    string input;
    cin >> input;

    bool ans = IsPPAP(input);

    if (ans)
        cout << "PPAP";
    else
        cout << "NP";
}