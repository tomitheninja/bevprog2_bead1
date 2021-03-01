#include "color.h"

#include <graphics.hpp>

Color::Color(int r, int g, int b) : m_r(r), m_g(g), m_b(b) {}

int Color::get_r() const { return r(); }

void Color::set_r(int r) { Color::m_r = r; }

int Color::get_g() const { return g(); }

void Color::set_g(int g) { Color::m_g = g; }

int Color::get_b() const { return b(); }

void Color::set_b(int b) { Color::m_b = b; }

bool Color::operator==(const Color &rhs) const {
  return m_r == rhs.m_r && m_g == rhs.m_g && m_b == rhs.m_b;
}

bool Color::operator!=(const Color &rhs) const { return !(rhs == *this); }

std::ostream &operator<<(std::ostream &os, const Color &color) {
  os << "Color(" << color.m_r << ", " << color.m_g << ", " << color.m_b << ")";
  return os;
}

int Color::r() const { return m_r; }

int Color::g() const { return m_g; }

int Color::b() const { return m_b; }

void Color::apply() const { genv::gout << genv::color(r(), g(), b()); }

Color Color::from_stream(std::istream &is) {
  int r = 0, g = 0, b = 0;
  if (is >> r >> g >> b) {
    return {r, g, b};
  } else {
    throw std::invalid_argument("Failed to parse the stream");
  }
}

bool Color::equal(const Color &x, int epsilon) const {
  auto abs = [](int x) { return x > 0 ? x : -x; };
  return abs(r() - x.r()) < epsilon && abs(g() - x.g()) < epsilon &&
         abs(b() - x.b()) < epsilon;
}

bool Color::not_equal(const Color &rhs, int epsilon) const {
  return !equal(rhs, epsilon);
}
