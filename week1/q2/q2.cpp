#include <iostream>
#include <vector>
using namespace std;

// function to find the minimum number of visisble box
int minbox(vector<vector<int>> &m, int n){
    // first I sort the the vector according to the decreasing order of size
    // so for that I basically sort the columns according to the first element of each column in decreasing order
    sort(m.begin(),m.end(),[](const vector<int> &a,const vector<int> &b){
        return a[0] > b[0];
    });
    // so I start from i=0, the largest box
    // second loop starts from the elment next to the first loop, that is j=i+1
    // my plan is to keep inserting smaller boxes to the end of each column containing the larger box
    // so I check if the last element of (i)th column is greater than the fisrt element of the (j)th column
    // if it is true, then I add all the elements of (j)th column to the end of the (i)th column
    // then I erase the (j)th column
    // then I decrease the value of n by 1 as 1 column was removed
    // then i also move the iterator j back by 1 as, when I removed the (j)th column before,
    // the (j+1)th column becomes the (j)th column
    // so i again have to check the (j)th column
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(m[i].back()>m[j][0]){
                m[i].insert(m[i].end(),m[j].begin(),m[j].end());
                m.erase(m.begin()+j);
                n--;
                j--;
            }
        }
    }
    // after I am done with the whole loop, the number of columns of the 2D vector will represent the number of visible boxes
    // so i return the number of columns of the 2D vector
    return m.size();
}

// so I take the input in a 2D vector with n rows and 1 column
// so first element of each row will be the size of the box
// then i pass the 2D vector into the function along with its length
int main(){
    int n;
    cin >> n;
    vector<vector<int>> m(n,vector<int>(1));
    for(int i=0;i<n;i++){
        cin >> m[i][0];
    }
    cout << minbox(m,n) << endl;
    return 0;
}