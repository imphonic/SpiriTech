// A fixed-width integer experiiment I should probably be shot for.
// All in the name of reducing standard library dependencies.
//-----------------------------------------------------------------------------

// Static assertions to enforce primitive type size.

// We could use the C fixed-width integer types but I want to see if
// this is possible; if it breaks later I'll just use find-replace and
// fix it I guess.



// Engine only runs on 64-bit platforms
static_assert   (sizeof(void*)                == 8);

// Char should always be 8 bits
static_assert   (sizeof(char)                 == 1);

// Short should always be 16 bits
static_assert   (sizeof(short)                == 2);
static_assert   (sizeof(signed short)         == 2);
static_assert   (sizeof(unsigned short)       == 2);

// Int should always be 32 bits
static_assert   (sizeof(int)                  == 4);
static_assert   (sizeof(signed int)           == 4);
static_assert   (sizeof(unsigned int)         == 4);

// Long long should always be 64 bits
static_assert   (sizeof(long long)            == 8);
static_assert   (sizeof(signed long long)     == 8);
static_assert   (sizeof(unsigned long long)   == 8);

// IEEE 754 will enforce this anyway
static_assert   (sizeof(float)                == 4);
static_assert   (sizeof(double)               == 8);

// Some more sanity checks for size suffixes

// Unsigned int suffixes
static_assert   (sizeof(0u)                   == 4);
static_assert   (sizeof(0U)                   == 4);

// Signed and unsigned long long suffixes
static_assert   (sizeof(0ll)                  == 8);
static_assert   (sizeof(0LL)                  == 8);
static_assert   (sizeof(0ull)                 == 8);
static_assert   (sizeof(0ULL)                 == 8);
