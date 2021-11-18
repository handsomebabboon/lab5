#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define V 9
int printSol(int dist[V]){
    printf("node\t\tmindist\n");

    for(int i=0;i<V;i++){
        printf("%d\t\t%d",i,dist[i]);
        printf("\n");
    }
}
int mindist(bool sptSet[V],int dist[V]){
    int min = INT_MAX,min_index;

    for(int i=0;i<V;i++){
        if(dist[i]<min && sptSet[i]==false){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;


}
int dij(int graph[V][V],int src){

    bool sptSet[V];int dist[V];

    for(int i=0;i<V;i++){
        sptSet[i] = false;dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for(int count=0;count<V-1;count++){
        int u = mindist(sptSet,dist);
        sptSet[u] = true;

        for(int v=0;v<V;v++){
            if(graph[u][v] && !sptSet[v] && dist[u] != INT_MAX && dist[v] > dist[u] + graph[u][v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }

    }
    printSol(dist);

}
int main()
{
    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    dij(graph, 0);
 
    return 0;
}