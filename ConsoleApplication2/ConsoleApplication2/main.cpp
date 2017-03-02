#include "Circle.h"
#include <iostream>
#include <stdlib.h>
int main()
{
	circle c1 (5.f, 25.f, 4.f);
	circle c2 (2.f, 3.f, 10.f);
	
	bool m = c1.intersects(c2);
	if (m == true)
	{
		printf("Esta bien el codigo\n");
	}
	else if(m == false)
	{
		printf("TA MALO CO%cO\n", 165);
	}
	system("PAUSE");
}