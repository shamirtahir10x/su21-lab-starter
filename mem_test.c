#include <stdio.h>
#include <stdint.h>
#include <string.h>


#define NO_WORDS 2
#define SIZE_WORDS NO_WORDS<<3

typedef struct {
   unsigned long long double_word[NO_WORDS];
} arr_t __attribute__ ((aligned (SIZE_WORDS) ));


arr_t store_byte_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_byte_expected_data[8] =
       {    // double_word0         double_word1
          { 0x00000000000000EF, 0x0000000000000000 },
          { 0x000000000000BE00, 0x0000000000000000 },
          { 0x0000000000AD0000, 0x0000000000000000 },
          { 0x00000000DE000000, 0x0000000000000000 },
          { 0x000000EF00000000, 0x0000000000000000 },
          { 0x0000BE0000000000, 0x0000000000000000 },
          { 0x00AD000000000000, 0x0000000000000000 },
          { 0xDE00000000000000, 0x0000000000000000 }
       };


arr_t store_half_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_half_word_expected_data[8] =
       {
          { 0x000000000000BEEF, 0x0000000000000000 },
          { 0x0000000000ADBE00, 0x0000000000000000 },
          { 0x00000000DEAD0000, 0x0000000000000000 },
          { 0x000000EFDE000000, 0x0000000000000000 },
          { 0x0000BEEF00000000, 0x0000000000000000 },
          { 0x00ADBE0000000000, 0x0000000000000000 },
          { 0xDEAD000000000000, 0x0000000000000000 },
          { 0xDE00000000000000, 0x00000000000000EF }
       };


arr_t store_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_word_expected_data[8] =
       {
          { 0x00000000DEADBEEF, 0x0000000000000000 },
          { 0x000000DEADBEEF00, 0x0000000000000000 },
          { 0x0000DEADBEEF0000, 0x0000000000000000 },
          { 0x00DEADBEEF000000, 0x0000000000000000 },
          { 0xF00DC0DE00000000, 0x0000000000000000 },
          { 0x0DC0DE0000000000, 0x00000000000000F0 },
          { 0xC0DE000000000000, 0x000000000000F00D },
          { 0xDE00000000000000, 0x0000000000F00DC0 }
       };


arr_t store_double_word_data[8] =
       {
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 },
          { 0x0000000000000000, 0x0000000000000000 }
       };


arr_t store_double_word_expected_data[8] =
       {
          { 0xDEADBEEFF00DC0DE, 0x0000000000000000 },
          { 0xADBEEFF00DC0DE00, 0x00000000000000DE },
          { 0xBEEFF00DC0DE0000, 0x000000000000DEAD },
          { 0xEFF00DC0DE000000, 0x0000000000DEADBE },
          { 0xF00DC0DE00000000, 0x00000000DEADBEEF },
          { 0x0DC0DE0000000000, 0x000000DEADBEEFF0 },
          { 0xC0DE000000000000, 0x0000DEADBEEFF00D },
          { 0xDE00000000000000, 0x00DEADBEEFF00DC0 }
       };



int store_byte_test ( ) {

// EF, BE, AD, DE, EF, BE, AD, DE
   // uint64_t val = 0xEFBEADDEEFBEADDE;
   uint8_t* ptr = (uint8_t*) &val;

   ptr[0] = 0xAB;

   if (ptr[0] != 0xAB && ptr[7] != 0xEF) {
   printf("Test failed\n");
   return 0;
   }

   printf("Test passed\n");
   return 1;

} // store_byte_test


int store_half_word_test ( ) {

// BEEF, ADBE, DEAD, EFDE, BEEF, ADBE, DEAD, EFDE
uint64_t val = 0xBEEFADBEDEADEFDE;
    uint16_t* ptr = (uint16_t*) &val;

    // Write the values to memory
    for (int i = 0; i < 4; i++) {
        write_half_word(ptr+i, *(ptr+i));
    }

    // Read the values from memory and compare them with the original
    for (int i = 0; i < 4; i++) {
        uint16_t value;
        read_half_word(ptr+i, &value);
        if (value != *(ptr+i)) {
            return i+1; // Return the index of the first incorrect value
        }
    }

    return 0; // All tests passed successfully

} // store_half_word_test


int store_word_test ( ) {

// DEADBEEF, F00DC0DE
uint32_t val1 = 0xDEADBEEF;
    uint32_t val2 = 0xF00DC0DE;

    store_word((uint8_t*)0x1000, val1);
    store_word((uint8_t*)0x1004, val2);

    if (load_word((uint8_t*)0x1000) != val1) {
        return 1;
    }

    if (load_word((uint8_t*)0x1004) != val2) {
        return 2;
    }

    return 0;

} // store_word_test


int store_double_word_test ( ) {

int store_double_word_test() {
    uint64_t val = 0xDEADBEEFF00DC0DE;
    uint8_t buffer[8];
    memcpy(buffer, &val, sizeof(uint64_t));
    return buffer[0] == 0xDE &&
           buffer[1] == 0xAD &&
           buffer[2] == 0xBE &&
           buffer[3] == 0xEF &&
           buffer[4] == 0xF0 &&
           buffer[5] == 0x0D &&
           buffer[6] == 0xC0 &&
           buffer[7] == 0xDE;
}

// DEADBEEFF00DC0DE

} // store_double_word_test



int main() {

   store_byte_test();

} // main
