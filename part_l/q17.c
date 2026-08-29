/* part_l/q17.c
 * Create a structure containing a union.
 * A common pattern: a record with a "type tag" plus a union of possible
 * values. Here a Sensor reading is either an int or a float.
 */
#include <stdio.h>

struct Sensor {
    int is_float;      /* tag: 0=int, 1=float */
    union {
        int i;
        float f;
    } value;
};

int main(void) {
    struct Sensor s;
    s.is_float = 1;
    s.value.f = 21.5f;
    if (s.is_float)
        printf("Sensor (float): %.2f\n", s.value.f);
    else
        printf("Sensor (int): %d\n", s.value.i);
    return 0;
}
