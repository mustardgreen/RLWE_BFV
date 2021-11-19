//  main.cpp
//  R_LWE
//
//  Created by mac on 2021/8/7.
//

#include <iostream>
#include "SecretKey.h"
#include "PublicKey.h"
#include "Encryptor.h"
#include "Decryptor.h"
#include "Ciphertext.h"
#include "Plaintext.h"
#include <cstdlib>
#include "Font.h"
using namespace std;

int main() {//同态加的实现

    cout << "R-LWE代码实现，输入相应序号进行程序演示："<<endl;
    cout << "1、对明文进行加解密（明文直接放到多项式环的系数上）"<<endl;
    cout << "2、对明文进行加解密（明文被分解到多项式环的各个系数上）"<<endl;
    cout << "3、对2个明文加密，演示同态加的效果"<<endl;
    cout << "0、退出系统"<<endl;
//    Parameters parms;
    int type;
    cin>>type;
    //? LPR.ES.SecretKeyGen(1^λ):   sample   s ←— X
    //?                             output  sk == s
    SecretKey sk;
    PRINT_FONT_YEL;
    cout<<"SecretKey:"<<endl<<"\tSK = ";
    sk.getSk().printRing();

    //? LPR.ES.PublicKeyGen(sk):    set s = sk , sample a ←— R_q , e ←— X
    //?                             output pk[2] = ( [-(a·s+e)]_q , a ).
    PublicKey pk(sk);
    PRINT_FONT_PUR;
    cout<<"PublicKey:"<<endl<<"\tPK[0] = ";
    pk.getPk()[0].printRing();
    cout<<"\tPK[1] = ";
    pk.getPk()[1].printRing();
    Encryptor encryptor(pk);
    Decryptor decryptor(sk);

    //? LPR.ES.Encrypt(pk,m):       m ∈ R_t , let p0 = pk[0] , p1 = pk[1] , sample u,e1,e2 ←— X
    //?                             Δ=q/t;  这里我们先令q=t
    //?                             return ct[2] = ( [p0·u+e1+Δ·m]_q , [p1·u+e2]_q )
//明文10
    switch (type) {
        case 1:
        {
            PRINT_FONT_BLA;
            PRINT_BACK_WHI;
            cout << "1、对明文进行加解密（明文直接放到多项式环的系数上）"<<endl;
            PRINT_BACK_BLA;
//            int plaintext;
//            cout<<"请输入明文 plaintext = ";
//            cin>>plaintext;
            int a[16];
            for (int & i : a) {
                i=random()%31;
            }

            Plaintext m(a);
            PRINT_FONT_GRE;
            cout<<"明文多项式为："<<endl<<"\tPlaintext = ";
            m.getPlaintext().printRing();
            Ciphertext encrypted=encryptor.encrypt(m);
            PRINT_FONT_CYA;
            cout<<"对明文加密，密文多项式为："<<endl;
            cout<<"\tCT[0]=";
            encrypted.getCt()[0].printRing();
            cout<<"\tCT[1]=";
            encrypted.getCt()[1].printRing();
            PRINT_FONT_GRE;
            cout<<"对密文解密，得到解密后明文多项式为："<<endl<<"\tdecrypted = ";
            Plaintext decrypted = decryptor.decrypt(encrypted);
            decrypted.getPlaintext().printRing();
            break;
        }
        case 2:
        {            PRINT_FONT_BLA;
            PRINT_BACK_WHI;
            cout << "2、对明文进行加解密（明文被分解到多项式环的各个系数上）"<<endl;
            PRINT_BACK_BLA;
            int plaintext;
            int a[16];

            cout<<"请输入明文 plaintext = ";
            cin>>plaintext;
            int tmp_m=plaintext;
            for (int & i : a) {
                i=tmp_m%2;
                tmp_m/=2;
            }
            Plaintext m(a);
            PRINT_FONT_GRE;
            cout<<"明文多项式为："<<endl<<"\tPlaintext = ";
            m.getPlaintext().printRing();
            Ciphertext encrypted=encryptor.encrypt(m);
            PRINT_FONT_CYA;

            cout<<"对明文加密，密文多项式为："<<endl;
            cout<<"\tCT[0] = ";
            encrypted.getCt()[0].printRing();
            cout<<"\tCT[1] = ";
            encrypted.getCt()[1].printRing();
            PRINT_FONT_GRE;
            cout<<"对密文解密，得到解密后明文多项式为："<<endl<<"\tdecrypted = ";
            Plaintext decrypted = decryptor.decrypt(encrypted);
            decrypted.getPlaintext().printRing();
            cout<<"将多项式转为整数："<<decrypted.getPlaintext().ring2int()<<endl;

            break;
        }
        case 3:
        {            PRINT_FONT_BLA;
            PRINT_BACK_WHI;
            cout << "3、对2个明文加密，演示同态加的效果"<<endl;
            PRINT_BACK_BLA;

            int plain1=9,plain2=7;
            Plaintext m1(plain1);
            Plaintext m2(plain2);
            Ciphertext encrypted_text1=encryptor.encrypt(m1);
            Ciphertext encrypted_text2=encryptor.encrypt(m2);
            Ciphertext t1addt2=encrypted_text1.add(encrypted_text2);
            PRINT_FONT_CYA;

            cout<<"输出进行加法同态算法后得到的密文:"<<endl<<"\tCT[0]:";
            t1addt2.getCt()[0].printRing();
            cout<<"\tCT[1]:";
            t1addt2.getCt()[1].printRing();
            Plaintext decrypted_text=decryptor.decrypt(t1addt2);
            PRINT_FONT_GRE;
            cout<<"decrypted_text:"<<endl<<"\tDecrypted = ";
            decrypted_text.getPlaintext().printRing();


        }
        case 4:
        {            PRINT_FONT_BLA;
            PRINT_BACK_WHI;
            cout << "3、对2个明文加密，演示同态乘的效果"<<endl;
            PRINT_BACK_BLA;

            int plain1=9,plain2=7;
            Plaintext m1(plain1);
            Plaintext m2(plain2);
            Ciphertext encrypted_text1=encryptor.encrypt(m1);
            Ciphertext encrypted_text2=encryptor.encrypt(m2);
            Ciphertext t1multy2=encrypted_text1.multiply(encrypted_text2);
            PRINT_FONT_CYA;

            cout<<"输出进行加法同态算法后得到的密文:"<<endl<<"\tCT[0]:";
            t1multy2.getCt()[0].printRing();
            cout<<"\tCT[1]:";
            t1multy2.getCt()[1].printRing();
            Plaintext decrypted_text=decryptor.decrypt(t1multy2);
            PRINT_FONT_GRE;
            cout<<"decrypted_text:"<<endl<<"\tDecrypted = ";
            decrypted_text.getPlaintext().printRing();


        }
        default:
            break;
    }

    return 0;
}
