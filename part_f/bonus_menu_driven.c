/**
 * bonus_menu_driven.c - Part F: Modular Programming with Functions
 * Comprehensive Menu-Driven Program
 */

#include <stdio.h>

// Function prototypes
long long square_val(int x) { return (long long)x * x; }
long long cube_val(int x) { return (long long)x * x * x; }
long long power_val(int base, int exp) {
    long long res = 1;
    for (int i = 0; i < exp; i++) res *= base;
    return res;
}
unsigned long long factorial_val(int n) {
    unsigned long long f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    return f;
}
int is_prime_func(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
int is_palindrome_func(int n) {
    int orig = n, rev = 0;
    if (n < 0) return 0;
    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return orig == rev;
}

// Array functions
double array_sum(const int arr[], int n) {
    double s = 0;
    for (int i = 0; i < n; i++) s += arr[i];
    return s;
}
int array_max(const int arr[], int n) {
    int m = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > m) m = arr[i];
    return m;
}
int array_min(const int arr[], int n) {
    int m = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] < m) m = arr[i];
    return m;
}
int array_search(const int arr[], int n, int key) {
    for (int i = 0; i < n; i++) if (arr[i] == key) return i;
    return -1;
}
void array_bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

void math_functions_menu(void) {
    int x, y;
    printf("\n--- Math Functions ---\n");
    printf("Enter an integer: ");
    if (scanf("%d", &x) != 1) return;
    printf("Square of %d: %lld\n", x, square_val(x));
    printf("Cube of %d:   %lld\n", x, cube_val(x));
    if (x >= 0 && x <= 20) {
        printf("Factorial of %d: %llu\n", x, factorial_val(x));
    }
    printf("Enter exponent for power calculation (%d^exp): ", x);
    if (scanf("%d", &y) == 1 && y >= 0) {
        printf("%d^%d = %lld\n", x, y, power_val(x, y));
    }
}

void number_check_menu(void) {
    int n;
    printf("\n--- Number Property Functions ---\n");
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) return;
    printf("Is Prime:      %s\n", is_prime_func(n) ? "YES" : "NO");
    printf("Is Palindrome: %s\n", is_palindrome_func(n) ? "YES" : "NO");
}

void array_functions_menu(void) {
    int n, arr[100];
    printf("\n--- Modular Array Operations ---\n");
    printf("Enter number of elements (1-100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) return;

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) return;
    }

    double sum = array_sum(arr, n);
    printf("Array Sum:     %.0f\n", sum);
    printf("Array Average: %.2f\n", sum / n);
    printf("Array Maximum: %d\n", array_max(arr, n));
    printf("Array Minimum: %d\n", array_min(arr, n));

    int key;
    printf("Enter value to search: ");
    if (scanf("%d", &key) == 1) {
        int idx = array_search(arr, n, key);
        if (idx != -1) printf("Element %d found at index %d.\n", key, idx);
        else printf("Element %d NOT found in array.\n", key);
    }

    array_bubble_sort(arr, n);
    printf("Sorted Array (Ascending): ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int choice;
    do {
        printf("\n============================================\n");
        printf("  Part F: Modular C Functions Hub           \n");
        printf("============================================\n");
        printf("1. Mathematical Functions (Square, Cube, Fact)\n");
        printf("2. Property Checker Functions (Prime, Palindrome)\n");
        printf("3. Array Processing Functions (Stats, Search, Sort)\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: math_functions_menu(); break;
            case 2: number_check_menu(); break;
            case 3: array_functions_menu(); break;
            case 4: printf("Exiting Part F Hub. Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
