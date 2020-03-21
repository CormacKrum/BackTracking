#include<iostream>
using namespace std;
void printSolution(int *path,int n)
{
    cout<<"\nThe Hamilton Path of Graph is:\n";
    for(int i=0;i<n;i++)
    {
        cout<<path[i]<<" ";
    }
}
bool isSafe(int **graph,int n,int v,int *path,int pos)
{
    if(graph[path[pos-1]][v]==0)
    {
        return false;
    }
    for(int i=0;i<pos;i++)
    {
        if( path[i]==v)
        {
            return false;
        }
    }
    return true;
}
bool hamCycleUtil(int **graph,int n,int *path,int pos)
{
    if(pos==n)
    {
        if(graph[path[pos-1]][path[0]]==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        for(int i=1;i<n;i++)
        {
            if(isSafe(graph,n,i,path,pos)==true)
            {
                path[pos]=i;
                if(hamCycleUtil(graph,n,path,pos+1)==true)
                {
                    return true;
                }
                else
                {
                    path[pos]=-1;
                }
            }
        }
        return false;
    }
}
void hamCycle(int **graph,int n)
{
    int *path=new int[n];
    for(int i=0;i<n;i++)
    {
        path[i]=-1;
    }
    path[0]=0;
    if(hamCycleUtil(graph,n,path,1)==true)
    {
        printSolution(path,n);
    }
    else
    {
        cout<<"Solution does not exists.";
    }
}
int main()
{
    int n;
    cout<<"Enter the value of n:\n";
    cin>>n;
    int **graph=new int*[n];
    for(int i=0;i<n;i++)
    {
        graph[i]=new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
    hamCycle(graph,n);
}
