#include <string>
#include <vector>
#include <map>
#include <iostream>


using namespace std;


map<string, int> lists;
map<string, int> tmps;

bool compareMaps()
{
    for (auto u: lists)
    {
        if (tmps.find(u.first) == tmps.end())
        {
            return false;
        }
        else if (tmps[u.first] != u.second)
            return false;
    }
    
    return true;
    
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for (int i = 0; i < want.size(); i++)
    {
        lists[want[i]] = number[i]; 
        //tmps[want[i]] = 0;
    }
    
    
    for (int i = 0; i <= discount.size() - 10; i++)
    {
       
        for (int j = i; j < i + 10; j++)
        {
            tmps[discount[j]]++;
        }
        if (compareMaps() == true)
            answer++;
        tmps.clear();
    }
    
    
    return answer;
}
