// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

TEST(CircleTest, DefaultConstructor) {
  Circle c;
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, ConstructorWithRadius) {
  Circle c(2.0);
  const double pi = 3.14159265358979323846;
  EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
  EXPECT_NEAR(c.getFerence(), 2.0 * pi * 2.0, 1e-9);
  EXPECT_NEAR(c.getArea(), pi * 2.0 * 2.0, 1e-9);
}

TEST(CircleTest, SetRadiusUpdatesOtherFields) {
  Circle c;
  const double pi = 3.14159265358979323846;
  c.setRadius(3.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
  EXPECT_NEAR(c.getFerence(), 2.0 * pi * 3.0, 1e-9);
  EXPECT_NEAR(c.getArea(), pi * 3.0 * 3.0, 1e-9);
}

TEST(CircleTest, SetFerenceUpdatesOtherFields) {
  const double pi = 3.14159265358979323846;
  Circle c;
  double ference = 2.0 * pi * 5.0;
  c.setFerence(ference);
  EXPECT_NEAR(c.getRadius(), 5.0, 1e-9);
  EXPECT_DOUBLE_EQ(c.getFerence(), ference);
  EXPECT_NEAR(c.getArea(), pi * 5.0 * 5.0, 1e-9);
}

TEST(CircleTest, SetAreaUpdatesOtherFields) {
  const double pi = 3.14159265358979323846;
  Circle c;
  double area = pi * 4.0 * 4.0;
  c.setArea(area);
  EXPECT_NEAR(c.getRadius(), 4.0, 1e-9);
  EXPECT_DOUBLE_EQ(c.getArea(), area);
  EXPECT_NEAR(c.getFerence(), 2.0 * pi * 4.0, 1e-9);
}

TEST(CircleTest, NegativeRadiusBecomesZero) {
  Circle c;
  c.setRadius(-1.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, NegativeFerenceBecomesZero) {
  Circle c;
  c.setFerence(-10.0);
  EXPECT_NEAR(c.getRadius(), 0.0, 1e-9);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, NegativeAreaBecomesZero) {
  Circle c;
  c.setArea(-5.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, MultipleUpdatesRadiusThenFerence) {
  const double pi = 3.14159265358979323846;
  Circle c(1.0);
  c.setRadius(2.0);
  double new_ference = 2.0 * pi * 3.0;
  c.setFerence(new_ference);
  EXPECT_NEAR(c.getRadius(), 3.0, 1e-9);
  EXPECT_DOUBLE_EQ(c.getFerence(), new_ference);
}

TEST(CircleTest, MultipleUpdatesRadiusThenArea) {
  const double pi = 3.14159265358979323846;
  Circle c(1.0);
  c.setRadius(2.0);
  double new_area = pi * 5.0 * 5.0;
  c.setArea(new_area);
  EXPECT_NEAR(c.getRadius(), 5.0, 1e-9);
  EXPECT_DOUBLE_EQ(c.getArea(), new_area);
}

TEST(CircleTest, ConsistencyBetweenSetters) {
  const double pi = 3.14159265358979323846;
  Circle c1;
  Circle c2;
  double radius = 2.5;
  double ference = 2.0 * pi * radius;
  double area = pi * radius * radius;

  c1.setRadius(radius);
  c2.setFerence(ference);

  EXPECT_NEAR(c1.getRadius(), c2.getRadius(), 1e-9);
  EXPECT_NEAR(c1.getFerence(), c2.getFerence(), 1e-9);
  EXPECT_NEAR(c1.getArea(), c2.getArea(), 1e-9);

  Circle c3;
  c3.setArea(area);
  EXPECT_NEAR(c1.getRadius(), c3.getRadius(), 1e-9);
  EXPECT_NEAR(c1.getFerence(), c3.getFerence(), 1e-9);
  EXPECT_NEAR(c1.getArea(), c3.getArea(), 1e-9);
}

TEST(TaskRopeTest, GapValue) {
  const double pi = 3.14159265358979323846;
  double gap = RopeGap();
  double expected = 1.0 / (2.0 * pi);
  EXPECT_NEAR(gap, expected, 1e-9);
}

TEST(TaskRopeTest, GapIsPositive) {
  double gap = RopeGap();
  EXPECT_GT(gap, 0.0);
}

TEST(TaskRopeTest, GapIndependentFromRadiusTheoretical) {
  const double pi = 3.14159265358979323846;
  double expected = 1.0 / (2.0 * pi);
  EXPECT_NEAR(expected, 0.159154943091895, 1e-12);
}

TEST(TaskRopeTest, CircleBasedAndFormulaAreClose) {
  const double pi = 3.14159265358979323846;
  double gap = RopeGap();
  double expected = 1.0 / (2.0 * pi);
  EXPECT_NEAR(gap, expected, 1e-9);
}

TEST(TaskPoolTest, ConcreteCostValue) {
  double cost = PoolConcreteCost();
  const double pi = 3.14159265358979323846;
  double expected_area = pi * 4.0 * 4.0 - pi * 3.0 * 3.0;
  double expected_cost = expected_area * 1000.0;
  EXPECT_NEAR(cost, expected_cost, 1e-6);
}

TEST(TaskPoolTest, FenceCostValue) {
  double cost = PoolFenceCost();
  const double pi = 3.14159265358979323846;
  double expected_length = 2.0 * pi * 4.0;
  double expected_cost = expected_length * 2000.0;
  EXPECT_NEAR(cost, expected_cost, 1e-6);
}

TEST(TaskPoolTest, ConcreteCostPositive) {
  double cost = PoolConcreteCost();
  EXPECT_GT(cost, 0.0);
}

TEST(TaskPoolTest, FenceCostPositive) {
  double cost = PoolFenceCost();
  EXPECT_GT(cost, 0.0);
}

TEST(TaskPoolTest, FenceCostGreaterThanConcreteCostForGivenData) {
  EXPECT_GT(PoolFenceCost(), PoolConcreteCost());
}
