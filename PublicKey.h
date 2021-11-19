//
// Created by mac on 2021/8/9.
//

#ifndef R_LWE_PUBLICKEY_H
#define R_LWE_PUBLICKEY_H


#include "Ring.h"
#include "SecretKey.h"
#include "Parameters.h"
class PublicKey {

private:
    Ring pk_[2];
    Ring e;
public:
    PublicKey(SecretKey key){
        pk_[1].random_Ring(Parameters::size_big);   //a ←— R_q
        e.random_Ring(Parameters::size_noise);        //e ←— X
        pk_[0]=pk_[1]*key.getSk()+e;
        pk_[0]=pk_[0].Mod(Parameters::modulus_Q);
        pk_[0]=pk_[0]* (-1);

    };
    //! LPR.ES.PublicKeyGen(sk):    set s = sk , sample a ←— R_q , e ←— X
    //!                             output pk[2] = ( [-(a·s+e)]_q , a ).


    PublicKey& operator=(const PublicKey& pk)
    {
        this->pk_[0]=pk.getPk()[0];
        this->pk_[1]=pk.getPk()[1];
        return *this;
    }


    const Ring *getPk() const {
        return pk_;
    }

    const Ring &getE() const {
        return e;
    }



};


#endif //R_LWE_PUBLICKEY_H
