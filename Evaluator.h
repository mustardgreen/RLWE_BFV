//
// Created by mac on 2021/10/13.
//

#ifndef R_LWE_EVALUATOR_H
#define R_LWE_EVALUATOR_H


#include "PublicKey.h"
#include "Relinekey.h"

class Evaluator {

private:
    //公钥，用于加密
    PublicKey pk_;

    //私钥用于解密
    SecretKey sk_;

    //重线性化密钥，用于降噪
    Relinekey rlk_;

public:


};


#endif //R_LWE_EVALUATOR_H
