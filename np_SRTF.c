#include <stdio.h>

int main() {
    int arrival_time[10], burst_time[10], temp[10];
    int i, smallest, count = 0, j, number;
    double wait_time = 0, turnaround_time = 0, end;
    float average_waiting_time, average_turnaround_time;
    printf("Enter the Total Number of Processes:");
    scanf("%d", &number);
    for (i = 0; i < number; i++) {
        printf("\nEnter Arrival Time of process %d:", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter Burst Time of process %d:", i + 1);
        scanf("%d", &burst_time[i]);
        temp[i] = burst_time[i];
    }

    burst_time[9] = 99;

    for (j = 0; count != number; j++) {
        smallest = 9;
        for (i = 0; i < number; i++) {
            if (arrival_time[i] <= j && burst_time[i] < burst_time[smallest] && burst_time[i] > 0) {
                smallest = i;
            }
        }
        burst_time[smallest]--;
        if (burst_time[smallest] == 0) {
            count++;
            end = j + 1;
            wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
            turnaround_time = turnaround_time + end - arrival_time[smallest];
        }
    }
    
    average_waiting_time = wait_time / number;
    average_turnaround_time = turnaround_time / number;

    //----------------------------------------------------------------------------------------
    printf("\n\nProcess\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < number; i++) {
        printf("%d\t%d\t\t%d\t\t%.2f\t\t%.2f\n", i + 1, arrival_time[i], temp[i], end - arrival_time[i], end - arrival_time[i] - temp[i]);
    }
    //----------------------------------------------------------------------------------------
    
    printf("\nAverage Waiting Time: %f\n", average_waiting_time);
    printf("Average Turnaround Time: %f\n", average_turnaround_time);

    return 0;
}

