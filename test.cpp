#include "c-echo.h"
#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
	char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
	EXPECT_EQ("hello world", echo(3,test_val));
}

TEST(EchoTest, EmptyString) {
	char* test_val[1]; test_val[0] = "./c-echo";
	EXPECT_EQ("", echo(1,test_val));
}

TEST(EchoTest, SpecialChars){
	char* test_val[5]; test_val[0] = "./c-echo"; test_val[1] = "\n"; test_val[2] = "\""; test_val[3] = "\t"; test_val[4] = "finish";
	EXPECT_EQ("\n \" \t finish", echo(5,test_val));
}

TEST(EchoTest, Alphabet){
	char* test_val[2]; test_val[0] = "./c-echo"; test_val[1] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!$%^&*()-=_+[]{};:\",./<>?";
	EXPECT_EQ("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!$%^&*()-=_+[]{};:\",./<>?", echo(2,test_val));
}

TEST(EchoTest, SimpleSentence) {
	char* test_val[5]; test_val[0] = "./c-echo"; test_val[1] = "This"; test_val[2] = "is"; test_val[3] = "a"; test_val[4] = "sentence.";
	EXPECT_EQ("This is a sentence.", echo(5,test_val));
}

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
