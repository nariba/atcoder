// テストケース記述ファイル
#include "gtest/gtest.h" // googleTestを使用するおまじないはこれだけでOK
// テスト対象関数を呼び出せるようにするのだが
// extern "C"がないとCと解釈されない、意外とハマりがち。
extern "C" {
    #include "C.h"
}

// fixtureNameはテストケース群をまとめるグループ名と考えればよい、任意の文字列
// それ以外のclass～testing::Testまではおまじないと考える
class test_wind : public ::testing::Test {
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
TEST_F(test_wind, test1)
{
    EXPECT_EQ(10.5, wind_dis_convert(628));
    EXPECT_EQ(0, wind_dis_convert(0));
    EXPECT_EQ(0.3, wind_dis_convert(15));
    EXPECT_EQ(32.7, wind_dis_convert(1959));
    EXPECT_EQ(17.2, wind_dis_convert(1029));
    EXPECT_EQ(10.7, wind_dis_convert(644));
    EXPECT_EQ(3.4, wind_dis_convert(201));
    EXPECT_EQ(0.3, wind_dis_convert(16));

}
TEST_F(test_wind, test2)
{
    EXPECT_EQ(0, wind_dis(0));
    EXPECT_EQ(0, wind_dis(0.2));

    EXPECT_EQ(1, wind_dis(0.3));
    EXPECT_EQ(1, wind_dis(1.5));

    EXPECT_EQ(2, wind_dis(1.6));
    EXPECT_EQ(2, wind_dis(3.3));

    EXPECT_EQ(3, wind_dis(3.4));
    EXPECT_EQ(3, wind_dis(5.4));

    EXPECT_EQ(4, wind_dis(5.5));
    EXPECT_EQ(4, wind_dis(7.9));

    EXPECT_EQ(5, wind_dis(8));
    EXPECT_EQ(5, wind_dis(10.7));

    EXPECT_EQ(6, wind_dis(10.8));
    EXPECT_EQ(6, wind_dis(13.8));

    EXPECT_EQ(7, wind_dis(13.9));
    EXPECT_EQ(7, wind_dis(17.1));

    EXPECT_EQ(8, wind_dis(17.2));
    EXPECT_EQ(8, wind_dis(20.7));

    EXPECT_EQ(9, wind_dis(20.8));
    EXPECT_EQ(9, wind_dis(24.4));

    EXPECT_EQ(10, wind_dis(24.5));
    EXPECT_EQ(10, wind_dis(28.4));

    EXPECT_EQ(11, wind_dis(28.5));
    EXPECT_EQ(11, wind_dis(32.6));

    EXPECT_EQ(12, wind_dis(32.7));

}

TEST_F(test_wind, test3)
{
    char ret[3];
    wind_deg(11.25, 1, ret);
    EXPECT_STREQ("NNE", ret);
    wind_deg(33.74, 1, ret);
    EXPECT_STREQ("NNE", ret);

    wind_deg(33.75, 1, ret);
    EXPECT_STREQ("NE", ret);
    wind_deg(56.24, 1, ret);
    EXPECT_STREQ("NE", ret);

    wind_deg(56.25, 1, ret);
    EXPECT_STREQ("ENE", ret);
    wind_deg(78.74, 1, ret);
    EXPECT_STREQ("ENE", ret);

    wind_deg(78.75, 1, ret);
    EXPECT_STREQ("E", ret);
    wind_deg(101.24, 1, ret);
    EXPECT_STREQ("E", ret);

    wind_deg(101.25, 1, ret);
    EXPECT_STREQ("ESE", ret);
    wind_deg(123.74, 1, ret);
    EXPECT_STREQ("ESE", ret);

    wind_deg(123.75, 1, ret);
    EXPECT_STREQ("SE", ret);
    wind_deg(146.24, 1, ret);
    EXPECT_STREQ("SE", ret);

    wind_deg(146.25, 1, ret);
    EXPECT_STREQ("SSE", ret);
    wind_deg(168.74, 1, ret);
    EXPECT_STREQ("SSE", ret);

    wind_deg(168.75, 1, ret);
    EXPECT_STREQ("S", ret);
    wind_deg(191.24, 1, ret);
    EXPECT_STREQ("S", ret);

    wind_deg(191.25, 1, ret);
    EXPECT_STREQ("SSW", ret);
    wind_deg(213.74, 1, ret);
    EXPECT_STREQ("SSW", ret);

    wind_deg(213.75, 1, ret);
    EXPECT_STREQ("SW", ret);
    wind_deg(236.24, 1, ret);
    EXPECT_STREQ("SW", ret);

    wind_deg(236.25, 1, ret);
    EXPECT_STREQ("WSW", ret);
    wind_deg(258.74, 1, ret);
    EXPECT_STREQ("WSW", ret);

    wind_deg(258.75, 1, ret);
    EXPECT_STREQ("W", ret);
    wind_deg(281.24, 1, ret);
    EXPECT_STREQ("W", ret);

    wind_deg(281.25, 1, ret);
    EXPECT_STREQ("WNW", ret);
    wind_deg(303.74, 1, ret);
    EXPECT_STREQ("WNW", ret);

    wind_deg(303.75, 1, ret);
    EXPECT_STREQ("NW", ret);
    wind_deg(326.24, 1, ret);
    EXPECT_STREQ("NW", ret);

    wind_deg(326.25, 1, ret);
    EXPECT_STREQ("NNW", ret);
    wind_deg(348.74, 1, ret);
    EXPECT_STREQ("NNW", ret);

    wind_deg(348.75, 1, ret);
    EXPECT_STREQ("N", ret);
    wind_deg(11.24, 1, ret);
    EXPECT_STREQ("N", ret);

    wind_deg(101.25, 0, ret);
    EXPECT_STREQ("C", ret);

}
