#include <stdio.h>
#include "version.h"

int main() {
  printf("Hello world! (%s)\n", REPO_REVISION);
  return 0;
}
