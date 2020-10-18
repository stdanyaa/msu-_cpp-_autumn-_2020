#include <cstddef>

class Allocator{
    char* memory_pointer_;
    size_t size_ = -1;
    size_t offset_; 


public:
    void makeAllocator(size_t maxSize){
        if (size_ != -1) return;
        if (maxSize <= 0) return;
        size_ = maxSize;
        offset_ = 0;
        memory_pointer_ = new char[size_];
    };
    char* alloc(size_t size){
        if (size_ == -1){
            return nullptr;
        }
        if (offset_ + size > size_){
            return nullptr;
        }
        if (size <= 0){
            return nullptr;
        }
        char* ret = memory_pointer_ + offset_;
        offset_ += size;
        return ret;
    };
    void reset(){
        offset_ = 0;
    };
    ~Allocator(){
        if(memory_pointer_ != nullptr){
            delete []memory_pointer_;
        }
    }
};
