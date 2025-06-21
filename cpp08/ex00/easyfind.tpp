template <typename T>
//std::find() 1 param is begin, 2 param is end, 3 is to_find
int easyfind(T c, int find)
{
	return (((std::find(c.begin(), c.end(), find) == c.end())) ? 0 : 1);
	
}
