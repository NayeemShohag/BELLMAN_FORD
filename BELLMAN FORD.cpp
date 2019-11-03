
#include<stdio.h>
#include<algorithm>

using namespace std;
struct edge
{
    int s;
    int e;
    int w;
};
int a[10],set[10];
int n,e,d[100],s;
edge items[10];
int res;
int node1,node2,pa1,pa2,tot,j,total,temp;
char parent[100];





int main()
{
    int i,j;

    printf("nodes:");
    scanf("%d",&n);
    printf("edge:");
    scanf("%d",&e);
    printf("source:");
    scanf("%d",&s);

    for(i=0;i<e;i++)
    {
        scanf("%d",&items[i].s);
        scanf("%d",&items[i].e);
        scanf("%d",&items[i].w);
    }
   
    for(i=0;i<n;i++)
    {
        d[i]=9999;
    }

   
  

    d[s]=0;

    for(j=0;j<n-1;j++){
        for(i=0;i<e;i++)
        {
            node1=items[i].s;
            node2=items[i].e;
            if(d[node2]>d[node1]+items[i].w)
            {
                d[node2]=d[node1]+items[i].w;
                
            }

        }
    }
    int flag=0;
    for(i=0;i<e;i++)
        {
            node1=items[i].s;
            node2=items[i].e;
            if(d[node2]>d[node1]+items[i].w)
            {
                d[node2]=d[node1]+items[i].w;
               
                flag=1;
            }

        }

   

    if(flag==0)
        for(i=0;i<n;i++){
            printf("%d %d %d\n",s,i,d[i]);
        }
    else
            printf("cycle detected");

    return 0;
}
