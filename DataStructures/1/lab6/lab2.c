#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int Q[n];
    for (int i=0; i<n; i++)
        scanf("%d", &Q[i]);
    
    for (int i=k-1; i>=0; i--)
        printf("%d ", Q[i]);
    for (int i=k; i<n; i++)
        printf("%d ", Q[i]);

    return 0;
}