#include <iostream>
#include "polargen.h"

int
main (int argc, char **argv)
{
  PolarGen pg; //készítünk egy polargent típust

  for (int i = 0; i < 10; ++i)
    std::cout << pg.kovetkezo () << std::endl; //hívjuk a tagfügvényt amivel random számot generálunk

  return 0;
}
