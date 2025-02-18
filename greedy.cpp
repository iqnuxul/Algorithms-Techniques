#include <iostream>
#include <vector>

using namespace std;

int n;
int currency[6]={100,50,20,10,5,1};
vector<int> change;

int main(){
    cin>> n;

    int q=0;
    for(int i=0; i<6; i++){
        if(n>= currency[i]){
            int j= n/currency[i];
            n%= currency[i];
            while(j--){
                change.push_back(currency[i]);
                q+= 1;
            }
        }
    }

    cout << "The min number of coins needed is " << q << endl;

    for (int i = 0; i < change.size(); i++) {
        cout << change[i] << " ";
    }

    return 0;
}
