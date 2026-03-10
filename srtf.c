// SJF Preemptive (SRTF) Scheduling using C

#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int at;
    int bt;
    int rt;     // Remaining Time (NEW)
    int wt;
    int tat;
    int done;
    struct Process* next;
};

int main() {
    int n, time = 0, completed = 0;
    float avgWT = 0, avgTAT = 0;
    struct Process* head = NULL, *temp, *new_pr;

    printf(" Enter the total number of processes: ");
    scanf("%d", &n);

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

        struct Process* candidate = NULL;
        temp = head;
        int minRT = 99999;

        // Find process with minimum remaining time
        while (temp != NULL) {
            if(temp->at <= time && temp->done == 0 && temp->rt < minRT && temp->rt > 0) {
                minRT = temp->rt;
                candidate = temp;
            }
            temp = temp->next;
        }

        if(candidate == NULL) {
            time++;
            continue;
        }

        // Execute for 1 unit time (PREEMPTION happens here)
        candidate->rt--;
        time++;

        // If process finishes
        if(candidate->rt == 0) {
            candidate->tat = time - candidate->at;
            candidate->wt = candidate->tat - candidate->bt;
            candidate->done = 1;
            completed++;
        }
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