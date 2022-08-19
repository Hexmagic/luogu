#include <stdlib.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    int k;
    cin>>k;
    int i=1,ans=0;
    while(true){
        ans+=1.0/i;
        if(ans>=k)
            cout<<i;
        i++;
    }
    return 0;
}