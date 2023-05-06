#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1000000
using namespace std;
 
int dp[MAX];//存储最后背包最大能存多少
int value[MAX],weight[MAX],number[MAX];//分别存的是物品的价值，每一个的重量以及数量
int bag;
 
void ZeroOnePack(int weight,int value )//01背包
{
    int i;
    for(i = bag; i>=weight; i--)
    {
        dp[i] = max(dp[i],dp[i-weight]+value);
    }
}
void CompletePack(int weight,int value)//完全背包
{
    int i;
    for(i = weight; i<=bag; i++)
    {
        dp[i] = max(dp[i],dp[i-weight]+value);
    }
}
 
void MultiplePack(int weight,int value,int number)//多重背包
{
    if(bag<=number*weight)//如果总容量比这个物品的容量要小，那么这个物品可以直到取完，相当于完全背包
    {
        CompletePack(weight,value);
        return ;
    }
    else//否则就将多重背包转化为01背包
    {
        int k = 1;
        while(k<=number)
        {
            ZeroOnePack(k*weight,k*value);
            number = number-k;
            k = 2*k;//这里采用二进制思想（二进制与十进制的转化）(快速幂也是这个思路)
            //而不是一个一个的减 
        }
        ZeroOnePack(number*weight,number*value);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
         int n;
        while(~scanf("%d%d",&bag,&n))
        {
            int i,sum=0;
            for(i = 0; i<n; i++)
            {
                scanf("%d",&weight[i]); 
                
                scanf("%d",&value[i]);//输入价值  此题没有物品的重量，可以理解为体积和价值相等
                   scanf("%d",&number[i]);//输入数量
            }
            memset(dp,0,sizeof(dp));
            for(i = 0; i<n; i++)
            {
                MultiplePack(weight[i],value[i],number[i]);//调用多重背包,注意穿参的时候分别是
                //重量，价值和数量
            }
            cout<<dp[bag]<<endl;
        }
        return 0;    
    }  
}