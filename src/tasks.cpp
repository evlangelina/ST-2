// Copyright 2026 UNN-CS
#include "tasks.h"
#include "circle.h"

namespace {
const double kPi = 3.14159265358979323846;
}

double RopeGap() {
  const double earth_radius = 6378100.0;
  Circle circle(earth_radius);
  double initial_radius = circle.getRadius();
  double initial_ference = circle.getFerence();
  circle.setFerence(initial_ference + 1.0);
  double new_radius = circle.getRadius();
  return new_radius - initial_radius;
}

double PoolConcreteCost() {
  const double inner_radius = 3.0;
  const double outer_radius = 4.0;
  const double concrete_cost_per_square = 1000.0;
  Circle inner(inner_radius);
  Circle outer(outer_radius);
  double concrete_area = outer.getArea() - inner.getArea();
  return concrete_area * concrete_cost_per_square;
}

double PoolFenceCost() {
  const double outer_radius = 4.0;
  const double fence_cost_per_meter = 2000.0;
  Circle outer(outer_radius);
  double fence_length = outer.getFerence();
  return fence_length * fence_cost_per_meter;
}

