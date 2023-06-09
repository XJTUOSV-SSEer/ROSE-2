#ifndef KUPRF_H
#define KUPRF_H

#include "common.h"
#include <string>
#include <gmpxx.h>
extern "C"
{
#include <pthread.h>
#include <relic/relic.h>
};

//key updatable PRF
//Key Size of KUPRF: 32
//Result Size of KUPRF: 33
class KUPRF
{
public:
    KUPRF()=default;

    ~KUPRF()=default;

    int key_gen(unsigned char *key_out);

    int Eval(unsigned char *out, const unsigned char *key, const std::string &keyword,
             const int id, OpType op); //out : P()
    
    int Eval(unsigned char *out, const unsigned char *key, const std::string &data);

    int update_token(unsigned char *out, const unsigned char *K1, const unsigned char *K2);//out : delta_k,其中K2是新的K

    int update(unsigned char *out, const unsigned char *token, const unsigned char *data);//out : new P, token : delta, data : old_P

    int mul(unsigned char *out, const unsigned char *K1, const unsigned char *K2);//传递

    static void init();

    static void clean();

};

#endif //SSE_2018_KUPRF_H
