#include <cstdio>
#include <cstring>

int bruteforce_search(char* pattern, char* text)    /* O(nm) */
{
    int pattern_len, num_iterations, i;

    /* If one of the strings is NULL, then return that the string was
     * not found.
     */
    if (pattern == NULL || text == NULL) return -1; 

    /* Get the length of the string and determine how many different places
     * we can put the pattern string on the text string to compare them.
     */
    pattern_len = strlen(pattern);
    num_iterations = strlen(text) - pattern_len + 1; 
    
    /* For every place, do a string comparison.  If the string is found,
     * return the place in the text string where it resides.
     */
    for (i = 0; i < num_iterations; i++) {
        if (!strncmp(pattern, &(text[i]), pattern_len)) return i;
    } 
    
    /* Otherwise, indicate that the pattern wasn't found */
    return -1;
}

int robin_karp_ksearch(char* pattern, char* text)           /* O(n + m) */
{
    int pattern_hash, text_hash, pattern_len, num_iterations, i; 
    
    /* are the pattern and the text legitimate strings? */
    if (pattern == NULL || text == NULL) return -1;

    /* get the lengths of the strings and the number of iterations */
    pattern_len = strlen(pattern);
    num_iterations = strlen(text) - pattern_len + 1;

    /* Do initial hashes */
    pattern_hash = hash(pattern);
    text_hash = hashn(text, pattern_len);

    /* Main comparison loop */
    for (i = 0; i < num_iterations; i) {
        if (pattern_hash == text_hash && 
            !strncmp(pattern, &(text[i]), pattern_len)) return i;

        text_hash = hash_increment(text, i, text_hash, pattern_len);
    } 
    
    /* Pattern not found so return -1 */
    return -1;
}

/* hash function for fingerprinting */
int hash(char* str)
{
    int sum = 0; 
    while (*str != '\0') sum += (int) *str; 
    return sum % MODULUS;
}

int hashn(char* str, int n)
{
    char ch = str[n];
    int sum; 
    str[n] = '\0';
    sum = hash(str);
    str[n] = ch;
    return sum;
}

int hash_increment(char* str, int prevIndex, int prevHash, int keyLength)
{
    int val = (prevHash - ((int) str[prevIndex]) 
        + ((int) str[prevIndex + keyLength])) % MODULUS;

    return (val < 0) ? (val + MODULUS) : val;
}