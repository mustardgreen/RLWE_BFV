//
// Created by mac on 2021/8/9.
//

#ifndef R_LWE_DECRYPTOR_H
#define R_LWE_DECRYPTOR_H


#include <utility>

#include "Ring.h"
#include "PublicKey.h"
#include "Encryptor.h"
#include "Parameters.h"
#include "SecretKey.h"
class Decryptor {

    friend class Parameters;
    SecretKey sk_;

    Ring LPR_ES_Decrypt();

public:
    explicit Decryptor(SecretKey sk):sk_(std::move(sk)){};

    Plaintext decrypt(Ciphertext ciphertext){
        Ring ct_0=ciphertext.getCt()[0];
        Ring ct_1=ciphertext.getCt()[1];

        Plaintext plaintext;
//! LPR.ES.Decrypt(sk,ct):      set s = sk , c0 = ct[0] , c1 = ct[1]
//!                             compute [ ⌊ (t·[c0+c1·s]_𝑞 ] / 𝑞 ]_t
        ct_1=ct_1*sk_.getSk();

        int T=Parameters::modulus_T;
        int Q=Parameters::modulus_Q;

        ct_1=ct_1+ct_0;     //这里ct_1该 mod q 了

        ct_1=ct_1.Mod(Q);

        ct_1=ct_1* (T);

        ct_1=ct_1/(Q);
        ct_1=ct_1.Mod(T);
//        ct_1=ct_1.Mod(Parameters::modulus_Q);
//        ct_1=ct_1* (Parameters::modulus_T);
//        ct_1=ct_1/(Parameters::modulus_Q);
//        ct_1=ct_1.Mod(Parameters::modulus_T);
        return Plaintext(ct_1);
    };
};


#endif //R_LWE_DECRYPTOR_H
