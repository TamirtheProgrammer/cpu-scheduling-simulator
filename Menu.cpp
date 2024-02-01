#include <iostream>
using namespace std;

int main () {
    int Input;
    
    printf("Please choose an option:\n 1)Scheduling Methods\n 2)Preemptive Mode\n 3)Show Result\n 4)Exit Program\n");

    cin >> Input;

    switch (Input)
    {
    case 1:
      int sched_method;
      printf("Please choose a scheduling method:\n 1) First Come, First Serve\n 2) Shortest Job First\n 3) Priority Scheduling\n 4) Round-Robin Scheduling\n");
      
      cin >> sched_method;

      switch (sched_method) 
      {
         case 1: system("./main/FCFS"); break;
         case 2: system("./main/SJF"); break;
         case 3: system("./main/Prior_Sched");  break;
         case 4: system("./main/RRS"); break;
         default: printf("Please choose a valid option!\n"); break;
      }
      return 0;

    case 2:
      int pre_mode;
      printf("Please choose a scheduling method:\n 1) First Come, First Serve\n 2) Shortest Job First\n 3) Priority Scheduling\n");
      cin >> pre_mode;
      
      switch (pre_mode)
      {
        case 1: system("./main/FCFS_Pre"); break;
        case 2: system("./main/SJF_Pre"); break;
        case 3: system("./main/Prior_Sched_Pre"); break;
        default: printf("Please choose a valid option!\n"); break;
      }
        return 0;

    case 3:

      printf("Showing results...\n");
      system("./main/RESULT");
       if(system == NULL) {
        printf("There is no output!");
       }
        break;

    case 4:
      printf("Exiting program...\n"); return 0;
        break;
    
    default:
      printf("Please choose a valid option!\n");
        break;
    }
}
