#include "gtest/gtest.h"

#include "Positionable.h"

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(Position, EqualityComparisonOperator) {
  Game::Position a(2.f, 2.f), b(2.f, 2.f);
  ASSERT_EQ(a, b);
}

TEST(Position, InequalityComparisonOperator) {
  Game::Position a(3.f, 2.f), b(2.f, 3.f);
  ASSERT_NE(a, b);
}

TEST(Positionable, DefaultConstructor) {
  Game::Positionable p;
  ASSERT_EQ(p.GetPosition(), Game::Position(0.f, 0.f));
}

TEST(Positionable, PositionConstructor) {
  Game::Positionable p { Game::Position { 1.f, 1.f } };
  ASSERT_EQ(p.GetPosition(), Game::Position(1.f, 1.f));
}

TEST(Positionable, XYConstructor) {
  Game::Positionable p { 1.f, 1.f };
  ASSERT_EQ(p.GetPosition(), Game::Position(1.f, 1.f));
}

TEST(Positionable, SetPosition) {
  Game::Positionable p;
  p.SetPosition(Game::Position { 3.f, 3.f });
  ASSERT_EQ(p.GetPosition(), Game::Position(3.f, 3.f));
}

TEST(Positionable, SetPositionXY) {
  Game::Positionable p;
  p.SetPosition(3.f, 3.f);
  ASSERT_EQ(p.GetPosition(), Game::Position(3.f, 3.f));
}

TEST(Positionable, SetPositionX) {
  Game::Positionable p;
  p.SetPositionX(4.f);
  ASSERT_EQ(p.GetPositionX(), 4.f);
}

TEST(Positionable, SetPositionY) {
  Game::Positionable p;
  p.SetPositionY(4.f);
  ASSERT_EQ(p.GetPositionY(), 4.f);
}

TEST(Positionable, GetPosition) {
  Game::Positionable p { 1.f, 2.f };
  ASSERT_EQ(p.GetPosition(), Game::Position(1.f, 2.f));
}

TEST(Positionable, GetPositionX) {
  Game::Positionable p { 1.f, 2.f };
  ASSERT_EQ(p.GetPositionX(), 1.f);
}

TEST(Positionable, GetPositionY) {
  Game::Positionable p { 1.f, 2.f };
  ASSERT_EQ(p.GetPositionY(), 2.f);
}
