/* CS261- Assignment 1A - Question 1
   Name: Linshengyi Sun Partner: Samantha Rodarte
   Date: 6/28/2020
   Solution description: allocate a dynamic array of ten students, randomly assign id and scores to them.
                         Find the mininum, maximum and average score of the students.
                         Print out the information & result.
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student
{
	int id;
	int score;
};

struct student* allocate()
{
     struct student *std_arr = malloc(10 * sizeof(struct student));
     //assert(std_arr != 0);

     return std_arr;
     // Allocate memory for ten students*/
     
     // Return the pointer*/
}

void generate(struct student* students)
{
     int i;
     srand(time(NULL));
     for(i = 0; i < 10; i++)
     {
          students[i].id = rand()%10 + 1;
          students[i].score = rand()%100 + 1;
          //if(students->id == NULL )
     }
     /* Generate random and unique IDs and random scores for ten students, 
		IDs being between 1 and 10, scores between 0 and 100 */
     
}

void output(struct student* students)
{
     int i;

     printf("*** Students Information ***\n");
     for(i = 0; i < 10; i++)
     {
          printf("* Student %d", i);
          printf("   ID: %d", students[i].id);
          printf("   Score: %d\n", students[i].score);


     }
     /* Output information about the ten students in the format:
        ID1 Score1
        ID2 score2
        ID3 score3
        ...
        ID10 score10*/
}

void summary(struct student* students)
{
     int i;
     int min = 0, max = 0, sum = 0, average = 0;
     for(i = 0; i < 10; i++)
     {
          if(i == 0)
               min = students[0].score;
          if(students[i].score > max)
               max = students[i].score;
          if(min > students[i].score)
               min = students[i].score;
          sum = sum + students[i].score;
     }
     average = sum / 10;

     //printf("\n");
     printf("\n** Minimum score: %d\n", min);
     printf("** Maximum score: %d\n", max);
     printf("** Average Score: %d\n", average);

     
     /* Compute and print the minimum, maximum and average scores of the 
		ten students */
     
}

void deallocate(struct student* stud)
{
     free(stud);
     // Deallocate memory from stud
}

int main()
{
    struct student* stud = NULL;
    
    // Call allocate
    stud = allocate();
    // Call generate
    generate(stud);
    // Call output
    output(stud);
    // Call summary
    summary(stud);
    // Call deallocate
    deallocate(stud);

    return 0;
}

