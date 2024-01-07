#include <bits/stdc++.h>
using namespace std;

vector<int> answerVec;
vector<int> numbers;
int answer;

void go(int cnt) {
    if(numbers.size() == 10) {
        if(cnt >= 5) answer ++;
        return;
    }
    for(int i=1;i<=5;i++) {
        int nextScore = cnt;
        if(numbers.size() > 1) {
            if(numbers[numbers.size()-1] == i && numbers[numbers.size()-2] == i) continue;
        } 
        numbers.push_back(i);
        if(answerVec[numbers.size()-1] == i) nextScore++;
        go(nextScore);
        numbers.pop_back(   );

    }
}

int main() {
    for(int i=0;i<10;i++) {
        int num; cin >> num;
        answerVec.push_back(num);
    }
    vector<int> empty;
    go(0);
    cout << answer;
}