#include<stdio.h>
#include<string.h>
#include<errno.h>

int silly_copy_demo(void *src, void *dst, unsigned long len){
    unsigned long buf;
    if(len> sizeof(buf)){
        return -EINVAL;
    }
    memcpy(&buf,src,len);
    memcpy(dst,&buf,len);

    return len;
}

int main(void){
    unsigned long src=10000000;
    unsigned long dst=0;
    int x= silly_copy_demo(&src,&dst,sizeof(src));
    if(x<0){
        printf("the copy failed\n");
        return 1;
    }
    printf("Source is %lu\n",src);
    printf("Destination is %lu\n",dst);
    printf("Copy successfull\n");

    return 0;
}
