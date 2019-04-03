// ./library/include

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
    
}


#endif // BASE64_HPP
