#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// function to calculate the maximum beauty
long maxbeauty(vector<pair<int,int>> &v, int n){
    // so if i take a general case and i take two consecutive pairs
    // let them be a_i,b_i and a_j,b_j and let the length formed before them be x
    // so first case in which (i)th is next and after that (j)
    // sum1 = x*b_i + (x+a_i)*b_j
    // next case is (j)th is first and then (i)th
    // sum2 = x*b_j + (x+a_j)*b_i
    // and if i take the difference of sum1 and sum2
    // it is (a_i*b_j)-(a_j*b_i) which is independent of the value of x
    // so only the values of (a_i*b_j) and (a_j*b_i) is needed to diced whic is first and second
    // so i sort the vector in the increasing order by comparing (a_i*b_j) and (a_j*b_i)
    sort(v.begin(),v.end(),[](const pair<int,int> &a, const pair<int,int> &b){
        return 1LL * a.second * b.first < 1LL * b.second * a.first;
    });
    long sum = 0,len = 0;
    // then after i have the proper sorted vector that will give the maximum beauty
    // I calculate the value of maximum beauty
    for(int i=0;i<n;i++){
        sum += v[i].second*len;
        len += v[i].first;
    }
    // then return the maximum value of beauty that I calcukated
    return sum;
}

// I take the inputs and store the (i)th length and beauty as (i)th pair in a vector
// then I pass the vector along with its length to the function and do it (t) times
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i].first;
        }
        for(int i=0;i<n;i++){
            cin >> v[i].second;
        }
        cout << maxbeauty(v,n) <<endl;
    }
    return 0;
}