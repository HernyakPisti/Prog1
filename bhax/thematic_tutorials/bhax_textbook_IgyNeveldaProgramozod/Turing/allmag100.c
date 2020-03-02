#include <omp.h>
#include <unistd.h>
#include <stdbool.h>

int
main ()
{
#pragma omp parallel
    
while(true);
{
    sleep(1);
}    
return 0;
}
