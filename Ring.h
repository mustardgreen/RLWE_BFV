//
//  Ring.h
//  R_LWE
//
//  Created by mac on 2021/8/7.
//

#ifndef Ring_hpp
#define Ring_hpp
#include <cstdlib>

#include <stdio.h>
class Ring
{
    const static int length=16;
    int mod_;
    int coefficient[2 * length]{};             //多项式系数
    int D{};                          //多项式环的最大次数 x^D+1

    static const int getLength();

public:
    explicit Ring(const int coef[length * 2]);            //构造方法
    explicit Ring(Ring *pRing);

    Ring( );
    explicit Ring(int x);




    void random_Ring(int size);
    void printRing() const;
    Ring ModxtimesDadd1(Ring r);               //确保每次计算后多项式仍在环上

    Ring Mod(int mod);


    Ring& operator/(const int& x);
    Ring operator+(const Ring& b);
    Ring operator*(const int& b);
    Ring& operator=(const Ring& ring);
    Ring operator*(const Ring& b);

    int ring2int();










private:
    static int get_random(int size){
        return (int)random()%size;
    };


protected:

};
#endif /* Ring_hpp */
