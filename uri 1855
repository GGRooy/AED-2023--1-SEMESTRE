#include <stdio.h>
#include <string.h>

#define MAX_SIZE 106

char v[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

int main()
{
	int x, y;
	
	while (scanf("%d %d", &y, &x) == 2)
	{
		for (int i = 0 ; i < x; ++i)
			scanf("%s", v[i]);
			
		int flag = 0;
		int avancai = 0;
		int avancaj = 1;
		int i = 0;
		int j = 0;
		
		memset(visited, 0, sizeof(visited));
		
		while (1)
		{
			if (v[i][j] == '>')
			{
				avancai = 0;
				avancaj = 1;
			}
			else if (v[i][j] == '<')
			{
				avancai = 0;
				avancaj = -1;
			}
			else if (v[i][j] == 'v')
			{
				avancai = 1;
				avancaj = 0;
			}
			else if (v[i][j] == '^')
			{
				avancai = -1;
				avancaj = 0;
			}
			else if (v[i][j] == '*')
			{
				printf("*\n");
				flag = 1;
				break;
			}
			
			i += avancai;
			j += avancaj;
			
			if (visited[i][j] || i >= x || j >= y)
				break;
			
			visited[i][j] = 1;
		}
		
		if (!flag)
			printf("!\n");
	}
	
	return 0;
}
