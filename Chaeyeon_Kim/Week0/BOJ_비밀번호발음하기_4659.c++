#include <iostream>
#include <string>

using namespace std;

string vowel = "aieou";

int main()
{
    while (true)
    {
        string in_str;
        getline(cin, in_str);
        int seq_count1 = 0;
        int seq_count2 = 0;
        int vowel_count = 0;
        int nope = 0;

        if (in_str.compare("end") == 0)
        {
            break;
        }

        for (int i = 0; i < in_str.length(); i++)
        {
            if(seq_count2 >= 3 or seq_count1 >= 3){
                nope ++;
                break;
            }

            if(vowel.find(in_str[i]) >= 0 and vowel.find(in_str[i])<= 4){ //모음
                vowel_count ++;
                if(seq_count1 == 0){ //모음이 처음
                    seq_count2 = 0;
                }
                seq_count1 ++;
            }else{ //자음
                if(seq_count2 == 0){
                    seq_count1 = 0;
                }
                seq_count2 ++;
            }

            if(i > 0){
                if(in_str[i-1] == in_str[i]){
                    if(in_str[i] != 'o' and in_str[i] != 'e'){
                        nope ++;
                        break;
                    }
                }
            }
        }
        // cout << vowel_count << seq_count1 << seq_count2 << nope;
        if(vowel_count >= 1 and seq_count1 < 3 and seq_count2 <3 and nope == 0){
            cout << "<" << in_str << "> " << "is acceptable." << endl;
        }else{
            cout << "<" << in_str << "> " << "is not acceptable." << endl;
        }
    }
}