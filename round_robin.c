// Round Robin Scheduling using C (Linked List)

#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int at;
    int bt;
    int rt;     // Remaining Time
    int wt;
    int tat;
    int done;
    struct Process* next;
};

int main() {
    int n, time = 0, completed = 0, tq;
    float avgWT = 0, avgTAT=0;
    struct Process* head = NULL, *temp, *new_pr;

    printf(" Enter the total number of processes: ");
    scanf("%d", &n);

    printf(" Enter Time Quantum: ");
    scanf("%d", &tq);

    for(int i=0; i<n; i++) {
        new_pr = (struct Process*)malloc(sizeof(struct Process));
        new_pr->pid = i+1;

        printf("Enter the AT and BT of P%d: ", new_pr->pid);
        scanf("%d %d", &new_pr->at, &new_pr->bt);

        new_pr->rt = new_pr->bt;   // Initialize remaining time
        new_pr->done = 0;
        new_pr->next = NULL;

        if(head == NULL)
            head = new_pr;
        else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = new_pr;
        }
    }

    while (completed < n) {

        int executed = 0;   // To check if any process executed in this cycle
        temp = head;

        while (temp != NULL) {

            if(temp->at <= time && temp->done == 0) {

                executed = 1;

                if(temp->rt > tq) {
                    time += tq;
                    temp->rt -= tq;
                }
                else {
                    time += temp->rt;
                    temp->rt = 0;

                    temp->tat = time - temp->at;
                    temp->wt = temp->tat - temp->bt;
                    temp->done = 1;
                    completed++;
                }
            }

            temp = temp->next;
        }

        // If no process was ready, increment time
        if(!executed)
            time++;
    }

    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    temp = head;

    while (temp != NULL) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               temp->pid, temp->at, temp->bt,
               temp->wt, temp->tat);

        avgWT += temp->wt;
        avgTAT += temp->tat;
        temp = temp->next;
    }

    printf("\n Average Waiting Time = %.2f", avgWT/n);
    printf("\n Average Turnaround Time = %.2f\n", avgTAT/n);

    return 0;
}