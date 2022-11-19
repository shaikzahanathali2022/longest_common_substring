#include <iostream>
#include <vector>
#include <climits>
using namespace std;

 int minDist(int dist[], bool Tset[]) // finding minimum distance
{
    int min=INT_MAX,ind;
              
    for(int k=0;k<6;k++) 
    {
        if(Tset[k]==false && dist[k]<=min)      
        {
            min=dist[k];
            ind=k;
        }
    }
    return ind;
}

void DijkstraAlgorithm(int Thegraph[6][6],int source) 
{
    int dist[6];                             
    bool Tset[6]; 
     
    for(int k = 0; k<6; k++)
    {
        dist[k] = INT_MAX;
        Tset[k] = false;    
    }
    
    dist[source] = 0;                
    
    for(int k = 0; k<6; k++)                           
    {
        int m=minDist(dist,Tset); 
        Tset[m]=true;
        for(int k = 0; k<6; k++)                  
        {
           
            if(!Tset[k] && Thegraph[m][k] && dist[m]!=INT_MAX && dist[m]+Thegraph[m][k]<dist[k])
                dist[k]=dist[m]+Thegraph[m][k];
                 // neighbouring vertexdistance gets updated.
        }
    }
    cout<<"Vertex\t  \t  the distance from source vertex"<<endl;
    for(int k = 0; k<6; k++)                      
    { 
        char str=65+k; 
        cout<<str<<"\t\t\t"<<dist[k]<<endl;
    }
}
int main() {
    int Thegraph[6][6]={
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}};
    DijkstraAlgorithm(Thegraph,0);
    return 0;
}
