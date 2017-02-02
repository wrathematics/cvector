#include "../cvector.h"


int main(int argc, char **argv)
{
  const int TOP = (int) atof(argv[1]);
  
  Vector_t *x = vec_create();
  for (int i=0; i<TOP; i++)
    vec_pushback(x, (double) i+1);
  
  printf("%.3e\n", VEC_DATA(x)[VEC_SIZE(x)-1]);
  
  return 0;
}
