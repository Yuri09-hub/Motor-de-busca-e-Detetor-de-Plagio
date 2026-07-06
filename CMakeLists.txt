cmake_minimum_required(VERSION 3.31)
project(Motor_de_busca_e_Detetor_de_Plagio C)

set(CMAKE_C_STANDARD 11)

add_executable(Motor_de_busca_e_Detetor_de_Plagio main.c
        hash.h
        hash.c
        frequencia.h
        frequencia.c
        plagio.h
        plagio.c
        trie.c
        trie.h
        document_loader.h
        document_loader.c
        tokenizer.h
        tokenizer.c
)
