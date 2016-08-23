/**
 * 
 *   Bad Credit
 *   credit.c
 *   hacker1 for cs50
 * 
 *   Filippov Anton
 * 
 * 
 * Prompts the user for a credit card number and then reports (via printf) whether it is a valid 
 * American Express, MasterCard, or Visa card number, per the definitions of each’s format herein
 * 
 */


#include<stdio.h>
#include<cs50.h>

string whatCardSys(int card[]);
int algLuhn(int card_len, int card[]);

int main(void)
{
    
    printf("Please input your card number\n");
    long long num = GetLongLong();
    int num_len = 1;
    long long n = 10;
    
    // Узнаем количество цифр в номере карты
    //we need lenth of card number
    do
    {
        n = n * 10;
        num_len++;
    }
    while(n < num);
    
    
    //Создаем массив цифр из номера карты
    //do array from card number
    int num_array[num_len];
    for(int i = num_len - 1; i >= 0; i--)
    {
        num_array[i] = num % 10;
        num = num / 10;
    }
    
    
    // Запускаем алгоритм Луна 
    // Go Luhn algorithm
    if(algLuhn(num_len, num_array) == 0)
    {
        printf("INVALID\n");
        return 0;
    }
    
    // Проверяем какая система
    // whot card System
    printf("%s\n", whatCardSys(num_array));
    return 0;
}



/**
 *  algLuhn
 * 
 *  This function analise card number with luhn algorithm
 *  
*/


int algLuhn(int card_len, int card[])
{
    int luhn_rez = 0;
    if(card_len % 2 == 0)
    {
        for (int i = 0, p = 0; i < card_len; i ++)
        {
            p = card[i];
            if(i % 2 == 0)
            {
                p = p * 2;
                if (p > 9)
                    p = p - 9;
            }
            luhn_rez = luhn_rez + p;
    
        }
    }
    else
    {
        for (int i = 0, p = 0; i < card_len; i ++)
        {
            p = card[i];
            if(i % 2 != 0)
            {
                p = p * 2;
                if (p > 9)
                    p = p - 9;
            }
            luhn_rez = luhn_rez + p;
    
        }
    }
    
    if(luhn_rez % 10 == 0)
        return 1;
    
    return 0;
}


/**
 *  whatCardSys
 * 
 *  this function analyzes the first digit of the card
 *  and return name of card system.
*/

string whatCardSys(int card[])
{
    if (card[0] == 4)
    {
        return "VISA";    
    }
    else if (card[0] == 5)
    {
        return "MASTERCARD";    
    }
    else if (card[0] == 3)
    {
        return "AMEX";    
    }
    else{
        return "INVALID";    
    }

}
