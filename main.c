#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "revpi.h"

int main(void) {
  revpi_peripheral o_1, i_1;
  if ((revpi_init(&o_1) < 0) || (revpi_init(&i_1) < 0)) {
    printf("failed to init\n");
  } else {
    revpi_set_do_level(&o_1, 1);
    sleep(1);
    printf("I_1 pin state: %d\n", revpi_get_di_level(&i_1));
  }

  return 0;
}
