#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    //table de multiplication
    int i=0,j=1;
    for(i=1; i<11; i++)	{
        cout<<"Table de "<< i <<" : "<<endl;
        for(j=1;j<11;j++)	{
            cout<<i<<"*"<<j<<"="<<i*j<<endl;
        }
    }
    return 0;
}
