#include <stdio.h>

int reverseNumber(int value) {
	int reversed = 0;
	while (value > 0) {
		int digit = value % 10;
		reversed = reversed * 10 + digit;
		value /= 10;
	}
	return reversed;
}

int printPalindromesInInterval(int start, int end) {
	int count = 0;
	for (int current = start; current <= end; current++) {
		int reversed = reverseNumber(current);
		(current >= 0 && current == reversed) ? (printf("%d ", current), count++) : 0;
	}
	printf("\n");
	return count;
}

int main(void) {
	int start, end;
	printf("Digite dois inteiros (n1 < n2): ");
	if (scanf("%d %d", &start, &end) != 2) {
		printf("Entrada invalida.\n");
		return 1;
	}
	if (start >= end) {
		printf("Intervalo invalido. O primeiro numero deve ser menor que o segundo.\n");
		return 1;
	}
	int palindromeCount = printPalindromesInInterval(start, end);
	printf("Total de palindromos: %d\n", palindromeCount);
	return 0;
}

 