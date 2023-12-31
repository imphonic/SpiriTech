#pragma once

#include "engine/common.h"

RPF_OPEN_SUB(math )

    /// \section    Common Math
    /// \brief      Gets the smaller of two values.
    ///
    /// \param in_a             First value to compare.
    /// \param in_b             Second value to compare.
    ///
    /// \returns    The smaller of the two values.
    float minf(float in_a, float in_b);

    /// \section    Common Math
    /// \brief      Gets the larger of two values.
    ///
    /// \param in_a             First value to compare.
    /// \param in_b             Second value to compare.
    ///
    /// \returns    The larger of the two values.
    float maxf(float in_a, float in_b);

    /// \section    Common Math
    /// \brief      Calculates the square of a number.
    ///
    /// \param in_v             Number to square.
    ///
    /// \returns    The resulting squared number.
    float squaref(float in_v);

    /// \section    Common Math
    /// \brief      Calculates the square root of a number.
    ///
    /// \param in_v             Number to get the square root of.
    ///
    /// \returns    The resulting square root.
    float sqrtf(float in_v);

    /// \section    Common Math
    /// \brief      Calculates the inverse square root of a number.
    ///
    /// \param in_v             Number to get the square root of.
    ///
    /// \returns    The resulting inverse square root.
    float rsqrtf(float in_v);

    /// \section    Common Math
    /// \brief      Gets the smaller of two values.
    ///
    /// \param in_a             First value to compare.
    /// \param in_b             Second value to compare.
    ///
    /// \returns    The smaller of the two values.
    double min(double in_a, double in_b);

    /// \section    Common Math
    /// \brief      Gets the larger of two values.
    ///
    /// \param in_a             First value to compare.
    /// \param in_b             Second value to compare.
    ///
    /// \returns    The larger of the two values.
    double max(double in_a, double in_b);

    /// \section    Common Math
    /// \brief      Calculates the square of a number.
    ///
    /// \param in_v             Number to square.
    ///
    /// \returns    The resulting squared number.
    double square(double in_v);

    /// \section    Common Math
    /// \brief      Calculates the square root of a number.
    ///
    /// \param in_v             Number to get the square root of.
    ///
    /// \returns    The resulting square root.
    double sqrt(double in_v);

    /// \section    Common Math
    /// \brief      Calculates the absolute value of a number.
    ///
    /// \param in_int           Number to get the absolute value of.
    ///
    /// \returns    The absolute value of in_int.
    template <typename t_int>
    t_int abs(t_int in_int)
        {
        // e.g. 32-bit int is shifted by 31
        constexpr t_int loc_shift_amt = ((sizeof(t_int)*8) - 1);
        t_int tmp = in_int >> loc_shift_amt;
        return (in_int ^ tmp) - tmp;
        }

    /// \section    Common Math
    /// \brief      Calculates the inverse square root of a number.
    ///
    /// \param in_v             Number to get the square root of.
    ///
    /// \returns    The resulting inverse square root.
    double rsqrt(double in_v);

    ushort random_ushrt();

    /// \section    Common Math
    /// \brief      Returns a random double-precision float in the range [0,1).
    ///
    /// \returns    The resulting inverse square root.
    double random_flt();

RPF_CLOSE
