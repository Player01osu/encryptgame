#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// chooses random number
int randAlg() {

  int whichOne = rand() % 4;

  return whichOne;
}

double cardOne(cardIn) {

  double outputCard = cardIn * 2;

  return outputCard;
}
double cardTwo(cardIn) {

  double outputCard = cardIn + 5;

  return outputCard;
}
double cardThree(cardIn) {

  double outputCard = cardIn * 1.5;

  return outputCard;
}
double cardFour(cardIn) {

  double outputCard = cardIn - 5;

  return outputCard;
}
double cardFive(cardIn) {

  double outputCard = cardIn + 2.5;

  return outputCard;
}
int main() {
  // user input
  // char cardIn[25];

  // start randomizer timer
  srand(time(NULL));

  int whichPicked;
  int cardIn;
  int userAnswer;
  // cardIn = fgetc(stdin);
  printf("Welcome!\n");
  printf("\nstart by inputting the number on the card: ");
  scanf("%d", &cardIn);

  // printf("\nrandom alg picked %d\n", randAlg());

  // check if random number generated is number
  if (randAlg() == 0) {
    printf("%f", cardOne(cardIn));
    whichPicked = 1;
  } else if (randAlg() == 1) {
    printf("%f", cardTwo(cardIn));
    whichPicked = 2;
  } else if (randAlg() == 2) {
    printf("%f", cardThree(cardIn));
    whichPicked = 3;
  } else if (randAlg() == 3) {
    printf("%f", cardFour(cardIn));
    whichPicked = 4;
  } else {
    printf("%f", cardFive(cardIn));
    whichPicked = 5;
  }

  printf("\nWhich random alg is it?");
  printf("\ncard 1\ncard 2\ncard 3\ncard 4\ncard 5\n");
  scanf("%d", &userAnswer);
  if (userAnswer == whichPicked) {
    printf("\nYou win!!");
  } else {
    printf("\nThat's not quite it");
  }
  printf("\npicked card %d", whichPicked);
}
