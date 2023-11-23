#include "helpers.h"
#include <stdio.h>
#include <math.h>



int int_to_str(int x, char str[], int d) 
{ 
    int i = 0; 
    while (x) { 
        str[i++] = (x % 10) + '0'; 
        x = x / 10; 
    } 
 
    // If number of digits required is more, then 
    // add 0s at the beginning 
    while (i < d) 
        str[i++] = '0'; 
 
    revstr(str, i); 
    // str[i] = '\0'; 
    return i; 
} 

void revstr(char *str, int len)  
{  
     int i = 0, j = len - 1, temp; 
    while (i < j) { 
        temp = str[i]; 
        str[i] = str[j]; 
        str[j] = temp; 
        i++; 
        j--; 
    } 
}  

void ftoa(double n, char* res, int afterpoint) 
{ 
    // Extract integer part 
    int ipart = (int)n; 
 
    // Extract floating part 
    double fpart = n - (double)ipart; 
 
    // convert integer part to string 
    int i = int_to_str(ipart, res, 0); 
 
    // check for display option after point 
    if (afterpoint != 0) { 
        res[i] = '.'; // add dot 
 
        // Get the value of fraction part upto given no. 
        // of points after dot. The third parameter 
        // is needed to handle cases like 233.007 
        fpart = fpart * pow(10, afterpoint); 
        fpart = round(fpart);
 
        int_to_str((int)fpart, res + i + 1, afterpoint); 
    } 
} 
