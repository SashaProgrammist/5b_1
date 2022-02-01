#include "libs/data_structures/vector/vector.h"
#include <stdint.h>

int main() {
    vector v = createVector(0);

    printf("%d", v.data);

    return 0;
}
