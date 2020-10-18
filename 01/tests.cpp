#include "Allocator.cpp"
#include <cassert>
#include <iostream> 


void NormalWorkTest(){
    Allocator Al;
    Al.makeAllocator(10);
    char* a = Al.alloc(5);
    char* b = Al.alloc(5);
    for(int i=0;i<5;i++)
    {
        a[i]='a'+i;
        b[i]='0'+i;
    }
    assert((a[0] == 'a') && (a[4]=='e'));
    assert((b[0] == '0') && (b[4]=='4'));
}

void OutOfRangeTest(){
    Allocator Al;
    Al.makeAllocator(6);
    char* a = Al.alloc(5);
    assert(a != nullptr);
    a = Al.alloc(3);
    assert(a == nullptr);
    return;
}

void AllocatorResetTest(){
    Allocator Al;
    Al.makeAllocator(6);
    char* a = Al.alloc(4);
    *a='a';
    Al.reset();
    char* b = Al.alloc(6);
    *b='b';
    assert(*a == 'b');
}

void MemoryAllocationTest(){
    // alloc without makeAlloc
    // is not allowed
    Allocator Al;
    char *a = Al.alloc(1);
    assert(a == nullptr);
    // makeAlloc double calling
    // doesn't leak memory
    Al.makeAllocator(1);
    a = Al.alloc(1);
    *a = 'a';
    Al.makeAllocator(1);
    Al.reset();
    char *b = Al.alloc(1);
    assert(*a == *b);
}

int main()
{
    NormalWorkTest();
    OutOfRangeTest();
    AllocatorResetTest();
    MemoryAllocationTest();
    std::cout<<"Success!\n";
}