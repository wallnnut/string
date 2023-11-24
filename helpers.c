#include "helpers.h"
#include <stdio.h>
#include <math.h>



int int_to_str(int q, char str[], int d) 
{ 
    int x = q;
    if (q < 0) {
        x *= -1;
    }
    int i = 0; 
    while (x) { 
        str[i++] = (x % 10) + '0'; 
        x = x / 10; 
    } 
 
    while (i < d) 
        str[i++] = '0'; 
    if (q < 0) {
        str[i] = '-';
        i++;
    }
    revstr(str, i);
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

void ftoa(double q, char* res, int afterpoint) 
{
    double n = q;
   
    int ipart = (int)n;
    
    double fpart = n - (double)ipart;
    if (q < 0) {
        fpart *= -1;
    }
    int i = int_to_str(ipart, res, 0); 
    
    if (afterpoint != 0) { 
        res[i] = '.'; 
 
        fpart = fpart * pow(10, afterpoint); 
        fpart = round(fpart);
 
        int_to_str((int)fpart, res + i + 1, afterpoint); 
        
    } 
} 
