#if defined (__cplusplus)
extern "C"{
#endif

#define x (0x1ULL << 63)
typedef int uint32;

void ptr_test(unsigned long *ptr){
    *ptr = 2000;
    return;
}

#if defined (__cplusplus)
};
#endif
