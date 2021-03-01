#ifndef VECTOR_2_H
#define VECTOR_2_H

#include <graphics.hpp>
#include <iostream>

#include "color.h"

class Vector2 {
  int m_x = 0, m_y = 0;
  genv::canvas *ptr_canvas = &genv::gout;

 public:
  Vector2();

  Vector2(int x, int y);

  static Vector2 from_stream(std::istream &is);

  int len_squared() const;

  float len() const;

  void set_canvas(genv::canvas *canvas);

  void move_to() const;

  void line_to_abs(const Vector2 &v) const;

  void line_to_rel(const Vector2 &v) const;

  void draw_color(const Color &color) const;

  void rect_to_abs(const Vector2 &v) const;

  void clear_until(Color color = {0, 0, 0}) const;

  void clear() const;

  friend std::ostream &operator<<(std::ostream &os, const Vector2 &vector_2);

  bool operator==(const Vector2 &rhs) const;

  bool operator!=(const Vector2 &rhs) const;

  int x() const;

  int get_x() const;

  void set_x(int x);

  int y() const;

  int get_y() const;

  void set_y(int y);

  Vector2 add(const Vector2 &rhs) const;

  void add_assign(const Vector2 &rhs);

  Vector2 add_x(int x) const;

  void add_assign_x(int x);

  Vector2 add_y(int y) const;

  void add_assign_y(int y);

  Vector2 sub(const Vector2 &rhs) const;

  void sub_assign(const Vector2 &rhs);

  Vector2 sub_x(int x) const;

  void sub_assign_x(int x);

  Vector2 sub_y(int y) const;

  void sub_assign_y(int y);

  Vector2 mul(int scalar) const;

  void mul_assign(int scalar);

  Vector2 div(int scalar) const;

  void div_assign(int scalar);

  Vector2 operator+(const Vector2 &rhs) const;

  void operator+=(const Vector2 &rhs);

  Vector2 operator-(const Vector2 &rhs) const;

  void operator-=(const Vector2 &rhs);

  Vector2 operator*(int scalar) const;

  void operator*=(int scalar);

  Vector2 operator/(int scalar) const;

  void operator/=(int scalar);
};

#endif  // VECTOR_2_H
