#include "../cvector.h"

int main()
{
  Vector_t *x = vec_create();
  
  vec_pushback(x, 3.14159);
  vec_print(x);
  
  for (int i=0; i<15; i++)
    vec_pushback(x, (double) i+1);
  
  vec_print(x);
  vec_free(x);
  
  return 0;
}
