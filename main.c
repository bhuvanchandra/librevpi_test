#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "revpi.h"

int main(void) {
  int ret = 0;
  revpi_peripheral o_1, i_1, i_2, do_pullupdown, ai_1;

  sprintf(o_1.pin_name, "%s", "O_1");
  sprintf(do_pullupdown.pin_name, "%s", "OutputPushPull");

  sprintf(i_1.pin_name, "%s", "I_1");
  sprintf(i_2.pin_name, "%s", "I_2");

  sprintf(ai_1.pin_name, "%s", "InputValue_1");

  revpi_init(&o_1);
  revpi_init(&do_pullupdown);
  revpi_init(&i_1);
  revpi_init(&i_2);
  revpi_init(&ai_1);

  uint16_t pullupdown_config = 0xF; /* all 16 pins push pull enabled */

  /* FIXME: this setting is not reflected */
  revpi_set_do_push_pull(&do_pullupdown, pullupdown_config);

  revpi_set_do_level(&o_1, 1);
  sleep(3);
  if ((revpi_get_di_level(&i_1) == 0) || (revpi_get_di_level(&i_2) == 0)) {
    printf("got enough vaccum :), stop the suction pump\n");
    revpi_set_do_level(&o_1, 0);
  } else {
    printf("timed out :(\n");
    revpi_set_do_level(&o_1, 0);
  }

  while(1) {
      printf("AI_1 value: %d\n", revpi_get_ai_value(&ai_1));
      sleep(1);
 }

  return 0;
}
