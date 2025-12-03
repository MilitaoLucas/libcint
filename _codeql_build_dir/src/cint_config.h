#include "cint.h"

#define HAVE_EXPL
#define HAVE_SQRTL
/* #undef HAVE_FABSL */

#define HAVE_QUADMATH_H

/* #undef WITH_RANGE_COULOMB */

#ifndef M_PI
#define M_PI            3.1415926535897932384626433832795028
#endif
#define SQRTPI          1.7724538509055160272981674833411451

// Complex number compatibility for C++
#ifdef __cplusplus
#include <complex>
typedef std::complex<double> double_complex;
#define MAKE_COMPLEX(re, im) double_complex(re, im)
#else
#include <complex.h>
typedef double complex double_complex;
#define MAKE_COMPLEX(re, im) ((re) + (im) * _Complex_I)
#endif

// Function pointer types for c2s transformations
typedef void (*CINTc2s_func_real)(double *out, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);
typedef void (*CINTc2s_func_complex)(double_complex *out, double *gctr, FINT *dims, CINTEnvVars *envs, double *cache);
// For 2e spinor transformations, e2 function takes double* as second arg
typedef void (*CINTc2s_2e2_func)(double_complex *out, double *opij, FINT *dims, CINTEnvVars *envs, double *cache);

// ng[*]
#define IINC            0
#define JINC            1
#define KINC            2
#define LINC            3
#define GSHIFT          4
#define POS_E1          5
#define POS_E2          6
#define SLOT_RYS_ROOTS  6
#define TENSOR          7

#define EXPCUTOFF       60
#ifndef MIN_EXPCUTOFF
// ~ 1e-15
#define MIN_EXPCUTOFF   40
#endif

#define OF_CMPLX        2

#define GRID_BLKSIZE    104
