//
//  int_buffer.hpp
//  Lab1
//
//  Created by Fredrik Sellgren on 2018-11-07.
//  Copyright © 2018 Fredrik Sellgren. All rights reserved.
//

#ifndef int_buffer_hpp
#define int_buffer_hpp

#include <stdio.h>
class int_buffer{
public:
    
    explicit int_buffer(size_t size); // size_t is defined in cstdlib
    int_buffer(const int* source , size_t size); //construct nr 2.
    int_buffer(const int_buffer& rhs); // copy construct
    int_buffer(int_buffer&& rhs); // move construct
    int_buffer & operator=(const int_buffer&rhs); // copy assign
    int_buffer & operator=(int_buffer&& rhs); // move assign
    bool check_sorted(int_buffer int_check);
    size_t size() const;
    int* begin();
    int* end();
    const int* begin() const;
    const int* end() const;
    ~int_buffer();
private:
    
    int* buff_beg = nullptr;
    size_t buff_size = 0;
};

#endif /* int_buffer_hpp */
