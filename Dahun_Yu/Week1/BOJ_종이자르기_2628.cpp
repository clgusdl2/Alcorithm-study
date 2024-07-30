#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){

    int g,s;
    cin >> g >> s;

    int n;
    cin >> n;

    vector<int> garoo ={0,s};
    vector<int> seroo = {0,g};

    for(int i=0;i<n;i++){
        int key,cut;
        cin >> key >> cut;
        if(key==0) garoo.push_back(cut);
        if(key==1) seroo.push_back(cut); 
    }

    sort(garoo.begin(),garoo.end());
    sort(seroo.begin(),seroo.end());

    int max_size = 0;
    for(int i=0; i<garoo.size()-1;i++){
        for(int j=0;j<seroo.size()-1;j++){
            int now = (garoo[i+1]-garoo[i])*(seroo[j+1]-seroo[j]);
            //cout << garoo[i+1]-garoo[i] << "*" <<seroo[j+1]-seroo[j] << "///"<< now << "i=" << i <<"j="<< j << endl;
            if(now > max_size){
                max_size = now;
            }
        }
    }
    
    cout << max_size;

    return 0;
}