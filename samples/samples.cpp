#include <iostream>
#include <list.h>

int main() {

	TList<int> List;
	Item<int>* ft = new Item<int>;		ft->Data = 0;
	Item<int>* sc = new Item<int>;		sc->Data = 1;
	Item<int>* th = new Item<int>;		th->Data = 2;
	Item<int>* fh = new Item<int>;		fh->Data = 3;
	Item<int>* fi = new Item<int>;		fi->Data = 4;
	List.InsertHead(ft);
	List.InsertEnd(sc);
	List.InsertEnd(th);
	List.InsertEnd(fh);
	List.InsertEnd(fi);
	List.FindFromEnd(2);

	TList<int> List1;
	Item<int>* first = new Item<int>;		first->Data = 0;
	List1.InsertHead(first);
	List1.FindFromEnd(1);
}