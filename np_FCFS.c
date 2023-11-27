#include<stdio.h>
int main(){
    int bt[20]={0},at[20]={0},tat[20]={0},wt[20]={0},ct[20]={0},process[20];
    int n,sum=0;
    float totalTAT=0,totalWT=0;
    printf("Enter number of processes:");
    scanf("%d",&n);
    printf("Enter arrival time and burst time :\n\n");
    for(int i=0;i<n;i++)
    {
        printf("Arrival time of process[%d]",i+1);
        scanf("%d",&at[i]);
        
        printf("Burst time of process[%d]",i+1);
        scanf("%d",&bt[i]);
        printf("\n");
    }
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                int temp = at[j];
at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
            }
        }
    }
    for(int j=0;j<n;j++)
    {
        sum=sum+bt[j];
        ct[j]=ct[j]+sum;
    }
    for(int k=0;k<n;k++)
    {
        tat[k]=ct[k]-at[k];
        totalTAT=totalTAT+tat[k];
    }
    for(int k=0;k<n;k++)
    {
        wt[k]=tat[k]-bt[k];
        totalWT=totalWT+wt[k];
    }
    printf("TABLE: \n\n");
    printf("PId\t AT\t BT\t CT\t TAT\t WT\t\n\n");
    
    for(int i=0;i<n;i++)
    {
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage Turnaround Time = %f\n",totalTAT/n);
    printf("Average WT = %f\n\n",totalWT/n);
    return 0;
}
