cmake_minimum_required(VERSION 3.19)
project(R_LWE)

set(CMAKE_CXX_STANDARD 14)

add_executable(R_LWE main.cpp Ring.cpp Ring.h SecretKey.cpp SecretKey.h PublicKey.cpp PublicKey.h Encryptor.cpp Encryptor.h Decryptor.cpp Decryptor.h Ciphertext.cpp Ciphertext.h Parameters.cpp Parameters.h Random.cpp Random.h Plaintext.cpp Plaintext.h Font.cpp Font.h Relinekey.cpp Relinekey.h Evaluator.cpp Evaluator.h)
