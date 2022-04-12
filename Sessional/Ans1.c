#include <stdio.h>
#include <string.h>
int main()
{
    int n, m, r, c, min, a, b, t, val = 9999;
    printf("Enter ETC MATRIX size: ");
    scanf("%d %d", &n, &m);
    int etc_max[m][n], brr[n];
    t = n;
    for (int i = 0; i < m; i++)
    {
        printf("Machine %d\n", i + 1);
        for (int j = 0; j < n; j++)
        {
            printf("Task %d: ", j + 1);
            scanf("%d", &etc_max[i][j]);
        }
        printf("\n");
    }
    while (t > 0)
    {
        min = val;
        memset(brr, 9999, sizeof(brr));
        for (c = 0; c < n; c++)
        {
            for (r = 0; r < m; r++)
            {
                if (brr[c] > etc_max[r][c])
                    brr[c] = etc_max[r][c];
            }
            if (brr[c] < min)
            {
                min = brr[c];
                b = c;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (etc_max[i][b] == min)
            {
                printf("Task %d(%d) will be assigned to Machine %d\n", b + 1, min, i + 1);
                a = i;
            }
        }
        t--;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == a)
                    etc_max[i][j] += min;
                if (j == b)
                    etc_max[i][j] = val;
            }
        }
    }
    printf("Make Span time - %d", min);
    return (0);
}
