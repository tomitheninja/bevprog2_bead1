#include "vector_2.h"

#include <cmath>
#include <exception>

Vector2::Vector2(int x, int y) : m_x(x), m_y(y) {}

int Vector2::get_x() const { return x(); }

void Vector2::set_x(int x) { Vector2::m_x = x; }

int Vector2::get_y() const { return y(); }

void Vector2::set_y(int y) { Vector2::m_y = y; }

bool Vector2::operator==(const Vector2 &rhs) const {
  return m_x == rhs.m_x && m_y == rhs.m_y;
}

bool Vector2::operator!=(const Vector2 &rhs) const { return !(rhs == *this); }

std::ostream &operator<<(std::ostream &os, const Vector2 &vector_2) {
  os << "Vector2(" << vector_2.m_x << ", " << vector_2.m_y << ")";
  return os;
}

Vector2 Vector2::from_stream(std::istream &is) {
  int x, y;
  if (is >> x >> y) {
    return {x, y};
  } else {
    throw std::invalid_argument("Failed to parse the stream");
  }
}

Vector2::Vector2() = default;

int Vector2::len_squared() const { return x() * x() + y() * y(); }

float Vector2::len() const { return std::sqrt(len_squared()); }

void Vector2::set_canvas(genv::canvas *canvas) { this->ptr_canvas = canvas; }

void Vector2::move_to() const { *ptr_canvas << genv::move_to(x(), y()); }

void Vector2::line_to_abs(const Vector2 &v) const {
  this->move_to();
  *ptr_canvas << genv::line_to(v.x(), v.y());
}

void Vector2::line_to_rel(const Vector2 &v) const {
  this->move_to();
  *ptr_canvas << genv::line(v.x(), v.y());
}

void Vector2::draw_color(const Color &color) const {
  this->move_to();
  color.apply();
  *ptr_canvas << genv::dot;
}

void Vector2::rect_to_abs(const Vector2 &v) const {
  bool is_self_top_left = x() < v.x();
  if (is_self_top_left) {
    this->move_to();
    genv::gout << genv::box_to(v.x(), v.y());
  } else {
    v.move_to();
    genv::gout << genv::box_to(x(), y());
  }
}

void Vector2::clear_until(Color color) const {
  color.apply();
  Vector2 start(0, 0);
  start.set_canvas(ptr_canvas);
  start.rect_to_abs(*this);
}

void Vector2::clear() const { clear_until(); }

Vector2 Vector2::add(const Vector2 &rhs) const {
  return {x() + rhs.x(), y() + rhs.y()};
}

void Vector2::add_assign(const Vector2 &rhs) {
  add_assign_x(rhs.x());
  add_assign_y(rhs.y());
}

Vector2 Vector2::add_x(int x) const { return {get_x() + x, get_y()}; }

void Vector2::add_assign_x(int x) { set_x(get_x() + x); }

Vector2 Vector2::add_y(int y) const { return {x(), get_y() + y}; }

void Vector2::add_assign_y(int y) { set_y(get_y() + y); }

Vector2 Vector2::sub(const Vector2 &rhs) const {
  return {x() - rhs.x(), y() - rhs.y()};
}

void Vector2::sub_assign(const Vector2 &rhs) {
  sub_assign_x(rhs.x());
  sub_assign_y(rhs.y());
}

Vector2 Vector2::sub_x(int x) const { return {get_x() - x, get_y()}; }

void Vector2::sub_assign_x(int x) { set_x(get_x() - x); }

Vector2 Vector2::sub_y(int y) const { return {get_x(), get_y() - y}; }

void Vector2::sub_assign_y(int y) { set_y(get_y() - y); }

Vector2 Vector2::mul(int scalar) const { return {x() * scalar, y() * scalar}; }

void Vector2::mul_assign(int scalar) {
  set_x(x() * scalar);
  set_y(y() * scalar);
}

Vector2 Vector2::div(int scalar) const { return {x() / scalar, y() / scalar}; }

void Vector2::div_assign(int scalar) {
  set_x(x() / scalar);
  set_y(y() / scalar);
}

Vector2 Vector2::operator+(const Vector2 &rhs) const { return add(rhs); }

Vector2 Vector2::operator-(const Vector2 &rhs) const { return sub(rhs); }

Vector2 Vector2::operator*(int scalar) const { return mul(scalar); }

Vector2 Vector2::operator/(int scalar) const { return div(scalar); }

void Vector2::operator+=(const Vector2 &rhs) { add_assign(rhs); }

void Vector2::operator-=(const Vector2 &rhs) { sub_assign(rhs); }

void Vector2::operator*=(int scalar) { mul_assign(scalar); }

void Vector2::operator/=(int scalar) { div_assign(scalar); }

int Vector2::x() const { return m_x; }

int Vector2::y() const { return m_y; }
