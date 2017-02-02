/* 
  Copyright (C) 2017 by Drew Schmidt <wrathematics@gmail.com>
  
  Permission to use, copy, modify, and/or distribute this software for any
  purpose with or without fee is hereby granted.
  
  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
  REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
  AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
  INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
  LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
  OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
  PERFORMANCE OF THIS SOFTWARE
*/

#ifndef __CVECTOR_H__
#define __CVECTOR_H__


#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


#define __VECTOR_INITIAL_SIZE 8
#define __VECTOR_GROWTH_FACTOR 1.5

#define VEC_CAPACITY(x) (x->capacity)
#define VEC_SIZE(x) (x->size)
#define VEC_DATA(x) (x->data)

#define VECTOR_OK       0
#define VECTOR_OOM      -1
#define VECTOR_BADINDEX -2

typedef struct Vector
{
  int capacity;
  int size;
  double *data;
} Vector_t;



static inline int __vec_expand_capacity(Vector_t *const x, const int newcapacity);
static inline Vector_t* vec_create();
static inline int vec_pushback(Vector_t *const x, const double value);
static inline int vec_set(Vector_t *x, const int index, const double value);
static inline void vec_free(Vector_t *x);
static inline int vec_resize(Vector_t *x, const int newsize);
static inline void vec_print(Vector_t *x);

static inline Vector_t* vec_create()
{
  Vector_t *x = malloc(sizeof(*x));
  
  VEC_SIZE(x) = 1;
  __vec_expand_capacity(x, __VECTOR_INITIAL_SIZE);
  
  return x;
}

static inline int __vec_expand_capacity(Vector_t *const x, const int newcapacity)
{
  void *realloc_ptr;
  // int newcapacity = VEC_CAPACITY(x) * __VECTOR_GROWTH_FACTOR;
  realloc_ptr = realloc(x->data, newcapacity * sizeof(*(x->data)));
  if (realloc_ptr == NULL)
  {
    vec_free(x);
    return VECTOR_OOM;
  }
  
  VEC_DATA(x) = realloc_ptr;
  VEC_CAPACITY(x) = newcapacity;
  return VECTOR_OK;
}

static inline int vec_pushback(Vector_t *const x, const double value)
{
  if (VEC_SIZE(x) == VEC_CAPACITY(x))
  {
    const int newsize = VEC_CAPACITY(x) * __VECTOR_GROWTH_FACTOR;
    int check = __vec_expand_capacity(x, newsize);
    if (check)
      return check;
  }
  
  VEC_DATA(x)[VEC_SIZE(x) - 1] = value;
  VEC_SIZE(x)++;
  
  return VECTOR_OK;
}

static inline int vec_set(Vector_t *x, const int index, const double value)
{
  if (index < VEC_SIZE(x) - 1)
  {
    VEC_DATA(x)[index] = value;
    return VECTOR_OK;
  }
  else
    return VECTOR_BADINDEX;
}

static inline void vec_free(Vector_t *x)
{
  free(VEC_DATA(x));
  VEC_DATA(x) = NULL;
  free(x);
}

static inline int vec_resize(Vector_t *x, const int newsize)
{
  if (newsize <= VEC_CAPACITY(x))
  {
    VEC_SIZE(x) = newsize;
    return VECTOR_OK;
  }
  else
  {
    int check = __vec_expand_capacity(x, newsize);
    return check;
  }
}

static inline void vec_print(Vector_t *x)
{
  const int n_per_line = 7;
  
  if (VEC_SIZE(x) == 0)
    return;
  
  for (int i=0; i<VEC_SIZE(x)-1; i+=n_per_line)
  {
    printf("  ");
    for (int j=0; j<n_per_line && i+j<VEC_SIZE(x)-1; j++)
      printf("%8.3f ", VEC_DATA(x)[i+j]);
    
    printf("\n");
  }
  
  putchar('\n');
}


#endif
