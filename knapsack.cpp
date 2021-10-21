#include <bits/stdc++.h>
using namespace std;


/*
input format

first line: C n //C is the capacity
new n lines: w p //w is the weight, and p is the profit

*/

int C, n;
int* weights;
int* profits;
int* curMax;

void printArray(){
    for(int i = 0; i <= C; i++){
        printf("%d ", curMax[i]);
    }
    printf("\n");
}


int getMaxProfit(){
    curMax = new int[C+1];
    int i = 0;
    int j = 0;

    //initialize the array with the first element;
    for(;j < C && j < weights[i]; j++){
        curMax[j] = 0;
    }

    for(;j <= C; j++){
        curMax[j] = max(curMax[j - weights[i]] + profits[i], curMax[j - 1]);
    }
    
    printArray();
    i++;
   for(; i < n; i++){
        int w = weights[i];
        int p = profits[i];

        j = w;
        for(;j <= C; j++){
            curMax[j] = max(curMax[j - weights[i]] + profits[i], max(curMax[j - 1], curMax[j]));
        }
        printArray();
    }

    return curMax[C];
}



int main(){

    scanf("%d %d", &C,&n);

    weights = new int[n];
    profits = new int[n];

    for(int i = 0; i < n; i++){
        int w, p;
        scanf("%d %d", &w, &p);
        weights[i] = w;
        profits[i] = p;
    }

    printf("The maximum profit is %d.", getMaxProfit());



    return 0;
}