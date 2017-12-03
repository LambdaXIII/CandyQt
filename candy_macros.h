#ifndef CANDYMACROS_H
#define CANDYMACROS_H


#define CANDY_PROPERTY(type,lower,upper) \
  private:\
  type m_##lower;\
  public: \
  inline type lower() const { return m_##lower;} \
  inline void set##upper(type x) { m_##lower = x;}


#define CANDY_PROPERTY_VALUE(type,lower,upper,value) \
  private:\
  type m_##lower = value;\
  public: \
  inline type lower() const { return m_##lower;} \
  inline void set##upper(type x) { m_##lower = x;}


#endif // CANDYMACROS_H
