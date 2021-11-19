//
// Created by mac on 2021/8/22.
//

#ifndef R_LWE_PLAINTEXT_H
#define R_LWE_PLAINTEXT_H


#include "Ring.h"

class Plaintext {
    Ring plaintext_;
public:
    Plaintext(int x){
        Ring tmpring(x);
        plaintext_=tmpring;
    };
    Plaintext(Ring x){
        plaintext_=x;
    };
    Ring getPlaintext() const {
        return plaintext_;
    };

    Plaintext() {

    };

    Plaintext(int pInt[16]) {
        plaintext_=Ring(pInt);
    }
};


#endif //R_LWE_PLAINTEXT_H
