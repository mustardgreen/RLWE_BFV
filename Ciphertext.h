//
// Created by mac on 2021/8/10.
//

#ifndef R_LWE_CIPHERTEXT_H
#define R_LWE_CIPHERTEXT_H


#include "Ring.h"

class Ciphertext {


public:
    Ring ct_[3];
    Ciphertext(){};


    const Ring *getCt() const {
        return ct_;
    }

    Ciphertext add(Ciphertext ciphertext) {
        this->ct_[0]= this->ct_[0]+ciphertext.ct_[0];
        this->ct_[1]= this->ct_[1]+ciphertext.ct_[1];

        return *this;
    }

/*~     重线性化
 * ~    c_new_0 = c_0+∑_i_0->l { evk_k[i][0]c_k^(i) }
 *
 * ~    c_new_1 = c_1+∑_i_0->l { evk_k[i][1]c_k^(i) }
 *
~*/
    inline void reline(Ciphertext &ct)
    {
         int a=1;
         a++;
    }
    Ciphertext multiply(Ciphertext ciphertext) {
        Ciphertext tmpCT;
        tmpCT.ct_[0]= this->ct_[0] * ciphertext.ct_[0];
        tmpCT.ct_[1]= this->ct_[1] * ciphertext.ct_[0] + this->ct_[0] * ciphertext.ct_[1];
        tmpCT.ct_[2]= this->ct_[1] * ciphertext.ct_[1];

        reline(tmpCT);
        return tmpCT;
    }




};


#endif //R_LWE_CIPHERTEXT_H
