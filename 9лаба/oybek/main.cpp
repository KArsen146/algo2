#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Top {
private:
    int amountInputs;
    vector<int> ribs;
public:
    Top() {
        amountInputs = 0;
    }

    void upAmountInputs() {
        amountInputs++;
    }

    void push(int top) {
        ribs.push_back(top);
    }

    void reduceAmountInputs() {
        amountInputs--;
    }

    int getAmountInputs() {
        return amountInputs;
    }

    vector<int> getRibs() {
        return ribs;
    }
};

bool isRiber(Top tops[], int x) {
    vector<int> a = tops[x].getRibs();
    for (int i = 0; i < a.size(); i++) {
        vector<int> b = tops[a[i]].getRibs();
        for (int j = 0; j < b.size(); j++) {
            if (b[j] == i) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    freopen("hamiltonian.in", "r", stdin);
    freopen("hamiltonian.out", "w", stdout);
    int v, e;
    cin >> v >> e;
    Top tops[v];
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        tops[--x].push(--y);
        tops[y].upAmountInputs();
    }

    queue<int> topWOinputs;
    for (int i = 0; i < v; i++) {
        int num = tops[i].getAmountInputs();
        if (!num) {
            topWOinputs.push(i);
        }
    }
    vector<int> answer;
    for (int i = 0; i < v; i++) {
        if (topWOinputs.empty()) {
            cout << "-1";
            return 0;
        }
        int num = topWOinputs.front();
        topWOinputs.pop();
        vector<int> del = tops[num].getRibs();
        for (int j = 0; j < del.size(); j++) {
            tops[del[j]].reduceAmountInputs();
            int numTop = tops[del[j]].getAmountInputs();
            if (!numTop) {
                topWOinputs.push(del[j]);
            }
        }
        answer.push_back(num + 1);
    }
//    reverse(answer.begin(), answer.end());
    for (int i = 0; i < answer.size() - 1; i++){
        int tmp = answer[i];
        vector<int> a = tops[tmp].getRibs();
        bool ham = false;
        for (int j = 0; j < a.size(); j++){
            if (a[j] == i + 1){
                ham = true;
            }
        }
        if (!ham){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}