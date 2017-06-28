#pragma once

/*
	
Copying in terms of Size_t is faster than copying byte by byte. So when copying type cast the pointers to size_t.
Assuming the alignment is happening on size_t, this will avoid byte aligning.
void memcpy(void* dest, void* src, int size)
{
    uint8_t *pdest = (uint8_t*) dest;
    uint8_t *psrc = (uint8_t*) src;

    int loops = (size / sizeof(uint32_t));
    for(int index = 0; index < loops; ++index)
    {
        *((uint32_t*)pdest) = *((uint32_t*)psrc);
        pdest += sizeof(uint32_t);
        psrc += sizeof(uint32_t);
    }
}
*/
