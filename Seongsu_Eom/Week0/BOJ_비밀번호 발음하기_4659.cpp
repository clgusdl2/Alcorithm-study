#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_set>

using namespace std;

int main()
{
    string a;
    unordered_set<char> b = { 'a', 'e', 'i', 'o', 'u' };

    while (1) {
        cin >> a;
        if (a == "end") {
            break;
        }

        int check1 = 0;
        int check2 = 0;
        int wordcheck = -1;
        char word = '0';
        int check3 = 0;
        int check = 0;

        for (char i : a) {
            if (b.find(i) != b.end()) {
                check1 = 1;
                if (wordcheck == 1) {
                    check2++;
                }
                else {
                    wordcheck = 1;
                    check2 = 1;
                }
            }
            else {
                if (wordcheck == 0) {
                    check2++;
                }
                else {
                    wordcheck = 0;
                    check2 = 1;
                }
            }
            if (check2 == 3) {
                check = 1;
                break;
            }

            if (word == i) {
                check3++;
            }
            else {
                word = i;
                check3 = 1;
            }
            if (check3 == 2 && word != 'e' && word != 'o') {
                check = 1;
                break;
            }
        }
        if (check1 == 0) {
            check = 1;
        }
        else {
            check1 = 0;
        }
        if (check == 1) {
            cout << "<" << a << "> is not acceptable." << endl;
            check = 0;
        }
        else {
            cout << "<" << a << "> is acceptable." << endl;
        }
    }


    return 0;
}