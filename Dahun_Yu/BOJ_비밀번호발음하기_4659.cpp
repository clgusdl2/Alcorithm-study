#include <iostream>
#include <string>
using namespace std;

string password;

int main() {
	while (1) {
		cin >> password;
		if (password == "end") break;

		string answer = " is not acceptable.";
		int flag[3];
		//모음포함?
		flag[0] = 0;
		for (auto c : password) {
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				flag[0] = 1;
				break;
			}
		}
		//자음 3개 연속?
		flag[1] = 1;
		int count_ja = 0;
		int count_mo = 0;
		for (auto c : password) {
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				count_ja++;
				count_mo = 0;
			}
			else {
				count_mo++;
				count_ja = 0;
			}

			if (count_ja >= 3 || count_mo >= 3) {
				flag[1] = 0;
				break;
			}
		}

		//같은문자 연속
		flag[2] = 1;
		char previous = '?';
		for (auto c : password) {
			if (previous == c && !(c =='e' || c =='o') ){
				flag[2] = 0;
				break;
			}
			previous = c;
		}


		if (flag[0] && flag[1] && flag[2]) answer = " is acceptable.";
		cout << "<" << password << ">" << answer << endl;
	}
	return 0;
}