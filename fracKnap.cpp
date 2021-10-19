// solving fractional knapsack problem 

#include<bits/stdc++.h>
using namespace std;

struct item
{
    int value, weight;
    // constructor
    item(int value, int weight)
    : value(value), weight(weight)
    {}
};

// comparison function to sort item a/c to val/weight ratio 
bool comp(struct item a, struct item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

//greedy approach
double fracknap(int W, struct item arr[], int n)
{
    // sort on basis of ratio 
    sort(arr, arr+n, comp);

    int curweight = 0;      //current weight in knapsack
    int finalvalue = 0.0;   //value from knapsack
    for(int i = 0;i<n;i++)
    {
        // if added item won't overflow, then add it completely
        if(curweight + arr[i].weight <=W)
        {
            curweight += arr[i].weight;
            finalvalue += arr[i].value;
        }
        else
        {
            int remain = W - curweight;
            finalvalue += arr[i].value * ((double)remain / (double)arr[i].weight);
            break;
        }
    }
    return finalvalue;
}

int main()
{
    int W = 50;     //weight in knapsack
    item arr[] = { {60,10}, {100,20}, {120,30} };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<fracknap(W, arr, n);

    return 0;
}