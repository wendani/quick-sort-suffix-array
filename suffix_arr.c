#include <string.h>
#include <stdio.h>

void qsort(char *str[], int len)
{
	int piv, i;
	char *temp;

	if ((!str) || (len <= 0))
		return;
	
	if (len == 1)
		return;

	// reach here, we have at least two elements
	piv = 0;
	temp = str[piv];
	for (i = piv + 1; i < len; i++)
		if (strcmp(str[i], temp) < 0) {
			str[piv] = str[i];
			str[i] = str[piv + 1];
			piv++;
		}
	str[piv] = temp;

	qsort(str, piv);
	qsort(str + piv + 1, len - piv - 1);
}

int main(int argc, char *argv[])
{
	int i;
	char c[] = "banana";
	int len = sizeof(c);
	char **a = (char **)malloc(len * sizeof(char *));

	for (i = 0; i < len; i++)
		a[i] = &c[i];
	
	qsort(a, len);
	for (i = 0; i < len; i++)
		printf("%s\n", a[i]);

	return 0;
}
