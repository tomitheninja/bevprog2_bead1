#ifndef COLOR_H
#define COLOR_H

#include <iostream>

class Color {
  int m_r = 0, m_g = 0, m_b = 0;

 public:
  void apply() const;

  static Color from_stream(std::istream &is);

  bool equal(const Color &rhs, int epsilon = 0) const;

  bool not_equal(const Color &rhs, int epsilon = 0) const;

  friend std::ostream &operator<<(std::ostream &os, const Color &color);

  bool operator==(const Color &rhs) const;

  bool operator!=(const Color &rhs) const;

  int r() const;

  int get_r() const;

  void set_r(int r);

  int g() const;

  int get_g() const;

  void set_g(int g);

  int b() const;

  int get_b() const;

  void set_b(int b);

  Color(int r, int g, int b);
};

#endif  // COLOR_H
