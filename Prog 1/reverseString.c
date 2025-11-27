#include <ctype.h>
#include <stdio.h>
#include <string.h>

void reverseWord(char *start, char *end) {
	while (start < end) {
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

void reverseLettersInWords(char *str) {
	char *wordStart = NULL;
	char *ptr = str;

	while (*ptr) {
		if (wordStart == NULL && !isspace(*ptr)) {
			wordStart = ptr;  // Mark start of a word
		}

		if (wordStart && (isspace(*ptr) || *(ptr + 1) == '\0')) {
			char *wordEnd = (isspace(*ptr)) ? ptr - 1 : ptr;
			reverseWord(wordStart, wordEnd);
			wordStart = NULL;
		}

		ptr++;
	}
}

int main() {
	char str[100] = "I LOVE AUTOMATA";

	printf("Original String: %s\n", str);
	reverseLettersInWords(str);
	printf("Reversed Words: %s\n", str);

	return 0;
}
