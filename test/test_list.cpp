#include "list.h"

#include <gtest.h>

TEST(TList, can_create_empty_list)
{
	ASSERT_NO_THROW(TList <int> ls);
}

TEST(TList, list_IsEmpty)
{
	TList<int> ls;

	EXPECT_EQ(true, ls.IsEmpty());
}

TEST(TList, Search_in_list)
{
	TList<int> ls;

	EXPECT_EQ(0, ls.Search(2));
}

TEST(TList, can_insert_at_start)
{
	TList<int> ls;
	Item<int>* ft = new Item<int>;		ft->Data = 0;
	Item<int>* second = new Item<int>;	second->Data = 1;
	ls.InsertHead(ft);
	
	ASSERT_NO_THROW(ls.InsertHead(second));
}

TEST(TList, can_insert_at_end)
{
	TList<int> ls;
	Item<int>* nd = new Item<int>;
	nd->Data = 3;
	
	ASSERT_NO_THROW(ls.InsertEnd(nd));
}

TEST(TList, can_insert_at_pointer)
{
	TList<int> ls;
	Item<int>* ft = new Item<int>;		ft->Data = 0;
	Item<int>* second = new Item<int>;	second->Data = 1;
	Item<int>* third = new Item<int>;	third->Data = 2;
	ls.InsertHead(ft);
	ls.InsertPointer(ft, second);
	
	ASSERT_NO_THROW(ls.InsertPointer(ft, third));
}

TEST(TList, can_delete_at_start)
{
	TList<int> ls;
	Item<int>* ft = new Item<int>;		ft->Data = 0;
	Item<int>* second = new Item<int>;	second->Data = 1;
	ls.InsertHead(ft);
	ls.InsertPointer(ft, second);
	
	ASSERT_NO_THROW(ls.DeleteHead());
}

TEST(TList, can_delete_at_end)
{
	TList<int> ls;
	Item<int>* ft = new Item<int>;		ft->Data = 0;
	Item<int>* second = new Item<int>;	second->Data = 1;
	ls.InsertHead(ft);
	ls.InsertPointer(ft, second);
	
	ASSERT_NO_THROW(ls.DeleteEnd());
}

TEST(TList, can_delete_at_pointer)//
{
	TList<int> ls;
	Item<int>* ft = new Item<int>;		ft->Data = 0;
	Item<int>* second = new Item<int>;	second->Data = 1;
	Item<int>* third = new Item<int>;		third->Data = 2;
	ls.InsertHead(ft);
	ls.InsertPointer(ft, second);
	ls.InsertPointer(second, third);
	
	ASSERT_NO_THROW(ls.DeletePointer(ft));
}

TEST(TList, Search_elem)
{
	TList<int> ls;
	Item<int>* ft = new Item<int>;		ft->Data = 0;
	Item<int>* second = new Item<int>;	second->Data = 1;
	Item<int>* third = new Item<int>;		third->Data = 2;
	ls.InsertHead(ft);
	ls.InsertEnd(second);
	ls.InsertEnd(third);
	EXPECT_EQ(second, ls.Search(1));
}
