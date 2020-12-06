#include<bits/stdc++.h>
using namespace std;

bool vis[1000][1000];
int n,m;
struct node
{
    int x,y;
};
bool isvalid(int i,int j)
{
    if(i<n&&i>=0&&j<m&&j>=0)
    return true;
    return false;
}
void min_time(int **a)
{
    queue<node> q;
    //q.push(-1);
    int cnt=0;
    node p;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        if(a[i][j]==2)
        {
            p.x=i;p.y=j;
            q.push(p);
            vis[i][j]=true;
        }
    }
    node d;
    d.x=-1;
    d.y=-1;
    q.push(d);
    int count = 0;
    while(!q.empty())
    {
         node z=q.front();
         q.pop();
         if(z.x==-1&&z.y==-1)
         {
             if(q.empty())
             {
                 break;
             }
             else
             {
                 cnt++;
                 q.push(d);
             }
         }
         else
         {
             vis[z.x][z.y]=true;
             int i=z.x;int j=z.y;
             if(isvalid(i+1,j)&&a[i+1][j]&&!vis[i+1][j])
             {
                 p.x=i+1;p.y=j;
                 vis[i+1][j]=true;
                 q.push(p);
             }
             if(isvalid(i,j+1)&&a[i][j+1]&&!vis[i][j+1])
             {
                 p.x=i;p.y=j+1;
                 vis[i][j+1]=true;
                 q.push(p);
             }
             if(isvalid(i-1,j)&&a[i-1][j]&&!vis[i-1][j])
             {
                 p.x=i-1;p.y=j;
                 vis[i-1][j]=true;
                 q.push(p);
             }
             if(isvalid(i,j-1)&&a[i][j-1]&&!vis[i][j-1])
             {
                 p.x=i;p.y=j-1;
                 vis[i][j-1]=true;
                 q.push(p);
             }
         }
    }
    int count1= 0;
    int count0 = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]==false &&a[i][j]==1)
            count1++;
            if(a[i][j] == 0) count0++;
        }
    }
    cout<<"time frames : "<<cnt<<endl;
  	cout<<"fresh orange : "<<count1<<endl;
  	cout<<"rotten orange : "<<n*m - count1-count0<<endl;
    return;
}
int main()
 {

	cin>>n>>m;
    int **a; 
    a=new int*[n];
    for(int i=0;i<n;i++)
    	a[i]=new int[m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
   			cin>>a[i][j];
    memset(vis,false,sizeof(vis));
    min_time(a);

	return 0;
}
