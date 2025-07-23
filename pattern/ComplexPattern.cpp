/*
         Pattern 

        1234554321
        1234**4321
        123****321
        12******21
        1********1
*/
#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"enter the number "<<endl;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
          if(j<=n+1-i){
              cout<<j;
          }
          else{
              cout<<"*";
          }
            j++;
        }
        int k=n;
        while(k>=1){
            if(k>n+1-i){
                cout<<"*";
            }
            else{
                cout<<k;
            }
            k--;
        }
        
        cout<<endl;
        i++;
    }

    return 0;
}