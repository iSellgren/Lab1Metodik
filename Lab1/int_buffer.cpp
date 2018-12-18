//
//  int_buffer.cpp
//  Lab1
//
//  Created by Fredrik Sellgren on 2018-11-07.
//  Copyright © 2018 Fredrik Sellgren. All rights reserved.
//

#include "int_buffer.hpp"

int_buffer::int_buffer(size_t size) // size_t is defined in cstdlib
: buff_size(size)
{
    buff_beg = new int[size];
}

int_buffer::int_buffer(const int* source , size_t size)
: buff_size(size)
{
    
    buff_beg = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        buff_beg[i] = source[i];
    }
}


int_buffer::int_buffer(const int_buffer& rhs)// copy construct
: buff_size(rhs.buff_size)
{
    buff_beg = new int[rhs.buff_size];
    for(size_t i = 0; i < buff_size; i++)
    {
        buff_beg[i] = rhs.buff_beg[i];
    }
}

int_buffer::int_buffer(int_buffer&& rhs):// move construct
buff_beg(rhs.buff_beg)
{
    buff_beg = rhs.buff_beg;
    rhs.buff_beg = nullptr;
    buff_size = rhs.buff_size;
    
}
int_buffer& int_buffer::operator=(const int_buffer&rhs) // copy assign
{
    if(this == &rhs)
        return *this;
    
    delete[] buff_beg; // delete buff_beg
    buff_beg = new int[rhs.buff_size]; //
    buff_size = rhs.buff_size;
    for(size_t i = 0; i < rhs.buff_size; i++)
    {
        buff_beg[i] = rhs.buff_beg[i];
    }
    
    return *this;
}
int_buffer& int_buffer::operator=(int_buffer&& rhs) // move assign
{
    
    if (this == &rhs)
        return *this;
    
    delete[] buff_beg;
    buff_size = rhs.buff_size;
    buff_beg = rhs.buff_beg;
    rhs.buff_beg = nullptr;
        
    return *this;
}


size_t int_buffer::size() const
{
    return buff_size;
}
int* int_buffer::begin()
{
    return buff_beg;
}
int* int_buffer::end()
{
    return buff_beg + buff_size;
}

const int* int_buffer::begin() const
{
    return buff_beg;
}
const int* int_buffer::end() const
{
    return buff_beg + buff_size;
}

int_buffer::~int_buffer()
{
    if (!buff_beg)
        delete[] buff_beg;
    
}
    
