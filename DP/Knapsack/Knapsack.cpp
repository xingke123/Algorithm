#include<iostream>
#include<algorithm>

#define Max_n 15

using namespace std;

int x[Max_n];  //记录背包最优解中是否有第i件物品，1表示有，0表示没有

int find_max_value(int w[],int v[],int n,int c)    //c表示背包容量，w表示每件物品的体积，v表示每件物品的价值，n表示一共有n件物品
{
    int Val[n+1][c+1];
    for(int i=0,j=0;j<=c;j++)
        Val[i][j]=0;
    for(int j=0,i=0;i<=n;i++)
        Val[i][j]=0;
    int i,j;
    for(i=1;i<=n;++i)
        for(j=1;j<=c;j++)
            {
                if(j<w[i-1])
                    Val[i][j]=Val[i-1][j];
                else
                    Val[i][j]=max(Val[i-1][j],Val[i-1][j-w[i-1]]+v[i-1]);
            }
    j=c;
    for(i=n;i>=1;i--)
    {
        if(Val[i][j]>Val[i-1][j])
            {
                x[i-1]=1;
                j=c-w[i-1];
            }
        else
                x[i-1]=0;
    }
    cout<<"选中的物品是：";
    for(i=0;i<n;++i)
        cout<<x[i]<<" ";
    cout<<endl;
    for(i=0;i<=n;++i)
        {
            for(j=0;j<=c;++j)
                cout<<Val[i][j]<<"\t";
            cout<<endl;
        }
    return Val[n][c];
}

int main()
{
    int n;
    int w[Max_n],v[Max_n];
    cout<<"请输入物品数量：";
    cin>>n;
    cout<<"请输入每件物品体积和价值：";
    for(int i=0;i<n;++i)
        cin>>w[i]>>v[i];
    int c=10;
    cout<<"背包所能容下物品的最大价值为："<<find_max_value(w,v,n,c)<<endl;
    return 0;
}
