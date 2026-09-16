/* Find the summation of n consecutive numbers.
Input: 5
Output: 15
*/
#include <stdio.h>

// Normal Recursion
// int fun(int n){
//     if(n>0){
//         return fun(n-1) + n;
//     }
//     return 0;
// }

// Recursion Using Static Variable
int x = 0;
int fun(int n){
    // static int x = 0;
    if(n>0){
        x++;
        return fun(n-1) + x;
    }
    return 0;
}

int main(){
    int a = 5;
    printf("%d\n", fun(a));
}