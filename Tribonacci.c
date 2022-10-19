#include <stdio.h>  

// Globally declare the variables to check
// how many times a function is called.
int count1=0;
int count2=0;

// pure recursive function
int tri1(int x){

    // increment the count1 after each function call.
    count1++;
    if(x==0 || x==1 || x==2)
    return x;

    // call the recursive function
    return tri1(x-1) + tri1(x-2) + tri1(x-3);
}

// memoization with array called dp (dynamic programming)
int tri2(int x, int *dp){

    // increment the count2 after each function call.
    count2++;
    if(x==0 || x==1 || x==2)
    return dp[x]=x;

    // if this step has already has been calculated 
    // then return this step with calculating again.
    if(dp[x]!=-1)
    return dp[x];

    // stroe the called function into the dp array
    dp[x] = tri2(x-1,dp) + tri2(x-2,dp) + tri2(x-3,dp);
    return dp[x];
}
void check_tri(int x){

    // print how many times the function has been called.
    printf("Tri1 was called %d times.\nTri2 was called %d times.",count1,count2);
}
int main(){
    int n;
    scanf("%d",&n);

    // call the tri1 function.
    int ans1 = tri1(n);
    printf("Answer from tri1 : %d\n",ans1);

    // call the tri2 function.
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    int ans2 = tri2(n,dp);
    printf("Answer from tri 2 : %d\n",ans2);
    check_tri(n);
}
