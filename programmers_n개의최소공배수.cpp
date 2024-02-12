#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    sort(arr.begin(), arr.end(), greater<>());
    int idx = 0;
    while(1)
    {
        idx++;
        int num = arr[0]* idx;
        int cnt = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            if (num % arr[i] == 0)
                cnt++;
        }
        if (cnt == arr.size() -1)
        {
            return num;
        }
    
    }
    
    return answer;
}
