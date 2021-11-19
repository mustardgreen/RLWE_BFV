//
// Created by mac on 2021/8/9.
//

#ifndef R_LWE_SECRETKEY_H
#define R_LWE_SECRETKEY_H


#include "Ring.h"
#include "Parameters.h"
class SecretKey {
    Ring sk_;
public:
    //? __attribute__ 的作用：内存地址紧凑对齐
    Ring getSk() const {
        return sk_;
    }

    SecretKey(){
        sk_.random_Ring(5*Parameters::size_noise);
    };
    SecretKey(Ring sk){
        sk_=sk;
    };
    //! LPR.ES.SecretKeyGen(1^λ):   sample   s ←— X
    //!                             output  sk == s
    Ring LPR_ES_SecretKeyGen();


};


#endif //R_LWE_SECRETKEY_H
