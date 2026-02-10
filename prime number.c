#include <stdio.h>

int main() {
    int x, n;

    printf("Enter the value of x: ");
    scanf("%d", &x);

    if (x <= 1) {
        printf("Not a prime number");
    } else {
        for (n = 2; n < x; n++) {
            if (x % n == 0) {
                break;
            }
        }

        if (n == x)
            printf("%d is prime", x);
        else
            printf("%d is not prime", x);
    }

    return 0;
}
