#ifndef STRONG_TYPE_HPP
#define STRONG_TYPE_HPP
/*******************************************************************************
 * \file
 * Allows built-in types to be strongly typed.
 *
 * \author Markus Saers <masaers>
 ******************************************************************************/

/*******************************************************************************
 * Defines a strong type named <code>name</code>, based on the
 * (built-in) type <code>type</code>.
 *
 * \author Markus Saers <masaers>
 ******************************************************************************/
#define strong_type(type, name)						\
  struct name {								\
    inline name() = default;						\
    inline name(name const&) = default;					\
    inline name(name&&) = default;					\
    inline name(type value) : value_m(value) {}				\
    inline operator type&() { return value_m; }				\
    inline operator type const&() const { return value_m; }		\
  private: type value_m;						\
  }


/******************************************************************************/
#endif
