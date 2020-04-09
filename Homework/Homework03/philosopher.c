#include<stdio.h>

#define n 5 //this can be any number you set.

int doneEating = 0,i;

struct fork{
    int taken;
}Forks[n];

struct philosopher{
    int left;
    int right;
}Status[n];

void eatDinner(int philosopherID) {
    if (Status[philosopherID].left == 10 && Status[philosopherID].right == 10)
        printf("Philosopher %d finished eating dinner\n", philosopherID + 1);
    else if (Status[philosopherID].left == 1 && Status[philosopherID].right == 1) {
        printf("Philosopher %d finished eating dinner\n", philosopherID + 1);
        Status[philosopherID].left = Status[philosopherID].right = 10;
        int otherFork = philosopherID - 1;
        if (otherFork == -1)
            otherFork = (n - 1);
        Forks[philosopherID].taken = Forks[otherFork].taken = 0;
        printf("Philosopher %d put down fork %d and fork %d\n", philosopherID + 1, philosopherID + 1, otherFork + 1);
        doneEating ++;
    }
    else if (Status[philosopherID].left == 1 && Status[philosopherID].right == 0) {
        if (philosopherID == (n - 1)) {
            if (Forks[philosopherID].taken == 0) {
                Forks[philosopherID].taken = Status[philosopherID].right = 1;
                printf("Fork %d is taken by philosopher %d\n",philosopherID + 1, philosopherID + 1);
            } else {
                printf("Philosopher %d is waiting for fork %d\n",philosopherID + 1, philosopherID + 1);
            }
        } else {
            int dupphilosopherID = philosopherID;
            philosopherID -= 1;
            
            if (philosopherID == -1)
                philosopherID = (n - 1);
            
            if (Forks[philosopherID].taken == 0) {
                Forks[philosopherID].taken = Status[dupphilosopherID].right = 1;
                printf("Fork %d is taken by philosopher %d\n", philosopherID + 1, dupphilosopherID + 1);
            } else {
                printf("Philosopher %d is waiting for fork %d\n", dupphilosopherID + 1, philosopherID + 1);
            }
        }
    }
    else if (Status[philosopherID].left == 0) {
        if (philosopherID == (n - 1)) {
            if (Forks[philosopherID - 1].taken == 0) {
                Forks[philosopherID - 1].taken = Status[philosopherID].left = 1;
                printf("Fork %d is taken by philosopher %d\n", philosopherID, philosopherID + 1);
            } else {
                printf("Philosopher %d is waiting for fork %d\n", philosopherID + 1, philosopherID);
            }
        } else {
            if (Forks[philosopherID].taken == 0){
                Forks[philosopherID].taken = Status[philosopherID].left = 1;
                printf("Fork %d is taken by Philosopher %d\n", philosopherID + 1, philosopherID + 1);
            } else {
                printf("Philosopher %d is waiting for fork %d\n", philosopherID + 1, philosopherID + 1);
            }
        }
    }
}

int main() {
    for(i = 0; i < n; i++) {
        Forks[i].taken=Status[i].left = Status[i].right = 0;
    }
    
    while(doneEating < n){
        for(i = 0; i < n; i++) {
            eatDinner(i);
        }
        printf("There are %d philosophers finished eating dinner so far.\n\n", doneEating);
    }
    
    return 0;
}
