// Implement min min algorithm
#include <stdio.h>
#include <limits.h>

int main()
{
    int nT, nM; // number of tasks , number of machines
    printf("\nEnter number of machines and tasks\n");
    scanf("%d %d", &nM, &nT);
    int minMin[nM][nT];
    int tmp[nM][nT];
    int makespan = 0;
    printf("\nFill Data\n");
    for (int i = 0; i < nM; i++)
        for (int j = 0; j < nT; j++)
        {
            scanf("%d", &minMin[i][j]);
            tmp[i][j] = minMin[i][j];
        }
    printf("\nOriginal Data\n");
    for (int i = 0; i < nM; i++)
    {
        for (int j = 0; j < nT; j++)
            printf("%d ", minMin[i][j]);
        printf("\n");
    }
    int resultTask[nT];
    int resultMachine[nT];
    int resultTime[nT];
    int ptr = -1; // Indicates if result set is full or not
    while (ptr < nT - 1)
    {
        int time[nT], machine[nT]; // stores minimum time w.r.t machine of each task
        for (int j = 0; j < nT; j++)
        {
            int minimum = INT_MAX;
            int pos = -1;
            for (int i = 0; i < nM; i++)
            {
                if (minMin[i][j] < minimum)
                {
                    minimum = minMin[i][j];
                    pos = i;
                }
            }
            time[j] = minimum;
            machine[j] = pos;
        }

        // Now we find task with minimum time

        int minimum = INT_MAX;
        int pos = -1;

        for (int j = 0; j < nT; j++)
        {
            if (time[j] < minimum)
            {
                minimum = time[j];
                pos = j;
            }
        }

        resultTask[++ptr] = pos;
        resultMachine[ptr] = machine[pos];
        resultTime[ptr] = tmp[machine[pos]][pos];
        if (minimum > makespan)
            makespan = minimum;
        // resetting states

        for (int i = 0; i < nM; i++)
        {
            for (int j = 0; j < nT; j++)
            {
                if (j == resultTask[ptr])
                    minMin[i][j] = INT_MAX;
                else if (i == resultMachine[ptr] && minMin[i][j] != INT_MAX)
                    minMin[i][j] += minimum;
                else
                    continue;
            }
        }
    }

    // printing answer
    printf("\nScheduled Task are :\n");
    for (int i = 0; i < nT; i++)
    {
        printf("\nTask %d Runs on Machine %d with Time %d units\n", resultTask[i] + 1, resultMachine[i] + 1, resultTime[i]);
    }

    printf("\nMakespan : %d units\n", makespan);
    return 0;
}

//O/p:
Enter number of machines and tasks
2 3

Fill Data
140
100
20
100
60
70

Original Data
140 100 20 
100 60 70 

Scheduled Task are :

Task 3 Runs on Machine 1 with Time 20 units

Task 2 Runs on Machine 2 with Time 60 units

Task 1 Runs on Machine 1 with Time 140 units

Makespan : 160 units

-------------------------------------
Enter number of machines and tasks
3 7

Fill Data
15
7
9
9
8
8
11
6
8
10
8
9
5
7
8
4
7
8
5
6
4

Original Data
15 7 9 9 8 8 11
6 8 10 8 9 5 7
8 4 7 8 5 6 4

Scheduled Task are :

Task 2 Runs on Machine 3 with Time 4 units

Task 6 Runs on Machine 2 with Time 5 units

Task 5 Runs on Machine 1 with Time 8 units

Task 7 Runs on Machine 3 with Time 4 units

Task 1 Runs on Machine 2 with Time 6 units

Task 3 Runs on Machine 1 with Time 9 units

Task 4 Runs on Machine 3 with Time 8 units

Makespan : 20 units
