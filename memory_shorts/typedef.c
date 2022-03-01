#include <cs50.h>
#include <string.h>
#include <stdint.h>

// To run: make typedef && ./typedef

int main(void)
{
    typedef struct car
    {
        int year;
        char model[10];
        char plate[7];
        int odometer;
        double engine_size;
    }
    car_t; // car_t is the new name

    // declaration
    car_t mycar; // create a variable mycar using car_t type

    // access fields
    mycar.year = 2011;
    strcpy(mycar.plate, "CS50");
    mycar.odometer = 50505;
}