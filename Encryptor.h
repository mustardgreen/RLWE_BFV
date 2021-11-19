//
// Created by mac on 2021/8/9.
//

#ifndef R_LWE_ENCRYPTOR_H
#define R_LWE_ENCRYPTOR_H


#include "Ring.h"
#include "PublicKey.h"
#include "Ciphertext.h"
#include "Plaintext.h"
#include "Parameters.h"
#include <iostream>
using namespace std;
class Encryptor {


    PublicKey pk_;
    Ring u;
    Ring e1;
    Ring e2;

public:
    Encryptor(PublicKey pk):pk_(pk) {
        u.random_Ring(Parameters::size_noise);
        e1.random_Ring(Parameters::size_noise);
        e2.random_Ring(Parameters::size_noise);

    };
    //! LPR.ES.Encrypt(pk,m):       m ∈ R_t , let p0 = pk[0] , p1 = pk[1] , sample u,e1,e2 ←— X
    //!                             return ct[2] = ( [p0·u+e1+Δ·m]_q , [p1·u+e2]_q )

    Ciphertext encrypt(Plaintext m){
        Ciphertext ct;
        Ring tmp1,tmp2;
        tmp1=pk_.getPk()[0];
        tmp1=tmp1*u;
        tmp1=tmp1+e1;
        tmp2=m.getPlaintext();
        tmp2=tmp2* (int)Parameters::delta;
        tmp1=tmp1+tmp2;
        Ring &CT0= const_cast<Ring &>(ct.getCt()[0]);
        CT0 = tmp1.Mod(Parameters::modulus_Q);

        //ct.getCt()[0]=pk_.getPk()[0]*u+e1+m.getPlaintext()*delta;   //mod q

        tmp1=pk_.getPk()[1];
        tmp1=tmp1*u;
        tmp1=tmp1+e2;
        Ring &CT1= const_cast<Ring &>(ct.getCt()[1]);
        CT1 = tmp1.Mod(Parameters::modulus_Q);
        //ct.getCt()[1]=pk_.getPk()[1]*u+e2;                          //mod q
        return ct;
    };

};


#endif //R_LWE_ENCRYPTOR_H
