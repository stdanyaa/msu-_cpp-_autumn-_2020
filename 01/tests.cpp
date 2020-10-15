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
    assert(a[4]=='e');
    assert(b[4]=='4');
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

void RewriteTest(){
    Allocator Al;
    Al.makeAllocator(6);
    char* a = Al.alloc(4);
    for(int i=0;i<4;i++)
    {
        a[i]='a';
    }
    Al.reset();
    char* b = Al.alloc(6);
    for(int i=0;i<3;i++)
    {
        b[i]='b';
    }
    assert(a[2] == 'b');
}

int main()
{
    NormalWorkTest();
    OutOfRangeTest();
    RewriteTest();
    std::cout<<"Success!\n";
}