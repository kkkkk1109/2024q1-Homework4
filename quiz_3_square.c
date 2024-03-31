#include <stdio.h>
#include <stdint.h>
static inline int __ffs(int word)
{
    int num = 0;

    if ((word & 0xffff) == 0) {
        num += 16;
        word >>= 16;
    }
    if ((word & 0xff) == 0) {
        num += 8;
        word >>= 8;
    }
    if ((word & 0xf) == 0) {
        num += 4;
        word >>= 4;
    }
    if ((word & 0x3) == 0) {
        num += 2;
        word >>= 2;
    }
    if ((word & 0x1) == 0)
        num += 1;
    return num;
}

int clear_bit (int x,int bit){
    uint32_t mask = ~(1 << bit); 
    return x & mask;
}
int fls (int x){
    int bit=1,set=1;

    while(bit!=31){
        set = bit;
        bit = __ffs(x);
        x=clear_bit(x,bit);
    }
    return set;
}

int i_sqrt(int x)
{
    if (x <= 1) /* Assume x is always positive */
        return x;

    int z = 0;
    for (int m = 1UL << (fls(x) & ~1UL); m; m >>= 2) {
        int b = z + m;
        z >>= 1;
        if (x >= b)
            x -= b, z += m;               
    }
    return z;
}

int main(){
    printf("%d",i_sqrt(49));
    return 0;
}