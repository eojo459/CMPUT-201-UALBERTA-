/* Purpose: Lab Exercise 9
 * Author: Emmanuel Ojo
 * Date: November 4 2020
 *
 * Sources:
 *   - Linked lists: https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
 *   - Generate random float numbers: https://stackoverflow.com/questions/36752991/generate-random-float-number-ranging-0-1-in-c
 *   - Distance equation: https://eclass.srv.ualberta.ca/mod/forum/discuss.php?d=1546131
 *   - Distance formula: https://www.purplemath.com/modules/distform.htm
 *   - Freeing memory: https://stackoverflow.com/questions/6417158/c-how-to-free-nodes-in-the-linked-list
 *   - Write & append to file: https://stackoverflow.com/questions/19429138/append-to-the-end-of-a-file-in-c
 *
 * All of the code in this program was written by myself (Emmanuel Ojo)
 * I used the sources for knowledge, but coded the program by myself.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

struct point {
  float x;
  float y;
  struct point *next; //point to the next point in the same shape
};

struct point *generate(int);
struct point *insert(struct point**, float, float);
float generateRandom();
int length(struct point *);
void printing(struct point *);
struct point *returnData(struct point *, int);
struct point *indexSample(struct point *, int);
float sampleDistance(struct point *, struct point *, int);
void freeMemory(struct point *);

// file pointer
FILE *fp;

int main() {

  // initialize random seed
  srand(time(NULL));

  // open the file
  fp = fopen("example_run.txt", "w");
  
  int shape1Points, shape2Points;
  struct point *shape1, *shape2;
  
  printf("Enter two integers in [1, 1000]: ");
  scanf("%d%d", &shape1Points, &shape2Points);
  fprintf(fp, "Enter two integers in [1, 1000]: %d %d\n", shape1Points, shape2Points);

  // PART 1: generate the shapes with their points
  shape1 = generate(shape1Points);
  
  if (shape1Points > 1) {
    fprintf(fp, "Shape1 with %d points: ", shape1Points);
    printf("Shape1 with %d points: ", shape1Points);
  }
  else {
    fprintf(fp, "Shape1 with %d point: ", shape1Points);
    printf("Shape1 with %d point: ", shape1Points);
  }
  printing(shape1);
  
  shape2 = generate(shape2Points);

  if (shape2Points > 1) {
    fprintf(fp, "Shape2 with %d points: ", shape2Points);
    printf("Shape2 with %d points: ", shape2Points);
  }
  else {
    fprintf(fp, "Shape2 with %d point: ", shape2Points);
    printf("Shape2 with %d point: ", shape2Points);
  }
  printing(shape2);

  // PART 2: find k-sample
  int k;

  printf("Enter an integer in [2, 1000]: ");
  scanf("%d", &k);
  fprintf(fp, "Enter an integer in [2, 1000]: %d\n", k);
  
  struct point *sshape1, *sshape2;
  sshape1 = indexSample(shape1, k);
  sshape2 = indexSample(shape2, k);

  fprintf(fp, "%d-sample: ", k);
  printf("%d-sample: ", k);
  printing(sshape1);

  fprintf(fp, "%d-sample: ", k);
  printf("%d-sample: ", k);
  printing(sshape2);

  // PART 3: find k-sample distance
  fprintf(fp, "The %d-sample distance is: %0.3f\n", k, sampleDistance(sshape1, sshape2, k));
  printf("The %d-sample distance is: %0.3f\n", k, sampleDistance(sshape1, sshape2, k));

  // free the memory
  freeMemory(shape1);
  freeMemory(shape2);
  freeMemory(sshape1);
  freeMemory(sshape2);

  // close file
  fclose(fp);
  
  return 0;
}

// free the memory to prevent memory leaks
void freeMemory(struct point *shape) {
  struct point *temp;

  while (shape != NULL) {
    temp = shape;
    shape = shape->next;
    free(temp);
  }
}

// print out the points
void printing(struct point *shape) {
  
  // print out all the shapes to 3 decimals
  while (shape != NULL) {
    if (shape->x != -1 && shape->y != -1) {
      if (shape->next != NULL) {
	fprintf(fp, "<(%0.3f, %0.3f)>, ", shape->x, shape->y);
	printf("<(%0.3f, %0.3f)>, ", shape->x, shape->y);
      }
      else {
	fprintf(fp, "<(%0.3f, %0.3f)>", shape->x, shape->y);
	printf("<(%0.3f, %0.3f)>", shape->x, shape->y);
      }
    }
    shape = shape->next;
  }
  printf("\n");
  fprintf(fp, "\n");
}

// find length of linked list, count the points
int length(struct point *shape) {
  int count = 1;
  struct point *current = shape;
  
  while (current->next != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

// get the data from an index and return it
struct point *returnData(struct point *shape, int index) {
  int count = 0;
  struct point *current = shape;

  while ((count < index) && (current->next != NULL)) {
    count++;
    current = current->next;
  }
  return current;
}

// generate random numbers from [0,1000]
float generateRandom() {
  return rand() % 1000 + ((float)rand() / RAND_MAX);
}

// insert points into the linked list
struct point *insert(struct point** head, float x, float y) {
  
  // allocate space
  struct point* newPoint = (struct point*) malloc (sizeof(struct point));
  struct point *current = *head;
  
  // linked list
  newPoint->x = x;
  newPoint->y = y;

  newPoint->next = NULL;

  if (*head == NULL) {
    *head = newPoint;
    return *head;
  }
  
  while (current->next != NULL) {
    current = current->next;
  }
  
  current->next = newPoint;

  // return the head pointer/beginning of linked list
  return *head;
}

// generate a shape of n random points
struct point *generate(int n) {

  // generate random points from [0,1000] x [0,1000]
  float randX = generateRandom(), randY = generateRandom();
  int count = 0;

  struct point* head = NULL;
  struct point* current;
  
  // send the empty null head pointer first
  current = insert(&head, randX, randY);
  count++;

  // if we have more points to add, add them to the end of the linked list
  while (count < n) {
    randX = generateRandom();
    randY = generateRandom();
    
    current = insert(&current, randX, randY);
    count++;
  }

  // return the head pointer A.K.A pointer to beginning of the linked list
  return current;
}

// build a k-sample from the original points
struct point *indexSample(struct point *shape, int k) {

  struct point *head = NULL, *current, *sampleIndex[5];
  
  int index[5], n = length(shape), count = 0, pos = 0;
  
  index[0] = 0;
  index[1] = floor(n/(k-1));
  index[2] = floor((2*n)/(k-1));
  index[3] = floor(((k-2)*n)/(k-1));
  index[4] = n - 1;

  current = insert(&head, -1, -1);

  // always include atleast the first and last index
  while (count < k) {
    if (index[pos] < n) {
      
      // print last index
      if (count == k - 1 && index[4] < n) {
	sampleIndex[4] = returnData(shape, index[4]);
	current = insert(&current, sampleIndex[4]->x, sampleIndex[4]->y );
	break;
      }
      sampleIndex[pos] = returnData(shape, index[pos]);
      current = insert(&current, sampleIndex[pos]->x, sampleIndex[pos]->y );
      count++;
    }
    pos++;
  }
  // return pointer to head/beginning
  return current;
}


float sampleDistance(struct point *shape1, struct point *shape2, int k) {

  float totalDistance = 0;

  // make sure we aren't pointing to the head
  while (shape1->x == -1 || shape1->y == -1) {
    shape1 = shape1->next;
  }

  while (shape2->x == -1 || shape2->y == -1) {
    shape2 = shape2->next;
  }

  for (int i = 0; i < k; i++) {
    totalDistance = totalDistance + (sqrt(pow((shape2->x - shape1->x),2) + pow((shape2->y - shape1->y),2)));
    shape1 = shape1->next;
    shape2 = shape2->next;
  }

  return totalDistance;
}
