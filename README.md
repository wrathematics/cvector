# cvector

A dynamic vector written in C99.  The implementation is header-only, so the "methods" should inline with any decent compiler.  There is still various size-checking overhead, but the performance should be fairly similar to C++ `vector<double>`.

Yes I actually needed this for something.



## Examples

```c
#include "cvector.h"

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
```

Output:

```
3.142 

3.142    1.000    2.000    3.000    4.000    5.000    6.000 
7.000    8.000    9.000   10.000   11.000   12.000   13.000 
14.000   15.000 
```


## License

This project is licensed under the "0-clause" BSD.  Basically I don't care how or why you use it, but it comes with no warranty of any kind.
