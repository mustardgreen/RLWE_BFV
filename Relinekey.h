//
// Created by mac on 2021/10/12.
//

#ifndef R_LWE_RELINEKEY_H
#define R_LWE_RELINEKEY_H


#include "Ring.h"
#include "SecretKey.h"

class Relinekey {

private:
    Ring rlk[2];
    Ring e;
public:
    Relinekey(SecretKey key){
        rlk[1].random_Ring(Parameters::size_big);   //a ←— R_q
        e.random_Ring(Parameters::size_noise);        //e ←— X
        rlk[0]=rlk[1]*key.getSk()+e;
        rlk[0]=rlk[0].Mod(Parameters::modulus_Q);
        rlk[0]=rlk[0]* (-1);

    };
    //! RelinearizationKeyGen(sk):    set s = sk , sample a ←— R_q , e ←— X
    //!                             output rlk[2] = ( [-(a·s+e)+s^2]_q , a ).


    Relinekey& operator=(const Relinekey& pk)
    {
        this->rlk[0]=pk.getPk()[0];
        this->rlk[1]=pk.getPk()[1];
        return *this;
    }


    const Ring *getPk() const {
        return rlk;
    }

    const Ring &getE() const {
        return e;
    }

};


#endif //R_LWE_RELINEKEY_H
