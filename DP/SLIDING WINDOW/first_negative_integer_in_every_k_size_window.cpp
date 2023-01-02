//RECURSIVE APPROACH
//TIME COMPLEXITY: O(NK)
//SPACE COMLEXITY: O(N)

#include<bits/stdc++.h>
using namespace std;

/*void  printFirstNegativeInteger(int arr[],int n,int k){
    for(int i = 0; i < (n-k+1); i++){
        bool flag = false;
        for(int j = 0; j < k; j++){
            if(arr[i+j] < 0){
                cout<<arr[i+j]<<endl;
                flag = true;
                break;
            }
        }
        if(!flag)
            cout<<"0";
    }
}*/
int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printFirstNegativeInteger(arr, n, k);
    return 0;
}




//BETTER APPROACH
//TIME COMPLEXITY: O(N)
//SPACE COMPLEXITY: O(K)

void printFirstNegativeInteger(int arr[], int n, int k){
    deque<int> D;
    
    for(int i = 0;i < k; i++){
        if(arr[i] < 0)
            D.push_back(i);
    }
    for(int i = k; i < n; i++){
        if(!D.empty())
            cout<<arr[D.front()];
        else
            cout<<"0";

        while((!D.empty()) && D.front() < i-k+1)
        {
            D.pop_front();
        }
        if(arr[i] < 0)
            D.push_back(i);
    }
    if (!D.empty())
           cout << arr[D.front()] << " ";
    else
        cout << "0" << " ";      
}
