#include <iostream>
#include <set>
#include <map>

using namespace std;


long long int cowArr[100020];

int main()
{
    int N, K;
    cin >> N >> K;

    map<long long int, int> cows;
    int maxLength = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> cowArr[i];
    }

    int left = 0;
    int right = 0;

    while (cows.size() != K + 1 && right < N)
    {
        if (cows.find(cowArr[right]) == cows.end())
            cows[cowArr[right]] = 1;
        else
            cows[cowArr[right]]++;
        if (cows[cowArr[right]] > maxLength) maxLength = cows[cowArr[right]];
        right++;
    }

    while (right < N)
    {
        while (cows.size() != K + 2 && right < N)
        {
            if (cows.find(cowArr[right]) == cows.end())
                cows[cowArr[right]] = 1;
            else
                cows[cowArr[right]]++;
            if (cows[cowArr[right]] > maxLength) maxLength = cows[cowArr[right]];
            right++;
        }

        while (cows.size() != K + 1 && left < N)
        {
            cows[cowArr[left]]--;
            if (cows[cowArr[left]] == 0)
                cows.erase(cowArr[left]);
            left++;
        }

    }

    cout << maxLength << endl;
}