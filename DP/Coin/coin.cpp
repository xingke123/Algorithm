#include<iostream>

using namespace std;

void FindMin(int money,int * coin,int n)     //money是要找的总钱数，coin为可用零钱币值，n为coin数组大小
{
    int * sum=new int[money+1];
    sum[0]=0;
    int i,j;
    for(i=1;i<=money;++i)
    {
        int cn=i;
        for(j=0;j<n;++j)
        {
            if(i<coin[j])
                break;
            int tmp=sum[i-coin[j]]+1;
            if(tmp<cn)
                cn=tmp;
        }
        sum[i]=cn;
    }
    cout<<sum[money]<<endl;
    int lf=money;
    for(i=sum[money];i>0;--i)
    {
        //int cn=i;
        int index;
        for(j=0;j<n;++j)
        {
            if(lf<coin[j])
                break;
            if(sum[lf-coin[j]]+1==sum[lf])  //&&sum[lf-coin[j]]<cn
            {
                //cn=sum[lf];
                index=j;
                break;
            }
        }
        if(i!=1)
            cout<<coin[index]<<" + ";
        else
            cout<<coin[index];
        lf-=coin[index];
    }
    cout<<endl;
}

int main()
{
    int coin[7]={1,2,5,10,20,50,100};
    cout<<"请输入要找的总钱数："<<endl;
    int money;
    cin>>money;
    while(money)
    {
       FindMin(money,coin,7);
       cout<<"请输入要找的总钱数："<<endl;
       cin>>money;
    }
    return 0;
}
