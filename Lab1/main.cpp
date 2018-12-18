//
//  main.cpp
//  Lab1
//
//  Created by Fredrik Sellgren on 2018-11-07.
//  Copyright © 2018 Fredrik Sellgren. All rights reserved.
//

#include <iostream>
#include "int_buffer.hpp"
#include "int_sorted.hpp"
#include <random>

bool check_sorted(const int_buffer& int_check){
    const int* check = int_check.begin();
    const int* next = int_check.begin() + 1;
    while (check != int_check.end()-1){
        next = check + 1;
        if (*check > *next){
            std::cout << "EJ sorterad" << std::endl;
            
            return false;
        }
        else{
            check = next;
        }
    }
    std::cout << "Sorterad" << std::endl;
    return true;
    
}


void sel_sort(int* begin, int* end)
{
    
    for(int* iter = begin; iter != end; iter++)
    {
        int* smallestIndex = iter;
        
        for(int* jiter = iter; jiter != end; jiter++)
            if(*jiter < *smallestIndex)
                smallestIndex = jiter;
        
    std::swap(*iter,*smallestIndex);
    }
}



void f(int_buffer buf)
{
    int val = 1;
    for(int* i = buf.begin(); i != buf.end(); i++)
    {
        *i = val;
        ++val;
    }
    
    
    for(const int* i = buf.begin(); i != buf.end(); i++)
    {
        std::cout << *i << std::endl;
    }
            
}
int main ()
{

    
   //f(int_buffer(2));
    int_buffer buff1(400000);
    int_buffer buff2(400000);
    int_buffer buff3(400000);
    
    
    

    std::mt19937 mt((std::random_device()()));
    
    std::uniform_int_distribution<int>dist(1,100);
    
    for(int* it = buff1.begin(); it != buff1.end(); it++)
    {
        *it = dist(mt);
    }
    for(int* it = buff2.begin(); it != buff2.end(); it++)
    {
        *it = dist(mt);
    }
    for(int* it = buff3.begin(); it != buff3.end(); it++)
    {
        *it = dist(mt);
    }
     clock_t start = clock();

        
  //  test.check_sorted(test);
   //sel_sort(buff1.begin(), buff1.end());
    
        clock_t stop = clock();
        double elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
        printf("Time it took to complete sel_sort sec: %f", elapsed);
    //check_sorted(buff1);
    
    clock_t sta = clock();
        int_sorted test(buff2.begin(), buff2.size());
    clock_t sto = clock();
    double elapse = (double)(sto - sta) / CLOCKS_PER_SEC;
    printf("Time it took to complete merge sec: %f", elapse);

    clock_t st = clock();
    std::sort(buff3.begin(), buff3.end());
    clock_t ss = clock();
    double elaps = (double)(ss - st) / CLOCKS_PER_SEC;
    printf("Time it took to complete std::sort sec: %f", elaps);
    
    
    
    return 0;
    
}
