//
//  Ring.cpp
//  R_LWE
//
//  Created by mac on 2021/8/7.
//

#include "Ring.h"
#include <iostream>
#include <cmath>
using namespace std;
Ring::Ring() {
    for(int i=1;i<length;i++)
    {
        coefficient[i]=0;
    }
};
Ring::Ring(int x) {
    coefficient[0]=x;
    for(int i=1;i<length;i++)
    {
        coefficient[i]=x;
    }
};
Ring::Ring(const int coefi[length * 2]){

    for (int i = 0; i < length; i++) {
        coefficient[i]=coefi[i];
    }
};

void Ring::printRing() const {
    for(int i= length   - 1; i >= 0; i--)
    {
        cout<<coefficient[i]<<" ";
    }
    cout<<endl;
}




Ring Ring::ModxtimesDadd1(Ring r) {
    Ring ring;
    for(int i= length * 2 - 1; i >= length; i--)
    {
        if(r.coefficient[i]!=0){
            ring.coefficient[i - length]+=this->coefficient[i]+r.coefficient[i];
        }
    }

    return ring;
}

const int Ring::getLength() {
    return length;
}



Ring Ring::Mod(int mod) {
    for (int i = 0; i < length; i++) {
        this->coefficient[i] %= mod;
    }
    return *this;
}

Ring::Ring(Ring *pRing ) {
    for(int i=0;i<length;i++)
    {
        this->coefficient[i]= pRing->coefficient[i];
    }
}





Ring Ring::operator*(const int &b) {
    Ring ring;
    for (int i = 0; i < length; i++) {
        ring.coefficient[i] = this->coefficient[i] * b;
    }
    return ring;
}


Ring &Ring::operator/(const int &x)
{
    for (int i = 0; i < length; i++) {
        this->coefficient[i] = this->coefficient[i] / x;
    }
    return *this;
}
Ring &Ring::operator=(const Ring &ring)
{
    for (int i = 0; i < this->getLength(); ++i) {
        this->coefficient[i]=ring.coefficient[i];
    }
    return *this;
}
Ring Ring::operator+(const Ring &b) {
    Ring ring;
    for (int i = 0; i < length; i++) {
        ring.coefficient[i] = this->coefficient[i] + b.coefficient[i];
    }
    return ring;
}
Ring Ring::operator*(const Ring &b)   {
    Ring ring;
    for (int i=0; i < length; i++) {
        for(int j=0; j < length; j++)
        {
            ring.coefficient[i+j]+=this->coefficient[i]*b.coefficient[j];
        }
    }
    ring = ModxtimesDadd1(ring);
    return ring;
}

void Ring::random_Ring(int size) {

        for(int i=0;i<length;i++)
        {
            coefficient[i]=get_random(size);
        }
}

int Ring::ring2int() {
    int result=0;
//    int t=pow(2,(this->length));
    int t=1;
    for (int x :coefficient) {
        result+=x*t;
        t*=2;
    }
    return result;
}


