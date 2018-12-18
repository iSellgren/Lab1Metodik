//
//  int_sorted.hpp
//  Lab1
//
//  Created by Fredrik Sellgren on 2018-11-07.
//  Copyright © 2018 Fredrik Sellgren. All rights reserved.
//

#ifndef int_sorted_hpp
#define int_sorted_hpp
#include "int_buffer.hpp"
#include <stdio.h>
class int_sorted{
public:
    int_sorted(const int* source , size_t size);
    size_t size() const;
    int* insert(int value); // returns the insertion point.
    const int* begin() const;
    const int* end() const;
    int_sorted merge(const int_sorted&merge_with) const;
   // bool check_sorted(const int_sorted & int_check);
    //void sel_sort(int* begin, int* end);
    
private:
    
    
    int_sorted sort(const int* begin, const int* end);
    int_buffer buff;
    
};

#endif /* int_sorted_hpp */
