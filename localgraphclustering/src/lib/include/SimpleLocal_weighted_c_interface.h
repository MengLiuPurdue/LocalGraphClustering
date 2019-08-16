#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

    int64_t SimpleLocal_weighted64(int64_t n, int64_t nR, int64_t* ai, int64_t* aj, double* a, double* degrees, int64_t offset, int64_t* R, int64_t* ret_set, double delta);
    uint32_t SimpleLocal_weighted32(uint32_t n, uint32_t nR, uint32_t* ai, uint32_t* aj, double* a, double* degrees, uint32_t offset, uint32_t* R, uint32_t* ret_set, double delta);
    uint32_t SimpleLocal_weighted32_64(uint32_t n, uint32_t nR, int64_t* ai, uint32_t* aj, double* a, double* degrees, uint32_t offset, uint32_t* R, uint32_t* ret_set, double delta);
    
    int64_t STAGEFLOW_weighted(int64_t* ai, int64_t* aj, double* a, double* degrees, double delta, double alpha, double beta, 
    	int64_t* fullyvisited, int64_t* R, int64_t* S, int64_t* S_ret, int64_t nf, int64_t nR, int64_t nS, int64_t n);
#ifdef __cplusplus
}
#endif

