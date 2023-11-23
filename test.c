#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

// void binary(float num) {
//     int n = *(int *) &num; //Evil bit hack from Quake3 Q_sqrt function
//     int size = sizeof(n) * 8; 
//     char *s = malloc(1 + size); //A string which can hold 32 characters
//     s[size] = '\0';
//     int index = size - 1;
//     while(index >= 0) {
//         if (n & 1)
//             *(s + index) = '1';
//         else
//             *(s + index) = '0';
//         n >>= 1;
//         index--;
//     }
//     printf("%s\n", s);
//     free(s);
// }
void reverse(char* str, int len) 
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
int intToStr(int x, char str[], int d) 
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
 
    reverse(str, i); 
    str[i] = '\0'; 
    return i; 
} 
 
// Converts a floating-point/double number to a string. 
void ftoa(double n, char* res, int afterpoint) 
{ 
    // Extract integer part 
    int ipart = (int)n; 
 
    // Extract floating part 
    double fpart = n - (double)ipart; 
 
    // convert integer part to string 
    int i = intToStr(ipart, res, 0); 
 
    // check for display option after point 
    if (afterpoint != 0) { 
        res[i] = '.'; // add dot 
 
        // Get the value of fraction part upto given no. 
        // of points after dot. The third parameter 
        // is needed to handle cases like 233.007 
        fpart = fpart * pow(10, afterpoint); 
        fpart = round(fpart);
 
        intToStr((int)fpart, res + i + 1, afterpoint); 
    } 
} 
 

void main() {
    char res[20]; 
    float n = 233.007; 
    ftoa(n, res, 6);
    // printf("printf result: %.7f\n", n); 
    printf("\"%s\"\n", res);
    sprintf(res, "%f", n);
    printf("\"%s\"\n", res);


    // float x = -10.5;
    // binary(x);

}
