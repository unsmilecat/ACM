#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define Inf 99999999
int matrix[85][85][85],vec[85][85],map[85][85];
bool cmp(int b,int m)
{
    int i;
    for(i=1;i<=m;i++)
        if(vec[0][i]!=vec[b][i])
            return false;
    return true;
}
void mul(int a,int b,int n,int m)
{
    int i,j,k,s;
    for(i=1;i<=m;i++)
    {
        vec[0][i]=0;
        for(j=1;j<=m;j++)
            vec[0][i]+=matrix[a][i][j]*vec[b][j];
    }
    for(i=1;i<=n;i++)
        if(i==a||i==b)
            continue;
        else if(cmp(i,m))
            map[a][i]=1;
}
void floyd(int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
}
int main()
{
    int i,j,k,m,n,a,b;
    while(~scanf("%d%d",&n,&m),m+n)
    {
        memset(matrix,0,sizeof(matrix));
        memset(vec,0,sizeof(vec));
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i==j)
                    map[i][j]=0;
                else
                    map[i][j]=Inf;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                for(k=1;k<=m;k++)
                    scanf("%d",&matrix[i][j][k]);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                for(k=1;k<=m;k++)
                    vec[i][j]+=matrix[i][j][k]*k;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i==j)
                    continue;
                else 
                    mul(i,j,n,m);    
        floyd(n);
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d%d",&a,&b);
            if(map[a][b]==Inf)
                printf("Sorry\n");
            else
                printf("%d\n",map[a][b]);
        }
    }
    return 0;
}
