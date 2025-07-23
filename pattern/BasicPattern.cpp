/*
Pattern 
     
    n=3

    1 2 3 
    1 2 3 
    1 2 3 

*/
#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"enter the number "<<endl;
    cin>>n;
    int i=1;
    // Loop To Rotate over Number of Rows.
    while(i<=n){
        int j=1;
        // Loop To Rotate over Number of Columns.
        while(j<=n){
            // Calculation
            cout<<j<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }

    return 0;
}



/*
Pattern 

    n=3

    3 2 1 
    3 2 1 
    3 2 1 

*/
#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"enter the number "<<endl;
    cin>>n;
    int i=1;
    // Loop To Rotate over Number of Rows.
    while(i<=n){
        int j=1;
        // Loop To Rotate over Number of Columns.
        while(j<=n){
            // Calculation
            cout<<n-j+1<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }

    return 0;
}


/*
Pattern 

    n=3

    1 2 3 
    4 5 6 
    7 8 9 

*/
#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"enter the number "<<endl;
    cin>>n;
    int i=1,counter=1;
    // Loop To Rotate over Number of Rows.
    while(i<=n){
        int j=1;
        // Loop To Rotate over Number of Columns.
        while(j<=n){
            // Calculation
            cout<<counter<<" ";
            counter++;
            j++;
        }
        cout<<endl;
        i++;
    }

    return 0;
}
