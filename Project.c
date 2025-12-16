#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_Q 200

typedef struct
{
    char question[200];
    char optA[100], optB[100], optC[100], optD[100];
    char correct;
} Quiz;

int main()
{
    //opening question file...
    FILE *fp = fopen("questions.txt", "r");

    //message if quetion file doesn't exist...
    if (!fp)
    {
        printf("\nError: questions.txt not found!\n");
        return 1;
    }

    //reading the question file...
    Quiz Q[MAX_Q];
    int totalQ = 0;

    while (!feof(fp))
    {
        if (!fgets(Q[totalQ].question, 200, fp))
            break;

        fgets(Q[totalQ].optA, 100, fp);
        fgets(Q[totalQ].optB, 100, fp);
        fgets(Q[totalQ].optC, 100, fp);
        fgets(Q[totalQ].optD, 100, fp);

        char correct[10];
        fgets(correct, 10, fp);
        Q[totalQ].correct = correct[0];

        char blank[10];
        fgets(blank, 10, fp);

        totalQ++;
    }
    fclose(fp);

    //giving instructions to the examinee...
    printf("\nYou will get 30 seconds for each questions.\n");
    printf("Once the time is over, the question will be counted as skipped.\n");
    printf("Even if you answer that question, you won't get any mark.\n");
    printf("So keep an eye on the clock.\n");

    //display total number of questions loaded from the file...
    printf("\nTotal questions loaded: %d\n", totalQ);

    //asking examinee to number of questions to be answered...
    int n;
    printf("How many questions do you want to answer? : ");
    scanf("%d", &n);

    //warning if the number of questions exceeds...
    if (n > totalQ)
    {
        printf("Not enough questions!\n");
        return 0;
    }

    //start of the exam...
    printf("\nYour exam starts now...\n");

    int score = 0;
    char ans;

    //displaying the questions and taking the answers one by one...
    for (int i = 0; i < n; i++)
    {
        printf("\nQ%d: %s", i + 1, Q[i].question);
        printf("a) %s", Q[i].optA);
        printf("b) %s", Q[i].optB);
        printf("c) %s", Q[i].optC);
        printf("d) %s", Q[i].optD);

        time_t start = time(NULL); //timer starts...

        //taking the answer of the displayed question...
        printf("Your answer (a/b/c/d or s to skip): ");
        getchar();
        scanf("%c", &ans);

        time_t end = time(NULL);//timer ends...
        int time_taken = end - start;

        //skipping the question if time is up...
        if (time_taken > 30)
        {
            printf("Time's up! (%d sec) \n", time_taken);
            continue;
        }

        //skipping the question if the chooses to...
        if (ans == 's' || ans == 'S')
        {
            printf("You skipped this question.\n");
            continue;
        }

        //counting answers that are correct...
        if (ans == Q[i].correct)
        {
            score++;
        }
    }

    //printing the final score...
    printf("\n========== RESULT ==========\n");
    printf("Final Score: %d out of %d\n", score, n);

    //saving the result in another file...
    FILE *save = fopen("result.txt", "a");
    fprintf(save, "Final Score: %d out of %d\n", score, n);
    fclose(save);

    printf("Your result is saved in result.txt\n");

    return 0;
}
