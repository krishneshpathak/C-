#include <iostream>
#include <cstdlib>

//allocator that splits IOMEM & SMEM in fixed size chunks(cell slots)
class Allocator final {
public:
    Allocator(const Allocator& )= delete;
    Allocator& operator=(const Allocator& )= delete;
    Allocator(Allocator&& );
    Allocator& operator=(Allocator&& );

    ~Allocator(){};

    //Builder for Allocator
    //contruction of Allocator more flexible...
    //we have to support unknown no of subpools, we have to able to
    // add them in dynamic manner...

    class Builder {
        public:
            Allocator::Builder& withIoMemCellSlot(size_t cellslotsize)
            {
                this->subcellsize = cellslotsize;
                return *this;
            }

            Allocator::Builder& withSMemCellSlot(size_t cellslotsize)
            {
                this->cellslotsize = cellslotsize;
                return *this;
            }
            Allocator::Builder& withAlignment(int alignment)
            {
                this->alignment = alignment;
                return *this;
            }
            Allocator build() const {
 
                return Allocator(cellslotsize, subcellsize, alignment );
            }
        private:
            int alignment=0;
            size_t cellslotsize;
            size_t subcellsize;
    };

    friend class Builder;

private:
    size_t cellslotsize;
    size_t subcellslotsize;
    int alignment;

    Allocator(size_t cellslotsize, size_t subcellsize, int alignment) {
        if(subcellsize) {
            std::cout <<"with IoMemCellSlot " ;
        } else if (cellslotsize){
            std::cout <<"with SMemCellSlot " ;
        } 
        if (alignment) {
            std::cout <<"with Alignment"<<  alignment<<"\n";
        } else {
            std::cout <<"default:" <<"\n";
        } 
    }

};


int main(){
    //allocation with IOMEM
    Allocator::Builder iomembuilder{};
    iomembuilder.withIoMemCellSlot(10).withAlignment(16);
    iomembuilder.build();

    //allocation with SMEM
    Allocator::Builder smembuilder{};
    smembuilder.withSMemCellSlot(20).withAlignment(16);
    smembuilder.build();

    return 0;
}
