#include <stdio.h>
#include "version.h"

int main() {
  printf("Hello world! (%s, %s)\n", REPO_DATE, REPO_REVISION);
  return 0;
}
