#ifndef STRONG_TYPE_HPP
#define STRONG_TYPE_HPP
/*******************************************************************************
 * \file
 * Allows built-in types to be strongly typed.
 *
 * \author Markus Saers <masaers>
 ******************************************************************************/


/*******************************************************************************
 * Defines the behaviour of strong types where it is important to
 * maintain the type (typically, doing arithmatic with strong types
 * devolves them to their base type).
 *
 * \author Markus Saers <masaers>
 ******************************************************************************/
template<typename T, typename value_T>
struct strong_type_crtp {
  strong_type_crtp(value_T value) : value_m(value) {}
  inline operator value_T&() { return value_m; }
  inline operator value_T const&() const { return value_m; }
  template<typename U>
  inline T& operator+=(U&& x) { value_m += x; return static_cast<T&>(*this); }
  template<typename U>
  inline T& operator-=(U&& x) { value_m -= x; return static_cast<T&>(*this); }
  template<typename U>
  inline T& operator*=(U&& x) { value_m *= x; return static_cast<T&>(*this); }
  template<typename U>
  inline T& operator/=(U&& x) { value_m /= x; return static_cast<T&>(*this); }
  template<typename U>
  inline T& operator%=(U&& x) { value_m %= x; return static_cast<T&>(*this); }
  template<typename U>
  inline T& operator>>=(U&& x) { value_m >>= x; return static_cast<T&>(*this); }
  template<typename U>
  inline T& operator<<=(U&& x) { value_m <<= x; return static_cast<T&>(*this); }
  template<typename U>
  inline T& operator^=(U&& x) { value_m ^= x; return static_cast<T&>(*this); }
  template<typename U>
  inline T& operator|=(U&& x) { value_m |= x; return static_cast<T&>(*this); }
  template<typename U>
  inline T& operator&=(U&& x) { value_m &= x; return static_cast<T&>(*this); }
  inline T& operator++() { ++value_m; return static_cast<T&>(*this); }
  inline T operator++(int) { T x(value_m); ++value_m; return x; }
  inline T& operator--() { --value_m; return static_cast<T&>(*this); }
  inline T operator--(int) { T x(value_m); --value_m; return x; }
private:
  value_T value_m;
};


/*******************************************************************************
 * Defines a strong type named <code>name</code>, based on the
 * (built-in) type <code>type</code>.
 *
 * \author Markus Saers <masaers>
 ******************************************************************************/
#define strong_type(type, name)						\
  struct name : public strong_type_crtp<name, type> {			\
    inline name() = default;						\
    inline name(name const&) = default;					\
    inline name(name&&) = default;					\
    inline name(type value) : strong_type_crtp<name, type>(value) {}	\
  }


/******************************************************************************/
#endif
