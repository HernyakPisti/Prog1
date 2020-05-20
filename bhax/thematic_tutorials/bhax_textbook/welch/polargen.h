#ifndef POLARGEN__H
#define POLARGEN__H

#include <cstdlib>
#include <cmath>
#include <ctime>

class PolarGen
{
public:
  PolarGen ()
  {
    nincsTarolt = true; //konsrutkor igazra inicalizál
    std::srand (std::time (NULL)); //inicaizál egy random számot
  }
   ~PolarGen ()
  {
  }
  double kovetkezo ();

private:
  bool nincsTarolt;
  double tarolt;

};

#endif
