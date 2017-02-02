# cvector

A dynamic vector written in C99.  The implementation is header-only, so the "methods" should inline with any decent compiler.  There is still various size-checking overhead, but the performance should be fairly similar to C++ `std::vector<double>`.

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



## Performance

The vector is meant to be grown via pushbacks.  The initial size is 8 elements, and thereafter, the storage is enlarged by a growth factor of 1.5.

To test the run time performance, we use two simple examples provided in the `bench/` subtree of the project source.  Each is tested with 1e8 elements.

The run time performance is comparable to its `std::vector` counterpart.  With gcc/g++:

```
# cvector
real	0m0.335s
user	0m0.164s
sys 	0m0.168s

# std::vector
real	0m0.813s
user	0m0.400s
sys	  0m0.412s
```


And with clang/clang++:

```
# cvector
real	0m1.014s
user	0m0.812s
sys	  0m0.200s

# std::vector
real	0m0.910s
user	0m0.468s
sys 	0m0.440s
```



## License

This project is licensed under the "0-clause" BSD.  Basically I don't care how or why you use it, but it comes with no warranty of any kind.
