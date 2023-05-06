#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int v[110],w[110],ans[110],dp[110][110];
int main()
{
    int t,n,m,i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n); //m是经费，n种大米
        for(i=0;i<n;i++)
            scanf("%d%d%d",&w[i],&v[i],&ans[i]);//w价格，v是每袋的重量，ans是袋数
        memset(dp,0,sizeof(dp));  //初始化
        for(i=0;i<n;i++)   //n种大米
        {
            for(j=0;j<=m;j++)    //剩余j元最多能买多少
            {
                if(j<w[i])        //剩余的钱不能买这一袋
                    dp[i+1][j]=dp[i][j];
                else
                {
                    for(k=0;k<=ans[i]&&w[i]*k<=j;k++)   //这种大米，从买0袋开始尝试买多少
                       dp[i+1][j]=max(dp[i+1][j],dp[i][j-k*w[i]]+k*v[i]);
                       //             原本的花费        这种大米买k袋
                }
            }
        }
        printf("%d\n",dp[n][m]);
    }

}