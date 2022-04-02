#include "gtest/gtest.h"
extern "C"
{
	#include "utils.h"
}

#include <cstring>

TEST(utils, split)
{
	char **ac = ft_lite_split(
		strdup("key1\nvalue1\nkey2\nvalue2\n\nsearch1\nsearch2\n"),
		'\n');
	std::string	ex[] = {"key1", "value1", "key2", "value2", "", "search1",
						"search2", ""};
	int i = 0;
	while (ac[i])
	{
		EXPECT_STREQ(ac[i], ex[i].c_str());
		i++;
	}
}

TEST(utils, split_with_empty)
{
	char **ac = ft_lite_split(strdup(""), '\n');
	EXPECT_STREQ(ac[0], NULL);
}
