/*
** EPITECH PROJECT, 2017
** Maxime Aiguier
** File description:
** Header file
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void strlen_tests(void)
{
	char hello[] = "Hello world!";
	char empty[] = "";
	char one[] = "1";

	printf("--- STRLEN TESTS ---\n");
	printf("expected : [12] got : [%lu]\n", strlen(hello));
	printf("expected : [0] got : [%lu]\n", strlen(empty));
	printf("expected : [1] got : [%lu]\n", strlen(one));
}

void strchr_tests(void)
{
	char hello[] = "Hello world!";
	char *str_chr = strchr(hello, (int)'w');
	char *str_chr_null = strchr(hello, (int)'!');
	char *str_chr_minus = strchr(hello, (int)'h');
	char *str_chr_first = strchr(hello, (int)'H');
	char *str_chr_zero = strchr(hello, 0);
	char *str_chr_backslah = strchr(hello, '\n');

	printf("--- STRCHR TESTS ---\n");
	printf("expected : [world!] got : [%s]\n", str_chr);
	printf("expected : [!] got : [%s]\n", str_chr_null);
	printf("expected : [(null)] got : [%s]\n", str_chr_minus);
	printf("expected : [Hello world!] got : [%s]\n", str_chr_first);
	printf("expected : [] got : [%s]\n", str_chr_zero);
	printf("expected : [(null)] got : [%s]\n", str_chr_backslah);
}

void memset_tests(void)
{
	char str[] = "Hello world!";
	char str_two[] = "Hello world!";
	char str_slash[] = "Hello world!";
	char str_zero[] = "Hello world!";
	char str_zero_len[] = "Hello world!";

	memset(str,'$',2);
	memset(str_two,'?',5);
	memset(str_slash, '\n', 2);
	memset(str_zero, 0, 3);
	memset(str_zero_len, 'c', 0);
	printf("--- MEMSET TESTS ---\n");
	printf("expected : [$$llo world!] got : [%s]\n", str);
	printf("expected : [????? world!] got : [%s]\n", str_two);
	printf("expected : [\n\nllo world!] got : [%s]\n", str_slash);
	printf("expected : [] got : [%s]\n", str_zero);
	printf("expected : [Hello world!] got : [%s]\n", str_zero_len);
}

void memcpy_tests(void)
{
	char hello[] = "Hello";
	char world[] = "world!";
	char azerty[] = "azerty";
	char full[] = "full";
	char empty[] = "empty";

	memcpy(hello, "yo", 2);
	memcpy(world, hello, 4);
	memcpy(azerty, world, 2);
	memcpy(full, azerty, 4);
	memcpy(empty, hello, 0);
	printf("--- MEMCPY TESTS ---\n");
	printf("expected : [yollo] got : [%s]\n", hello);
	printf("expected : [yolld!] got : [%s]\n", world);
	printf("expected : [yoerty] got : [%s]\n", azerty);
	printf("expected : [yoer] got : [%s]\n", full);
	printf("expected : [empty] got : [%s]\n", empty);
}

void strcmp_tests(void)
{
	char lower[] = "abcdef";
	char upper[] = "ABCDEF";
	char upper_cpy[] = "ABCDEF";
	char hello[] = "Hello";
	char world[] = "world!";
	char hello_world[] = "Hello world!";
	char empty[] = "";

	printf("--- STRCMP TESTS ---\n");
	printf("expected [-65] got : [%d]\n", strcmp("", upper));
	printf("expected [-97] got : [%d]\n", strcmp("", lower));
	printf("expected [32] got : [%d]\n", strcmp(lower, upper));
	printf("expected [-32] got : [%d]\n", strcmp(upper, lower));
	printf("expected [0] got : [%d]\n", strcmp(upper, upper_cpy));
	printf("expected [-47] got : [%d]\n", strcmp(hello, world));
	printf("expected [47] got : [%d]\n", strcmp(world, hello));
	printf("expected [32] got : [%d]\n", strcmp(hello_world, hello));
	printf("expected [-47] got : [%d]\n", strcmp(hello_world, world));
	printf("expected [-32] got : [%d]\n", strcmp(hello, hello_world));
	printf("expected [47] got : [%d]\n", strcmp(world, hello_world));
	printf("expected [119] got : [%d]\n", strcmp(world, empty));
	printf("expected [72] got : [%d]\n", strcmp(hello, empty));
	printf("expected [72] got : [%d]\n", strcmp(hello_world, empty));
	printf("expected [-72] got : [%d]\n", strcmp(empty, hello_world));
	printf("expected [-72] got : [%d]\n", strcmp(empty, hello));
	printf("expected [-119] got : [%d]\n", strcmp(empty, world));
	printf("expected [0] got : [%d]\n", strcmp(empty, ""));
	printf("expected [0] got : [%d]\n", strcmp(hello, hello));
	printf("expected [0] got : [%d]\n", strcmp(hello_world, hello_world));
}

void strncmp_tests(void)
{
	char lower[] = "azerty";
	char upper[] = "qwerty";
	char upper_cpy[] = "BHUJKL";
	char hello[] = "bonjour";
	char world[] = "monde !";
	char hello_world[] = "Bonjour monde";
	char empty[] = "";
	char a[] = "a";
	char c[] = "c";
	char onemore[] = "One more test!";
	char one[] = "One more";

	printf("--- STRNCMP TESTS ---\n");
	printf("expected [0] got : [%d]\n", strncmp(onemore, one, 8));
	printf("expected [0] got : [%d]\n", strncmp(a, c, 0));
	printf("expected [-2] got : [%d]\n", strncmp(a, c, 1));
	printf("expected [-16] got : [%d]\n", strncmp(lower, upper, 2));
	printf("expected [16] got : [%d]\n", strncmp(upper, lower, 9));
	printf("expected [47] got : [%d]\n", strncmp(upper, upper_cpy, 1));
	printf("expected [0] got : [%d]\n", strncmp(hello, world, 0));
	printf("expected [11] got : [%d]\n", strncmp(world, hello, 5));
	printf("expected [-32] got : [%d]\n", strncmp(hello_world, hello, 6));
	printf("expected [-43] got : [%d]\n", strncmp(hello_world, world, 2));
	printf("expected [32] got : [%d]\n", strncmp(hello, hello_world, 1));
	printf("expected [43] got : [%d]\n", strncmp(world, hello_world, 7));
	printf("expected [109] got : [%d]\n", strncmp(world, empty, 8));
	printf("expected [98] got : [%d]\n", strncmp(hello, empty, 2));
	printf("expected [66] got : [%d]\n", strncmp(hello_world, empty, 3));
	printf("expected [-66] got : [%d]\n", strncmp(empty, hello_world, 1));
	printf("expected [-98] got : [%d]\n", strncmp(empty, hello, 7));
	printf("expected [-109] got : [%d]\n", strncmp(empty, world, 1));
	printf("expected [0] got : [%d]\n", strncmp(empty, "", 2));
	printf("expected [0] got : [%d]\n", strncmp(hello, hello, 5));
	printf("expected [0] got : [%d]\n", strncmp(hello_world, hello_world, 5));
}

void strcasecmp_tests(void)
{
	char lower[] = "AzerTy";
	char upper[] = "qWerty";
	char AZ[] = "AZ";
	char AZ2[] = "AzZ";
	char AZ3[] = "aAZz";
	char AZ4[] = "AazZ";
	char AZ5[] = "6AZ0";
	char AZ6[] = "jhsjAZsyu!";
	char AZ7[] = "(à()AZ))";
	char bhujkl_upper[] = "BHUJKL";
	char bhujkl[] = "bhujkl";
	char bhujkl_both[] = "bHUjKl";

	printf("--- STRCASECMP TESTS ---\n");
	printf("expected [-113] got : [%d]\n", strcmp("", upper));
	printf("expected [-65] got : [%d]\n", strcmp("", lower));
	printf("expected [-16] got : [%d]\n", strcasecmp(lower, upper));
	printf("expected [16] got : [%d]\n", strcasecmp(upper, lower));
	printf("expected [0] got : [%d]\n", strcasecmp(upper, upper));
	printf("expected [0] got : [%d]\n", strcasecmp(AZ, AZ));
	printf("expected [-122] got : [%d]\n", strcasecmp(AZ, AZ2));
	printf("expected [25] got : [%d]\n", strcasecmp(AZ2, AZ3));
	printf("expected [0] got : [%d]\n", strcasecmp(AZ3, AZ4));
	printf("expected [43] got : [%d]\n", strcasecmp(AZ4, AZ5));
	printf("expected [66] got : [%d]\n", strcasecmp(AZ6, AZ7));
	printf("expected [-57] got : [%d]\n", strcasecmp(AZ7, AZ));
	printf("expected [0] got : [%d]\n", strcasecmp(bhujkl_upper, bhujkl));
	printf("expected [0] got : [%d]\n", strcasecmp(bhujkl, bhujkl_upper));
	printf("expected [0] got : [%d]\n", strcasecmp(bhujkl_upper, bhujkl_upper));
	printf("expected [0] got : [%d]\n", strcasecmp(bhujkl_upper, bhujkl_both));
	printf("expected [0] got : [%d]\n", strcasecmp(bhujkl_both, bhujkl_both));
}

void rindex_tests()
{
	char hello[] = "hello";
	char azerty[] = "azerty";
	char querty[] = "querty";
	char upper[] = "UppeR";
	char upper2[] = "UPpeR";
	char a[] = "a";
	char au[] = "A";

	printf("--- RINDEX TESTS ---\n");
	printf("expected [lo] got : [%s]\n", rindex(hello, 'l'));
	printf("expected [o] got : [%s]\n", rindex(hello, 'o'));
	printf("expected [hello] got : [%s]\n", rindex(hello, 'h'));
	printf("expected [(null)] got : [%s]\n", rindex(hello, 'z'));
	printf("expected [azerty] got : [%s]\n", rindex(azerty, 'a'));
	printf("expected [y] got : [%s]\n", rindex(azerty, 'y'));
	printf("expected [querty] got : [%s]\n", rindex(querty, 'q'));
	printf("expected [y] got : [%s]\n", rindex(querty, 'y'));
	printf("expected [(null)] got : [%s]\n", rindex(querty, 'a'));
	printf("expected [(null)] got : [%s]\n", rindex(upper, 'u'));
	printf("expected [UppeR] got : [%s]\n", rindex(upper, 'U'));
	printf("expected [(null)] got : [%s]\n", rindex(upper, 'r'));
	printf("expected [R] got : [%s]\n", rindex(upper, 'R'));
	printf("expected [eR] got : [%s]\n", rindex(upper, 'e'));
	printf("expected [(null)] got : [%s]\n", rindex(upper2, 'u'));
	printf("expected [peR] got : [%s]\n", rindex(upper2, 'p'));
	printf("expected [Pper] got : [%s]\n", rindex(upper2, 'P'));
	printf("expected [eR] got : [%s]\n", rindex(upper2, 'e'));
	printf("expected [(null)] got : [%s]\n", rindex(upper2, 'E'));
	printf("expected [R] got : [%s]\n", rindex(upper2, 'R'));
	printf("expected [a] got : [%s]\n", rindex(a, 'a'));
	printf("expected [(null)] got : [%s]\n", rindex(a, 'A'));
	printf("expected [A] got : [%s]\n", rindex(au, 'A'));
	printf("expected [(null)] got : [%s]\n", rindex(au, 'a'));
	printf("expected [(null)] got : [%s]\n", rindex(au, 'b'));
	printf("expected [] got : [%s]\n", rindex(a, 0));
	printf("expected [(null)] got : [%s]\n", rindex(a, '\n'));
	printf("expected [(null)] got : [%s]\n", rindex("", 'A'));
	printf("expected [] got : [%s]\n", rindex("", 0));
}

void strpbrk_tests()
{
	char hello[] = "hello";
	char hellou[] = "HELLO";
	char azerty[] = "azerty";
	char upper[] = "UppER";
	char upper2[] = "UPpeR";
	char a[] = "a";
	char au[] = "A";
	char hu[] = "H";
	char h[] = "h";

	printf("--- STRPBRK TESTS ---\n");
	printf("expected [hello] got : [%s]\n", strpbrk(hello, hello));
	printf("expected [ello] got : [%s]\n", strpbrk(hello, azerty));
	printf("expected [(null)] got : [%s]\n", strpbrk(hello, a));
	printf("expected [o] got : [%s]\n", strpbrk(hello, "bonjour"));
	printf("expected [(null)] got : [%s]\n", strpbrk(hello, upper));
	printf("expected [ello] got : [%s]\n", strpbrk(hello, upper2));
	printf("expected [(null)] got : [%s]\n", strpbrk(hello, au));
	printf("expected [(null)] got : [%s]\n", strpbrk(hellou, au));
	printf("expected [(null)] got : [%s]\n", strpbrk(hellou, h));
	printf("expected [HELLO] got : [%s]\n", strpbrk(hellou, hu));
	printf("expected [ur] got : [%s]\n", strpbrk("onjour", "salutr"));
	printf("expected [hey] got : [%s]\n", strpbrk("hey", "hello"));
	printf("expected [hey] got : [%s]\n", strpbrk("hey", "ellho"));
	printf("expected [hello world!] got : [%s]\n", strpbrk("hello world!", "hello!"));
	printf("expected [!] got : [%s]\n", strpbrk("hello world!", "!"));
	printf("expected [!] got : [%s]\n", strpbrk("!", "salut! :)"));
}

void strcspn_tests()
{
	printf("--- STRCSPN TESTS ---\n");
	printf("expected [1] got : [%ld]\n", strcspn("hallo", "1234a"));
	printf("expected [0] got : [%ld]\n", strcspn("hallo", "hallo"));
	printf("expected [5] got : [%ld]\n", strcspn("hallo", "1234"));
	printf("expected [4] got : [%ld]\n", strcspn("hallo", "1o234"));
	printf("expected [1] got : [%ld]\n", strcspn("hallo", "123l4a"));
	printf("expected [5] got : [%ld]\n", strcspn("hallo", ""));
	printf("expected [0] got : [%ld]\n", strcspn("hallo", "h123l4a"));
	printf("expected [0] got : [%ld]\n", strcspn("", ""));
	printf("expected [0] got : [%ld]\n", strcspn("", "sds"));
}

void memmove_tests(void)
{
	char lower[10] = "azerty";
	char upper[112] = "qwerty";
	char upper_cpy[42] = "BHUJKL";
	char hello[9] = "bonjour";
	char world[8] = "monde !";
	char hello_world[17] = "Bonjour monde";
	char dest[10] = "oldstring";
	const char src[10] = "newstring";
	char warning[50] = "Warning,";
	char not_warning[100] = "Not Warning";

	printf("--- MEMMOVE TESTS ---\n");
	printf("expected : [$onjour] got : [%s]\n", memmove(hello, "$", 1));
	printf("expected : [?onde !] got : [%s]\n", memmove(world, "?", 1));
	printf("expected : [?onde !] got : [%s]\n", memmove(world, hello, 3));
	printf("expected : [Bonde !] got : [%s]\n", memmove(world, hello_world, 3));
	printf("expected : [newstring] got : [%s]\n", memmove(dest, src, 9));
	printf("expected : [worle !] got : [%s]\n", memmove(world, "world", 4));
	printf("expected : [world] got : [%s]\n", memmove(lower, "world", 7));
	printf("expected : [qwerd] got : [%s]\n", memmove(lower, upper, 4));
	printf("expected : [qwerty] got : [%s]\n", memmove(upper_cpy, upper, 19));
	printf("expected : [newstring] got : [%s]\n", memmove(dest, src, 9));
	printf("expected : [Thining,] got : [%s]\n", memmove(warning, "This is a test", 3));
	printf("expected : [Not Warning] got : [%s]\n", memmove(not_warning + 5, not_warning, strlen(not_warning) + 1));
	printf("expected : [helloooo] got : [%s]\n", memmove(hello, "helloooooo", strlen(hello) + 1));
	printf("expected : [helloooooo] got : [%s]\n", memmove(hello, "helloooooo", strlen(hello) + 12));
}

void strstr_tests()
{
	char tutorial[] = "TutorialPoint";
	char hello_world[] = "Hello World!";
	char hello[] = "Hello";
	char world[] = "World";
	char exclam[] = "!";
	char azerty[] = "azerty";
	char qwerty[] = "qwerty";
	char question[] = "Azerty or qwerty my friend ? :)";
	char point[] = "Point";
	char empty[] = "";
	char space[] = " ";
	char slash[] = "\n";
	char smile[] = ":)";

	printf("expected [Point] got : [%s]\n", strstr(tutorial, point));
	printf("expected [(null)] got : [%s]\n", strstr(tutorial, exclam));
	printf("expected [!] got : [%s]\n", strstr(hello_world, exclam));
	printf("expected [Hello World!] got : [%s]\n", strstr(hello_world, hello));
	printf("expected [World!] got : [%s]\n", strstr(hello_world, world));
	printf("expected [(null)] got : [%s]\n", strstr(hello, world));
	printf("expected [(null)] got : [%s]\n", strstr(world, hello));
	printf("expected [(null)] got : [%s]\n", strstr(world, hello_world));
	printf("expected [(null)] got : [%s]\n", strstr(hello, hello_world));
	printf("expected [(null)] got : [%s]\n", strstr(azerty, qwerty));
	printf("expected [qwerty] got : [%s]\n", strstr(qwerty, qwerty));
	printf("expected [(null)] got : [%s]\n", strstr(qwerty, azerty));
	printf("expected [(null)] got : [%s]\n", strstr(question, azerty));
	printf("expected [qwerty my friend ? :)] got : [%s]\n", strstr(question, qwerty));
	printf("expected [(null)] got : [%s]\n", strstr(azerty, question));
	printf("expected [(null)] got : [%s]\n", strstr(qwerty, question));
	printf("expected [] got : [%s]\n", strstr(empty, empty));
	printf("expected [Azerty or qwerty my friend ? :)] got : [%s]\n", strstr(question, empty));
	printf("expected [ or qwerty my friend ? :)] got : [%s]\n", strstr(question, space));
	printf("expected [(null)] got : [%s]\n", strstr(question, slash));
	printf("expected [:)] got : [%s]\n", strstr(question, smile));
	printf("expected [(null)] got : [%s]\n", strstr(smile, question));
}

//make test && LD_PRELOAD=./libasm.so ./a.out

int main(void)
{
	 strlen_tests();
	 strchr_tests();
	 memset_tests();
	 memcpy_tests();
	 strcmp_tests();
	 strncmp_tests();
	 strcasecmp_tests();
	 rindex_tests();
	 strcspn_tests();
	memmove_tests();
	strstr_tests();
	strpbrk_tests();
}
