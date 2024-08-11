#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUCCESS_CUTOFF  (int)177
#define MAX_TURNS       (int)231
#define MAX_TURNS_PLUS  (int)232


#define ROLLS           (int) 1000000000

int main() {
    // roll counters
    int roll = 0;
    int highest_roll = 0;
    int roll_results[4] = {0,0,0,0};
    int *one_roll_count = &roll_results[0];
    int rand_number = 0;

    time_t start_time, end_time;
    double elapse_time = 0.0;
    struct tm ts;
    char buf[80];

    // seeding the rand generator
    srand(time(NULL));
    printf("Starting the loop counter\n");
    fflush(stdout); // Force printing of text before all hell breaks loose

    // Start time of calculation
    time(&start_time);
    while ((*one_roll_count < SUCCESS_CUTOFF) & (roll < ROLLS)) {
        for (int i = 1; i < MAX_TURNS_PLUS; i++) {
            roll_results[rand()%4]++; // Use roll outcome as direct link to mem location
            // Note ++, this directly increments the value, in stead of getting the value from mem adding one and storing again.

            // rand_number = rand()%4;
            // printf(" %d", rand_number);
            // roll_results[rand_number]++;
        }
        // Keep taps on roll count
        roll++;
        // Store highest achieved value
        if (roll_results[0] > highest_roll) highest_roll = roll_results[0];
        // Reset results mem
        for (int i=0; i<4;i++) roll_results[i] = 0;
    } 
    // Capture end of calculation
    time(&end_time);

    printf("\n\n");
    printf("***********\n");
    printf("* Results *\n");
    printf("***********\n");
    printf("Ran %d times\n", roll);
    // Human readable printing of epochs (Should have been a function \('<')/ )
    ts = *localtime(&start_time);
    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
    printf("Ran from %s\n", buf);
    
    ts = *localtime(&end_time);
    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
    printf("Ran till %s\n", buf);

    printf("Took %.2f seconds\n", difftime(end_time, start_time));
    
    // Print highest roll
    printf("Highest roll: %d\n", highest_roll);
    // printf("Rolls: %d ; %d ; %d ;%d\n",
    //     roll_results[0],
    //     roll_results[1],
    //     roll_results[2],
    //     roll_results[3]);

    printf("Exiting the loop counter\n");
    return 0;
}