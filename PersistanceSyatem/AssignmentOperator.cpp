// Types copy assignment operator
// What,why,when

// “Instead of copying the data, just steal it.”

// It’s like saying:
// “Hey, I don’t need this anymore—take it, and I’ll leave myself empty.”

// Copying large objects (like vectors, strings, or custom buffers) is expensive. 
// Move semantics avoids that cost by transferring the internal resources (like pointers) instead of duplicating them.





#include <iostream>

class DataBuffer {
    char* data;
    size_t size;

public:
    // Constructor
    DataBuffer(size_t s) : size(s) {
        data = new char[size];
        std::cout << "Constructed buffer of size " << size << "\n";
    }

    // Destructor
    ~DataBuffer() {
        delete[] data;
        std::cout << "Destroyed buffer\n";
    }

    // Move constructor
    DataBuffer(DataBuffer&& other) noexcept
        : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Moved (constructor)\n";
    }

    // Move assignment operator
    DataBuffer& operator=(DataBuffer&& other) noexcept {
        if (this != &other) {
            delete[] data;  // Free existing resource
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
            std::cout << "Moved (assignment)\n";
        }
        return *this;
    }

    // Disable copy operations
    DataBuffer(const DataBuffer&) = delete;
    DataBuffer& operator=(const DataBuffer&) = delete;
};

int main() {
    DataBuffer a(1024);         // Allocate 1 KB
    DataBuffer b(2048);         // Allocate 2 KB

    b = std::move(a);           // Move assignment: transfer ownership
}