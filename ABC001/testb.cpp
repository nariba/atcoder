// テストケース記述ファイル
#include "gtest/gtest.h" // googleTestを使用するおまじないはこれだけでOK
// テスト対象関数を呼び出せるようにするのだが
// extern "C"がないとCと解釈されない、意外とハマりがち。
extern "C" {
    #include "B.h"
}

// fixtureNameはテストケース群をまとめるグループ名と考えればよい、任意の文字列
// それ以外のclass～testing::Testまではおまじないと考える
class fixtureName : public ::testing::Test {
protected:
    // fixtureNameでグループ化されたテストケースはそれぞれのテストケース実行前に
    // この関数を呼ぶ。共通の初期化処理を入れておくとテストコードがすっきりする
    virtual void SetUp(){
    }
    // SetUpと同様にテストケース実行後に呼ばれる関数。共通後始末を記述する。
    virtual void TearDown(){
    }
};

// 成功するテストケース。細かい説明はGoogleTestのマニュアルを見てね。
TEST_F(fixtureName, test1)
{
    EXPECT_EQ(00, visibility(10));
    EXPECT_EQ(00, visibility(99));
}
TEST_F(fixtureName, test2)
{
    EXPECT_EQ(01, visibility(100));
    EXPECT_EQ(20, visibility(2000));
    EXPECT_EQ(50, visibility(5000));
}

TEST_F(fixtureName, test3)
{
    EXPECT_EQ(56, visibility(6000));
    EXPECT_EQ(65, visibility(15000));
    EXPECT_EQ(80, visibility(30000));
}

TEST_F(fixtureName, test4)
{
    EXPECT_EQ(81, visibility(35000));
    EXPECT_EQ(82, visibility(40000));
    EXPECT_EQ(88, visibility(70000));
}
TEST_F(fixtureName, test5)
{
    EXPECT_EQ(89, visibility(70001));
    EXPECT_EQ(89, visibility(80000));
}
