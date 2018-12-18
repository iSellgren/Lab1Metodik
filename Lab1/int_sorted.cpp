//
//  int_sorted.cpp
//  Lab1
//
//  Created by Fredrik Sellgren on 2018-11-07.
//  Copyright © 2018 Fredrik Sellgren. All rights reserved.
//

#include "int_sorted.hpp"
#include "int_buffer.hpp"

#include <algorithm>
#include <iostream>


int_sorted::int_sorted(const int* source , size_t size) // Vi tar en kopia av buffs size och source för att sedan sortera den.
:buff(nullptr,0)
{
    int_buffer tmp(source, size);
    if(size == 0)
    {
        return;
    }
    else if (size == 1)
    {
        insert(*source);
        return;
    }
    
    int_sorted sorted = sort(tmp.begin(), tmp.end());
    
    
//    buff = int_buffer(std::move(sorted.buff));
    buff = (std::move(sorted.buff));
    
    
}


size_t int_sorted::size() const // Returnar sizen på buffern.
{
    return buff.size();
}

int* int_sorted::insert(int value)// returns the insertion point.
{
    int_buffer tempbuff(buff.size() + 1 ); // Skapar en temporär buffer.
    int* index = nullptr; // sätter index till nullprt
    
    for(int* iter = buff.begin(); iter != buff.end(); iter++) //iterrerar
    {
        if(value < *iter) // om värdet på iter är större än value så stoppas värdet in innan.
        {
            index = tempbuff.begin();
            index += (iter - buff.begin());
            break;
        }
    }

    if(index == nullptr)
    {
        index = tempbuff.end()-1;
    }
    
    *index = value;
    
    int* newiter = tempbuff.begin();
    int* olditer = buff.begin();
    
    while(olditer != buff.end()) // Går igenom buff.
     {
         if(index == newiter) //newiter ökas pga value insert.
         {
             ++newiter;
         }
         *newiter = *olditer;
         ++newiter;
         ++olditer;
     }
    
//    buff = int_buffer(std::move(tempbuff));
    buff = std::move(tempbuff);
    return index;    
}
const int* int_sorted::begin() const
{
    return buff.begin();
}
const int* int_sorted::end() const
{
    return  buff.end();
}
int_sorted int_sorted::merge(const int_sorted & merge_with) const
{
    
    int_buffer mergbuff(buff.size() + merge_with.size());
    
    const int* Temp1 = buff.begin();
    const int* Temp2 = merge_with.begin();
    int* merged = mergbuff.begin();
    

    while((Temp1) != buff.end()  && (Temp2) != merge_with.end())
    {
        
        if(*Temp1 < *Temp2)
        {
            *merged = *Temp1;
            ++merged;
            Temp1++;
        }
        
        else
        {
            *merged = *Temp2;
            ++merged;
            Temp2++;
        }
    }
    
    while((Temp1) != buff.end())
    {

        *merged = *Temp1;
        ++merged;
        Temp1++;
    }
    
    while((Temp2) != merge_with.end())
    {
        *merged = *Temp2;
        ++merged;
        Temp2++;
    }

    int_sorted completed(nullptr, 0);
    
    completed.buff = std::move(mergbuff);
    
    return completed;
}


int_sorted int_sorted::sort(const int* begin, const int* end)
{
    if (begin == end) return int_sorted(nullptr,0);
    
    if (begin == end - 1) return int_sorted(begin, 1);
    
    ptrdiff_t half = (end - begin) / 2;
    
    const int* mid = begin + half;
   return sort(begin, mid) .merge(sort(mid, end));
}


bool check_sorted(const int_sorted & int_check){
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
