# cvector

A dynamic vector written in C99.  The implementation is header-only, so the "methods" should inline with any decent compiler.  There is still various size-checking overhead, but the performance should be fairly similar to C++ `std::vector`.

Yes I actually needed this for something.



## Installation

Just copy `cvector.h` over to wherever and include it via `#include "cvector.h"`.  The license is extremely permissive (see License section below).

The default storage type is `double`.  Change the definition of `VecData_t` in the header as appropriate for your needs.  For printing, change the macros `VECTOR_PRINT_FORMAT` and `VECTOR_N_PER_LINE` as well.



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



## API

The "public" API is:

```c
Vector_t* vec_create();
int vec_pushback(Vector_t *const x, const VecData_t value);
int vec_set(Vector_t *x, const int index, const VecData_t value);
void vec_free(Vector_t *x);
int vec_resize(Vector_t *x, const int newsize);
void vec_print(Vector_t *x);
```

The "getters" are:

```c
VEC_SIZE(x)
VEC_DATA(x)
```

Return values are:

```c
VECTOR_OK       //  0
VECTOR_OOM      // -1
VECTOR_BADINDEX // -2
```

See the examples and benchmarks for example usage.



## Performance

The vector is meant to be grown via pushbacks.  The initial size is 8 elements, and thereafter, the storage is enlarged by a growth factor of 1.5.

To test the run time performance, we use two simple examples provided in the `bench/` subtree of the project source.  Each is tested with 1e8 elements.

The run time performance is comparable to its `std::vector` counterpart.  With gcc/g++:

```
# cvector
real  0m0.335s
user  0m0.164s
sys   0m0.168s

# std::vector
real  0m0.813s
user  0m0.400s
sys   0m0.412s
```


And with clang/clang++:

```
# cvector
real  0m1.014s
user  0m0.812s
sys   0m0.200s

# std::vector
real  0m0.910s
user  0m0.468s
sys   0m0.440s
```



## License

This project is licensed under the "0-clause" BSD.  Basically I don't care how or why you use it, but it comes with no warranty of any kind.

A longer explanation is that it is subject to the usual restrictions of the 2-Clause BSD license, except that you do not have to retain copyright notices on source or binary copies.  Note that this should not be construed as a dereliction of copyright or "public domaining".  It's just meant to be extremely permissive.
