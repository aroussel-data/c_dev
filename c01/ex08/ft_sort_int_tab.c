#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	// sort often involves checking value of current value and comparing with value of next value to see if it is larger or not. 
	
	// traverse the entirety of the array?
	int i;
	int temp;
	
	i = 0;
	temp = 0;
	
	//printf("%d", tab[i]);
	//printf("%d", tab[i+1]);

	
	while (tab[size-1] < tab[0])
	{
		// we have this [4, 3, 2, 1]
		// we want this [1, 2, 3, 4]
		// while value @ pos 0 > value @ pos 3 
		// compare 4 -> 3 : is 4 > 3? If so, set pos 0 to 3 and pos 0 + 1 to 4...
		// i++
		// move onto i = 1
		// is 3 > 2? If so, set pos 1 to 2 and pos 2 to 3
		// move onto i = 2
		// is 2 > 1? If so, set pos 2 to 1 and pos 3 to 2
		//
		// at this point we have something like: [3, 4, 1, 2] , so we need to do multiple passes...
		
		
		if (tab[i] > tab[i+1])
		{
			//need to swap current -> next so that the smallest of the two is in the leftmost position.
			temp = tab[i];
			tab[i] = tab[i+1];
			tab[i+1] = temp;	
		}
		printf("%d", tab[i]);
		i++;
		if (i == size-1)
		{
			// reset i to 
			i = 0;
		}
	}
	//printf("%d", tab[i+1]);
	
}

int	main(void)
{
	int int_array[4] = {4, 3, 2, 1};
	ft_sort_int_tab(int_array, 4);
}
