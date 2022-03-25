/*
 * main.c
 *
 * Project: Traverse all cities
 * Author: Qi Duan
 * Email: qi.duan001@umb.edu
 * Date: 05/16/2021
 * Notes:
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
#define BLOCKED INT_MAX

int strToNum(char *str) {
    
    int num = 0;
    while (*str != '\0' && *str != '\n' && *str != ' ') {
        num = 10 * num + (int)(*str - '0');
        ++str;
    }
    
    return num;
}

int main(int argc, char *argv[]) {
    /* Read the input */
    char buffer[100];
    scanf("%s", buffer);
    int n = strToNum(buffer);
    int **graph = (int **)malloc(n * sizeof(int *));
    
    for (int i = 0; i < n; ++i) {
        graph[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; ++j) {
            graph[i][j] = 0;
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            scanf("%s", buffer);
            graph[i][j] = INT_MAX;
            if (strcmp(buffer, "x") != 0) {
                graph[i][j] = graph[j][i] = strToNum(buffer);
            }
        }
    }
    /* Traverse all cities */
    // Using bellman ford algorithm to find shortest path.
    int dist[n];
    for(int i=0;i<n;i++) dist[i] = BLOCKED;
    dist[0] = 0;
  
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(graph[j][k] != BLOCKED){
                    if(dist[j] != BLOCKED && dist[j] + graph[j][k] < dist[k]){
                        dist[k] = dist[j] + graph[j][k];
                    }
                }
            }
        }
    }
  
    int ans = 0;
    for(int i=1;i<n;i++){
        ans = MAX(ans, dist[i]);

    }

    printf("%d\n", ans);
    /* Free the memory if necessary */
    for (int i = 0; i < n; ++i) {
        free(graph[i]);
    }
    free(graph);
    return 0;
}
 
 
