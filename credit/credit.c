#include <stdio.h>
#include <cs50.h>

// function declaration
long firsttwodigits(long num);

// Prompt for user to input the credit card number
int main(void)
{
    long card_number = get_long("What's your credit card number? ");

    //long card_number = 4003600000000014;

    // Multiply every other digit by 2,
    // starting with the number’s second-to-last digit,
    // and then add those products’ digits together.
    long card_number_2nd = card_number / 10;
    long sum = 0;
    long product = 0;
    long product_digit = 0;
    long sum_product_digit = 0;

    while
    (card_number_2nd)
    {
        product = (card_number_2nd % 10) * 2;
        while
        (product)
        {
            product_digit = product % 10;
            sum_product_digit += product_digit;
            product /= 10;
        }
        card_number_2nd /= 100;
    }
    // Debug for result
    // printf("%li\n",sum_product_digit);

    // Add the sum to the sum of the digits that weren’t multiplied by 2.
    long checksum = 0;
    long other_digits = 0;
    long sum_other_digits = 0;
    long card_number_local = card_number;
    while
    (card_number_local)
    {
        other_digits = card_number_local % 10;
        sum_other_digits += other_digits;
        card_number_local /= 100;
    }
    checksum = sum_product_digit + sum_other_digits;
    // Debug for result
    // printf("%li\n",checksum);

    // If the total’s last digit is 0 (or, put more formally,
    // if the total modulo 10 is congruent to 0), the number is valid!
    long last_digit_checksum = checksum % 10;
    // Debug for result
    // printf("%li\n",last_digit_checksum);

    // First 2 digits of the card

    long firsttwo = firsttwodigits(card_number);
    long first = firsttwo / 10;

    // Debug for result
    //printf("%li\n",firsttwodigits(card_number));
    //printf("%li\n",first);

    if (last_digit_checksum == 0 && card_number > 1000000000000)
    {
        if (first == 4)
        {
            printf("VISA\n");
        }
        else if (firsttwo == 34 || firsttwo == 37)
        {
            printf("AMEX\n");
        }
        else if (firsttwo == 51 || firsttwo == 52 || firsttwo == 53 || firsttwo == 54 || firsttwo == 55)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}

// First 2 digits of the card
long firsttwodigits(long num)
{
    long localnum = num;
    while
    (localnum >= 100)
    {
        localnum /= 10;
    }
    return localnum;
}