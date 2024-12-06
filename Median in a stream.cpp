#include<queue>

int signum(int a, int b)
{
    if(a==b)
        return 0;
    if(a>b)
        return 1;
    else
        return -1;
}
void callMedian(int element,priority_queue<int,vector<int>,greater<int>> &mini,priority_queue<int> &maxi, int &median)
{
    switch(signum(maxi.size(),mini.size()) ){
            
        case 0:
            if(element>median)
            {
                mini.push(element);
                median  = mini.top();
            }
            else
            {
                maxi.push(element);
                median = maxi.top();
                
            }
            break;
            
        case 1:
            if(element>median)
            {
                mini.push(element);
                median = (maxi.top()+mini.top())/2;
            }
            else
            {
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(element);
                median = (maxi.top()+mini.top())/2;
            }
            break;
            
        case -1:
            if(element>median)
            {
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
                median = (maxi.top()+mini.top())/2;
            }
            else
            {
                maxi.push(element);
                median = (maxi.top()+mini.top())/2;
            }
            break;
    }

}

vector<int> findMedian(vector<int> &arr, int n)
{
	// Write your code here 
    vector<int> ans;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    priority_queue<int> maxHeap;
    int median = 0;
    for(int i=0;i<n;i++)
    {
         callMedian(arr[i],minHeap,maxHeap,median);
         ans.push_back(median);
    }
    return ans;
}
