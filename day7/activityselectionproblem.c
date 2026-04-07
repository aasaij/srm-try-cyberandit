#include <stdio.h>
#include <stdlib.h>
typedef struct Actitivity{
    int start;
    int end;
}activity;
int compare(const void *x, const void *y){
    return ((activity*)x)->end - ((activity*)y)->end;
}

int main(){
    int n, cnt=0;
    scanf("%d", &n);
    activity activities[n];
    for(int i = 0; i < n; i++){
        scanf("%d %d", &activities[i].start, &activities[i].end);
    }
    qsort(activities,n, sizeof(activities[0]),compare);
    for (int i = 0; i<n; ){
        int j = i+1;
        while (j < n && activities[i].end > activities[j].start) j++;
        if (j<n){
            cnt++;
            i = j;
        }
        else
            i++;
    }
    printf("%d", cnt+1);

    return 0;
}