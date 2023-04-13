#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef unsigned char uint8;
#define BUFFER_MAX 12
#define TRUE    1
#define FALSE   0

typedef struct
{
    char *buffer_data;
    uint8 index_read;
    uint8 index_write;
    uint8 size;
}ring;

inline void vRingBufferInit(ring *ring_buffer,uint8 user_size)
{
    ring *temp_ring = NULL;
    temp_ring = ring_buffer;

    temp_ring->buffer_data = (char*)calloc(user_size,sizeof(char));
    temp_ring->size = user_size;
    temp_ring->index_read = 0;
    temp_ring->index_write = 0;
}

inline uint8 bRingBufferIsFull(ring *ring_buffer)
{
    return ((ring_buffer->index_write + 1) % ring_buffer->size == ring_buffer->index_read);
}

inline uint8 bRingBufferIsEmpty(ring *ring_buffer)
{
    return (ring_buffer->index_write == ring_buffer->index_read);
}

void vWriteData(ring *temp_ring, char data)
{
    if(bRingBufferIsFull(temp_ring))
    {
        temp_ring->index_read = (temp_ring->index_read + 1) % temp_ring->size;
        printf("Override Happened!\t");
    }
    temp_ring->buffer_data[temp_ring->index_write] = data;
    temp_ring->index_write = (temp_ring->index_write + 1) % temp_ring->size;
    
    
}

void vReadData(ring *temp_ring)
{
    if(bRingBufferIsEmpty(temp_ring))
    {
        printf("The ring is empty!\n");
        return;
    }
    else
    {
        printf("data:%c\t",temp_ring->buffer_data[temp_ring->index_read]);
        temp_ring->index_read = (temp_ring->index_read + 1) % temp_ring->size;
    }
}

int main(){
    ring ring1;
    uint8 ring_size = 8;
    vRingBufferInit(&ring1,ring_size);
    char np_char[9] = {'1','2','3','4','5','6','7','8','9'};
    for(int i = 0; i < 8; i++){
        vWriteData(&ring1,np_char[i]);
        printf("read:%d\twrite:%d\n",ring1.index_read,ring1.index_write);
    }
    for(int i = 0; i < 6; i++){
        vWriteData(&ring1,np_char[i]);
        printf("read:%d\twrite:%d\n",ring1.index_read,ring1.index_write);
    }
    for(int i = 0; i < 3; i++){
        vReadData(&ring1);
        printf("read:%d\twrite:%d\n",ring1.index_read,ring1.index_write);
    }
    for(int i = 0; i < 4; i++){
        vReadData(&ring1);
        printf("read:%d\twrite:%d\n",ring1.index_read,ring1.index_write);
    }
    // for(int i = 0; i < 3; i++){
    //     vWriteData(&ring1,np_char[i]);
    // }
    // for(int i = 0; i < 3; i++){
    //     vReadData(&ring1);
    // }

    
    return 0;
}