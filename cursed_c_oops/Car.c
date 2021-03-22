#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *name;
  int year;
} CarAttributes;

typedef struct _Car Car;

struct _Car {
  CarAttributes car_attributes;
  char *(*pfGetName)(Car *);
  int (*pfGetYear)(Car *);
  void (*pfDisplay)(Car *);
  void (*pfSetName)(Car *, char *);
  void (*pfSetYear)(Car *, int );
};

char *getName(Car *car) {
  return car->car_attributes.name;
}

int getYear(Car *car) {
  return car->car_attributes.year;
}

void display(Car *car) {
  printf("%s::%d\n", car->car_attributes.name, car->car_attributes.year);
}

void setName(Car *car, char *name) {
  car->car_attributes.name = name;
}

void setYear(Car *car, int year) {
  car->car_attributes.year = year;
}

void init_car(Car *car) {
  car->pfGetName = getName;
  car->pfGetYear = getYear;
  car->pfSetName = setName;
  car->pfSetYear = setYear;
  car->pfDisplay = display;

  car->car_attributes.name = (char *) malloc(sizeof(char) * 255);
  car->car_attributes.year = 0;
}

int main (int argc, char **argv) {
  Car car;
  init_car(&car);

  car.pfSetName(&car, "Tesla Model Z");
  car.pfSetYear(&car, 2019);
  car.pfDisplay(&car);

  return 0;
}
