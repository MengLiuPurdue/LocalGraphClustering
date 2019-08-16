#include "include/SimpleLocal_weighted_c_interface.h"
#include "include/SimpleLocal_weighted.h"

int64_t SimpleLocal_weighted64(int64_t n, int64_t nR, int64_t* ai, int64_t* aj, double* a, double* degrees, int64_t offset, int64_t* R, int64_t* ret_set, double delta)
{
    graph<int64_t,int64_t> g(ai[n],n,ai,aj,a,offset,degrees);
    return g.SimpleLocal_weighted(nR,R, ret_set, delta);
}

uint32_t SimpleLocal_weighted32(uint32_t n, uint32_t nR, uint32_t* ai, uint32_t* aj, double* a, double* degrees, uint32_t offset, uint32_t* R, uint32_t* ret_set, double delta)
{
    graph<uint32_t,uint32_t> g(ai[n],n,ai,aj,a,offset,degrees);
    return g.SimpleLocal_weighted(nR,R, ret_set, delta);
}

uint32_t SimpleLocal_weighted32_64(uint32_t n, uint32_t nR, int64_t* ai, uint32_t* aj, double* a, double* degrees, uint32_t offset, uint32_t* R, uint32_t* ret_set, double delta)
{
    graph<uint32_t,int64_t> g(ai[n],n,ai,aj,a,offset,degrees);
    return g.SimpleLocal_weighted(nR,R, ret_set, delta);
}

int64_t STAGEFLOW_weighted(int64_t* ai, int64_t* aj, double* a, double* degrees, double delta, int64_t* R, int64_t* S, int64_t* ret_set, int64_t nR, int64_t nS, int64_t n)
{
	unordered_map<int64_t,int64_t> fullyvisited, S_map;
    unordered_map<int64_t,int64_t> R_map;
    int64_t actual_length;
	graph<int64_t,int64_t> g(ai[n],n,ai,aj,a,0,degrees);
    init_fullyvisited_R(fullyvisited, R_map, nR, R);
    double total_degree = std::accumulate(degrees,degrees+n,0);
    pair<double, double> set_stats = get_stats_weighted(fullyvisited,fullyvisited.size());
    double alpha = 1.0 * get<1>(set_stats) / min(get<0>(set_stats), total_degree - get<0>(set_stats));
    double fR = 1.0 * get<0>(set_stats) / (total_degree - get<0>(set_stats));
    double alph0;
    double beta = alpha * (fR + delta);
    alph0 = alpha;

    clear_map<int64_t,int64_t>(S);
    g.STAGEFLOW_weighted(delta, alpha, beta, fullyvisited, R_map, S);

    copy_results<int64_t,int64_t>(S,ret_set,&actual_length);

    return actual_length;
}