#include <stdio.h>
#include <conio.h>

int a[20][20], vis[20], stack[20], top = -1;
void push(int item);
int pop();
void dfs(int s, int n);
int main()
{
int n, i, j, s;
char c, dummy;
clrscr();
printf("ENTER THE NUMBER OF VERTICES: ");
scanf("%d", &n);
for (i = 1; i <= n; i++)
{
for (j = 1; j <= n; j++)
{
printf("ENTER 1 IF %d HAS AN EDGE WITH %d ELSE 0: ", i, j);
scanf("%d", &a[i][j]);
}
}

printf("THE ADJACENCY MATRIX IS\n");
for (i = 1; i <= n; i++)
{
for (j = 1; j <= n; j++)
{
printf("%d ", a[i][j]);
}
printf("\n");
}

Do
 {
for (i = 1; i <= n; i++)
{
vis[i] = 0;
}
printf("\nENTER THE SOURCE VERTEX: ");
scanf("%d", &s);
dfs(s, n);
printf("\nDO YOU WANT TO CONTINUE? (y/n): ");
scanf("%c", &dummy);
scanf("%c", &c);

}
 while (c == 'y' || c == 'Y');
getch();
return 0;
}
void dfs(int s, int n)
{
int i, k;
push(s);
vis[s] = 1;
while (top != -1)
{
k = pop();
printf("%d ", k);
for (i = 1; i <= n; i++)
{
if (a[k][i] == 1 && vis[i] == 0)
{
push(i);
vis[i] = 1;
}
}
}
}
void push(int item)
{
if (top == 19)
{
printf("Stack Overflow\n");
}
else
{
stack[++top] = item;
}
}
int pop()
{
if (top == -1)
{
return 0;
}
else
{
return stack[top--];
}
}
