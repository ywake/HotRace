// #include "gtest/gtest.h"
// extern "C"
// {
// 	#include "utils.h"
// }

// #include <cstring>

// bool test(char *input, std::string ex[])
// {
// 	char	**ac;
// 	bool	isSuccess;

// 	isSuccess = true;
// 	input = strdup(input);
// 	ac = ft_lite_split(input, '|');
// 	int i = 0;
// 	while (ac[i])
// 	{
// 		isSuccess = isSuccess && std::string(ac[i]) == ex[i];
// 		i++;
// 	}
// 	free(input);
// 	free(ac);
// 	return (isSuccess);
// }

// TEST(utils, split)
// {
// 	char *input;

// 	EXPECT_TRUE(test(
// 		"key1|value1|key2|value2||search1|search2|",
// 		(std::string []){"key1", "value1", "key2", "value2", "", "search1", "search2", ""}));

// 	EXPECT_TRUE(test(
// 		"split  ||this|for|me|||||!|",
// 		(std::string []){"split  ", "", "this", "for", "me", "", "", "", "", "!", ""}));

// 	EXPECT_TRUE(test(
// 		"",
// 		(std::string []){}));
// }
