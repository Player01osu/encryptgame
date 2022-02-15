#include <gtk/gtk.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static GtkWidget *cardIn;
// static GtkWidget *number2;
static GtkWidget *result;

int whichPicked;
// char cardIn[6];
int userAnswer;
int i;
int numI;
int ascii;
int binS;
long long cardInAdded;
char cardIns[10];
char cardInNum[10];

// chooses random number
int randAlg() {

  int whichOne = rand() % 4;

  return whichOne;
}

// Take input; multiply by 2
double cardOne(cardInAdded) {

  double outputCard = cardInAdded * 2;

  return outputCard;
}

// Take input; add 5
double cardTwo(cardInAdded) {

  double outputCard = cardInAdded + 5;

  return outputCard;
}

// Take input; multiply by 1.5
double cardThree(cardInAdded) {

  double outputCard = cardInAdded * 1.5;

  return outputCard;
}

// Take input; minus 5
double cardFour(cardInAdded) {

  double outputCard = cardInAdded - 5;

  return outputCard;
}

// Take input; add 2.5
double cardFive(cardInAdded) {

  double outputCard = cardInAdded + 2.5;

  return outputCard;
}

// Determine how many digits in number
int numPlaces(int n) {
  if (n < 0)
    return numPlaces((n == INT_MIN) ? INT_MAX : -n);
  if (n < 10)
    return 1;
  return 1 + numPlaces(n / 10);
}

// function takes entry, turns to ascii and prints to result
void do_calculate(GtkWidget *calculate, gpointer data) {
  // entry field called cardInNum
  const gchar cardInNum = *gtk_entry_get_text(GTK_ENTRY(cardIn));
  cardInAdded = 0;

  char buffer[32];
  // cardIns = *cardInNum;
  /*for (i = 0; cardInNum[i] != 0; i++) {
    ascii = cardInNum[i];
    // printf("ascii is %d\n", ascii);
    cardInAdded = cardInAdded * (pow(10, numPlaces(ascii)));
    cardInAdded = cardInAdded + ascii;
    // printf("added %lld\n", cardInAdded);
    // printf("num place %d\n", numPlaces(ascii));
  }*/

  ascii = cardIns[3];
  // ascii = *cardInNum;
  // snprintf(buffer, sizeof(buffer), "result: %lld", cardInAdded);
  snprintf(buffer, sizeof(buffer), "result: %c", cardInNum);

  gtk_label_set_text(GTK_LABEL(result), buffer);
}

int main(int argc, char **argv) {
  // spawn window
  GtkWidget *window, *grid, *calculate;
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  grid = gtk_grid_new();
  gtk_container_add(GTK_CONTAINER(window), grid);

  // entry window
  cardIn = gtk_entry_new();
  gtk_grid_attach(GTK_GRID(grid), cardIn, 0, 0, 1, 1);

  // call do calculate function when calculate clicked
  calculate = gtk_button_new_with_label("calculate");
  g_signal_connect(calculate, "clicked", G_CALLBACK(do_calculate), NULL);
  gtk_grid_attach(GTK_GRID(grid), calculate, 2, 0, 1, 1);

  result = gtk_label_new("result:");
  gtk_grid_attach(GTK_GRID(grid), result, 3, 0, 1, 1);

  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}
