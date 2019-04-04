// ./include/headers/

/* Base64 algorithm to encode encryption and decription
  
   Base64 algorithm's table looks like this:
            +------|------+
            | Char | Code |
            +------|------+
            |  A   |   0  |
            +------|------+
            |  B   |   1  |
            +------|------+
            |  C   |   2  |
            +------|------+
                 .....
            +------|------+
            |  +   |  62  |
            +------|------+
            |  /   |  63  |
            +------|------+
    
   Algorithm explain based on example from Wikipedia:
        word "Man" is encoded as "TWFu"
   1. take the ASCII values of characters 'M', 'a' and 'n'
   2. these are
        M = 77  (binary: 01001101) 8 bits +
        a = 97  (binary: 01100001) 8 bits +
        n = 110 (binary: 01101110) 8 bits +
                                 = 24 bits
   3. then, all binary digits are grouped, so it looks like:
        010011010110000101101110 (length is, of course, 3 x 8 =24)
   4. 24 bits are grouped in groups of 6 bits. Why 6?
        Because, 2^6 = 64, so, we can map them to our table
   5. grouping is done in this way:
        +------+------+------+------+
        | every group is 6 bit long |
        +------+------+------+------+
        |010011|010110|000101|101110|
        +------+------+------+------+
        |    converted to decimal   |
        +------+------+------+------+
        |  19  |  22  |   5  |  46  | <--- look at the table
        +------+------+------+------+
        | if we map it to our table |
        +------+------+------+------+
        |   T  |   W  |   F  |   u  | <--- our encoded string
        +------+------+------+------+
    6. if the last group of 24 bit string is shorter than 24
        (the whole string is divided into 24 bit string)
        then we need to add padding
            6.1 Add extra "=" if last group contains only one byte
            6.2 Add extra "==" if last group contains two bytes

    ******************************************************************
        our algorithm directly encodes string to string, but minor
        modifications are needed to encode arbitrary byte sequence
    ******************************************************************
    More information: https://en.wikipedia.org/wiki/Base64

*/
#ifndef BASE64_HPP
#define BASE64_HPP

#include <vector>
#include <string>

namespace Base64
{
    std::string base64_encode(const std::string &);

    const std::string &SALT1 = "LM::TB::BB";
    const std::string &SALT2 = "_:/_77";
    const std::string &SALT3 = "line=wowC++";

    std::string EncryptB64(std::string s)
    {
        s = SALT1 + s + SALT2 + SALT3;
        s = base64_encode(s);
        s.insert(7, SALT3); // add the salt after the 7th char
        s += SALT1;
        s = base64_encode(s);
        s = SALT2 + SALT3 + SALT1;
        s = base64_encode(s);
        s.insert(1, "L");
        s.insert(7, "M");

        return s;
    }

    const std::string &BASE64_CODES = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    std::string base64_encode(const std::string &s)
    {
        std::string ret; // output string filled with encoded chars
        int val = 0; // index of map input base64 codes table
        int bits = -6; // represent number of bits in a sub group
        const unsigned int b63 = 0x3F; // in decimal value is 63

        for(auto &c : s) // every char c from string s
        {
            val = (val << 8) + c;
            // '<<' stand for left binary shifting but it this particular case
            // is a bit wise operation and << 8 means that the resulting number
            // will be shifted left by 8 places or is equal to
            // val= (val << 8) is same as val = val * 2^8
            bits += 8; // will add 8 to number of bits base64 works with octets 
            // when extracting information from original string
            while(bits >= 0)
            {
                ret.push_back(BASE64_CODES[(val >> bits) &b63]);
                bits -= 6; //grouping by six so we take -6
            }
        }
        if(bits > -6)
            ret.push_back(BASE64_CODES[((val << 8) >> (bits + 8)) &b63]);
        
        while(ret.size() % 4)
            ret.push_back('=');

        return ret;
    }
}


#endif // BASE64_HPP
