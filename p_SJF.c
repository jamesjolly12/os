#include<stdio.h>
#define max 10

int main()
{

int temp,PID[max],AT[max],BT[max],WT[max],TAT[max],n;
float TotalWT=0.0,TotalTAT=0.0;

printf("Enter the number of PID:-");
scanf("%d",&n);

for(int i=0;i<n;i++){
    printf("Enter PID :-");
    scanf("%d",&PID[i]);
    printf("Enter the A.T:-");
    scanf("%d",&AT[i]);
    printf("Enter the B.T:- ");
    scanf("%d",&BT[i]);
}

//Apply any Soerting algorithem
// I am applying Bubble sort

for(int i=0;i<n;i++){
    for(int j=0;j<n-i-1;j++){
        if(BT[j]>BT[j+1]){
            temp=BT[j];
            BT[j]=BT[j+1];
            BT[j+1]=temp;

            temp=PID[j];
            PID[j]=PID[j+1];
            PID[j+1]=temp;
        }
    }
}
printf("\nPID\t AT\t BT\t TAT\t WT\n");
for(int i=0;i<n;i++){
    WT[i]=0;
    TAT[i]=0;
    for(int j=0;j<i;j++){
        WT[i]=WT[i]+BT[j];
    }
TAT[i]=WT[i]+BT[i];
TotalWT=TotalWT+WT[i];
TotalTAT=TotalTAT+TAT[i];
printf("%d\t %d\t %d\t %d\t %d\t\n",PID[i],AT[i],BT[i],TAT[i],WT[i]);

}

printf("\nAverage Waiting time is %f\n",TotalWT/n);
printf("Average Turn Around Time is %f\n",TotalTAT/n);
}
