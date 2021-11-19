//
// Created by mac on 2021/8/22.
//

#ifndef R_LWE_RANDOM_H
#define R_LWE_RANDOM_H

#include <cstdlib>

class Random {

public:
    static int get_random(){
        return (int)random()%16;;
    };
};


#endif //R_LWE_RANDOM_H
