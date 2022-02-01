#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int whichPicked;
char cardIn[33];
int userAnswer;
int i;
int numI;
int ascii;
int binS;
int cardInAdded;

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

int numPlaces(int n) {
  if (n < 0)
    return numPlaces((n == INT_MIN) ? INT_MAX : -n);
  if (n < 10)
    return 1;
  return 1 + numPlaces(n / 10);
}
/*int asciify(cardIn){



}*/

int main() {
  // user input
  // char cardIn[25];

  // start randomizer timer
  srand(time(NULL));

  // cardIn = fgetc(stdin);
  printf("Welcome!\n");
  printf("\nstart by inputting the number on the card: ");
  // scanf("%d", &cardIn);
  fgets(cardIn, 33, stdin);

  // printf("\nrandom alg picked %d\n", randAlg());
  //
  for (i = 0; cardIn[i] != 0; i++) {
    ascii = cardIn[i];
    printf("ascii is %d\n", ascii);
    cardInAdded = cardInAdded * (pow(10, numPlaces(ascii)));
    cardInAdded = cardInAdded + ascii;
    printf("added %d\n", cardInAdded);
    // printf("num place %d\n", numPlaces(ascii));
  }

  cardInAdded = (cardInAdded - 10) / 100;
  printf("card in final %d\n", cardInAdded);
  // check if random number generated is number
  if (randAlg() == 0) {
    printf("%f", cardOne(ascii));
    whichPicked = 1;
  } else if (randAlg() == 1) {
    printf("%f", cardTwo(ascii));
    whichPicked = 2;
  } else if (randAlg() == 2) {
    printf("%f", cardThree(ascii));
    whichPicked = 3;
  } else if (randAlg() == 3) {
    printf("%f", cardFour(ascii));
    whichPicked = 4;
  } else {
    printf("%f", cardFive(ascii));
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
