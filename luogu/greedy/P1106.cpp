#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    vector<string> temp;
    for(int i=0;i<k;i++){
        for(int i=0;i<s.length();i++){
            temp.push_back(s.substr(0,i-0)+s.substr(i+1,s.length()-i));
        }
        sort(temp.begin(),temp.end());
        s=temp[0];
    }
    cout<<stoi(s)<<endl;
    return 0;
}