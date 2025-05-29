#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// this is the code to return 1 if it is possible to sort in non-decreasing aorder with everyone's direction as right
// else it returns 0
int aquasort(vector<int> &v, int n){
    // first I create two vectors
    // v1 to store the once at i = 0,2,4,.....
    // v2 to store the once at i = 1,3,5,.....
    // the logic to do so is that if I need anyone to be right, I need to make even number of swaps
    // even swaps imply that odd position person remains at odd position and even postion person remains at even
    vector <int> v1((n+1)/2),v2(n/2);
    // so to make sure that odd and even position dont mix, I seperate them and store in v1 and v2
    for(int i=0;i<n;i++){
        if(i%2==0){
            v1[i/2] = v[i];
        }
        else{
            v2[(i-1)/2] = v[i];
        }
    }
    // then I sort the vectors v1 and v2 seperately
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    // then i combine v1 and v2 to a single vector v1
    // so by now i have made sure that everyone remains right
    for(int i=0;i<n;i++){
        if(i%2==0){
            v[i] = v1[i/2];
        }
        else{
            v[i] = v2[(i-1)/2];
        }
    }
    // now the only condition left to check is if the arrangement is non-decreasing
    // so i check that and if it is not, I return 0
    for(int i=0;i<n-1;i++){
        if(v[i]>v[i+1]){
            return 0;
        }
    }
    // if it is non-decreasing, I return 1
    return 1;
}

// I take the input and store the number on t-shirt
// then I pass the vector along with its lenght to the function
// then according to the output of the function i print yes or no
// I run this (t) times
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int j=0;j<n;j++){
            cin >> v[j];
        }
        if(aquasort(v,n)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}