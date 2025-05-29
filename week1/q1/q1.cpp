#include <iostream>
#include <vector>
using namespace std;
//function to calculate the number of subarray
int subarray(const vector <int> &v,int n,int x){
    int count = 0,sum=0,k=0;
    // I am running a loop and when ever the sum is equal to the target sum, i do count++
    for(int i=0;i<n;i++){
        // so for i=0, I am incrementing j till the sum is equal to or less than the target sum
        if(i==0){
            for(int j=0;j<n;j++){
                if(sum+v[j]<=x){
                    sum += v[j];
                    k++;
                    if(sum==x){
                        count++;
                    }
                }
                else{
                  break;
                }
            }
        }
        // other than i=0, to get the sum, first i would remove the previous value from the sum
        // that is I remove v[i-1] from the sum
        // then i keep incrementing sum again from the point i was incrementing in the last iteration
        // like I continue from the point till I took the value of j in the (i-1)th iteration
        // then I again stop the increment when sum is less than or equal to the target sum
        else{
            sum -= v[i-1];
            for(int j=k;j<n;j++){
                if(sum+v[j]<=x){
                    sum += v[j];
                    k++;
                    if(sum==x){
                        count++;
                    }
                }
                else{
                  break;
                }
            }
        }
    }
    // finally I get the total number of subarrays and return the value
    return count;
}
// take input and pass the vector along with its lenght and target sum to the function
int main() {
    int n,x;
    cin >> n >> x;
    vector <int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    cout << subarray(v,n,x) << endl;
    return 0;
}