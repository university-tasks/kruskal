#include <iostream>
#include <string>

using namespace std;

int nValidator() {

int n;
bool isBiggerThan100_000 = true;

while (isBiggerThan100_000) {
        cout << "Enter the number of vertices: ";
        cin >> n;

        if (n < 100001 and n > 0) {
            isBiggerThan100_000 = false;
        } else if (n > 100001) {
            cout << "The number of vertices must be less than 100 001\n";
        } else {
            cout << "The number of vertices must be bigger than 0\n";
        }
    }
    return n;
}

bool YesNotValidator(string question){
    int answer = 0;
    while (true) {
        cout << question << "\n1) Yes\n2) No\n";
        cin >> answer;

        if (answer == 1) return true;
        if (answer == 2) return false;
        cout << "The input is not valid\n\n";
    }
}
