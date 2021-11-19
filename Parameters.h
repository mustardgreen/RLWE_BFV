//
// Created by mac on 2021/8/22.
//

#ifndef R_LWE_PARAMETERS_H
#define R_LWE_PARAMETERS_H

class Parameters {

private:


public:
    //~构造函数
    Parameters()= default;;
    const static int modulus_T=64;
    const static int modulus_Q=16384;
    const static int delta=modulus_Q/modulus_T; //         delta=q/t

    const static int size_big=64;
    const static int size_noise=4;

};


#endif //R_LWE_PARAMETERS_H
