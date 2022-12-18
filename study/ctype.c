#include <stdio.h>
#include <ctype.h>

int main(void){
    int a = 0, b = 0, c = 0,
        d = 0, e = 0, f = 0,
        g = 0, h = 0, i = 0;

    char z[2] = ""; char x[2] = "";

    a = isalnum('10');  printf("a : %d \n", a);
    b = isalnum('A');   printf("b : %d \n", b);

    g = isalnum('%');   printf("g : %d \n", g);

    c = islower('A');   printf("c : %d \n", c);
    d = islower('a');   printf("d : %d \n", d);
    e = isupper('A');   printf("e : %d \n", e);
    f = isupper('a');   printf("f : %d \n", f);

    h = isdigit('7');   printf("h : %d \n", h);
    i = isspace('8');   printf("i : %d \n", i);

    z[0] = tolower('H');    printf("z : %s \n", z);
    x[0] = toupper('i');    printf("x : %s \n", x);

    return 0;

}