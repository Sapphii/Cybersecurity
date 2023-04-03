#include <iostream>
#include <vector>

using namespace std;

unsigned char mult_GF8(unsigned char a, unsigned char b);

vector<vector<unsigned char>> mix_columns(vector<vector<unsigned char>> state) {
    // Create the MixColumns matrix
    unsigned char mix_matrix[4][4] = {
        {0x02, 0x03, 0x01, 0x01},
        {0x01, 0x02, 0x03, 0x01},
        {0x01, 0x01, 0x02, 0x03},
        {0x03, 0x01, 0x01, 0x02}
    };

    // Create a new state matrix to hold the result
    vector<vector<unsigned char>> new_state(4, vector<unsigned char>(4));

    // Perform the matrix multiplication for each column
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            unsigned char total = 0;
            for (int k = 0; k < 4; k++) {
                // Multiply the matrix element by the corresponding state element
                unsigned char mult = mult_GF8(mix_matrix[i][k], state[k][j]);
                // Add the result to the running total
                total ^= mult;
            }
            // Set the new state element to the total
            new_state[i][j] = total;
        }
    }

    return new_state;
}

unsigned char mult_GF8(unsigned char a, unsigned char b) {
    // Multiply two Galois Field (GF) elements in GF(2^8)
    unsigned char p = 0;
    //iterates through all 8 bits
    for (int i = 0; i < 8; i++) {
        if (b & 1) { //checks if least significant bit of b is 1.
            p ^= a; //xor p and a
        }
        unsigned char hi_bit_set = a & 0x80; //check if most significant digit of a is 1. If it is then hi_bit_set is set to non-zero
        a <<= 1; //shift a one bit to the left
        if (hi_bit_set) { 
            a ^= 0x1B; // xor a with the fixed irreduciable polynomial.
        }
        b >>= 1; //shift b one bit to the right.
    }
    return p % 256;
}

int main() {
    // Input matrix to be MixColumned 
    vector<vector<unsigned char>> state = {
        {0xba, 0x4a, 0x12, 0x55},
        {0x36, 0xd3, 0x37, 0x96},
        {0x63, 0xe3, 0x2a, 0x8f},
        {0x32, 0x85, 0x79, 0x55}
    };
    // ba	4a	12	55
    // 36	d3	37	96
    // 63	e3	2a	8f
    // 32	85	79	55

    vector<vector<unsigned char>> new_state = mix_columns(state);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << hex << (int)new_state[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}