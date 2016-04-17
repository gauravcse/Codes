#include <assert.h>
#include <ctype.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static const size_t SIZE_LIMIT 	= (size_t)(-2);
static const size_t NOT_FOUND   = (size_t)(-1);
static const int 	HEAD = 0;
static const int 	BEGIN = 1;

static const char* MAIN_MENU[] = 
{"MENU", "=====","1. Insert","2. Delete","3. Find","4. Sort","5. Print","6. Quit"};

enum{FALSE,TRUE};

typedef int (*cmp_func)(double a, double b);

typedef struct AList_WS {
	size_t 	current_size_limit;
	size_t 	current_size;

	int* 	usage_data;
	size_t* next_data_addrs;
	double*	data;	
} AList_WS;

AList_WS* new_list();/**/
AList_WS* new_list_size(size_t initial_size);/**/
AList_WS* new_list_data(double data);/**/
AList_WS* new_list_mult_data(int data_count, ...);/**/

void 	increase_size(AList_WS* list);/**/
void 	increase_size_to(AList_WS* list, size_t new_size); /**/

void 	insert_head(AList_WS* list, double data);/**/
void 	insert_tail(AList_WS* list, double data);/**/
void 	insert_next(AList_WS* list, size_t pos, double data);/**/
void 	insert_prev(AList_WS* list, size_t pos, double data);/**/
void	insert_at_loc(AList_WS* list, size_t prev, size_t next, double data);/**/

void 	delete_head(AList_WS* list);/**/
void 	delete_tail(AList_WS* list);/**/
void 	delete_data(AList_WS* list, double data);/**/
void 	delete_data_at(AList_WS* list, size_t pos);/**/
void 	delete_data_loc(AList_WS* list, size_t pos);/**/

void 	swap(AList_WS* list, size_t a, size_t b);/**/
void	sort(AList_WS* list, cmp_func func);/**/
int 	is_sorted(AList_WS* list, cmp_func func);/**/
void 	insert_sorted(AList_WS* list, double data, cmp_func);/**/

int 	is_empty(AList_WS* list);/**/
size_t 	find(AList_WS* list, double data);/**/
double	at(AList_WS* list,size_t pos);/**/

size_t inter_pos(AList_WS* list, size_t pos);/**/

size_t 	get_prev(AList_WS* list, size_t data);/**/
size_t 	get_next(AList_WS* list, size_t data);/**/

double 	list_front(AList_WS* list);
double  list_back(AList_WS* list);

size_t 	list_begin(AList_WS* list);/**/
size_t 	list_end(AList_WS* list);/**/

size_t find_empty_location(AList_WS* list); /**/
size_t get_new_size(size_t arg);/**/

int ascending(double a, double b);/**/
int descending(double a, double b);/**/

void print_list(AList_WS* list);/**/

void init_menu(AList_WS* list);/**/
void init_menu_insert(AList_WS* list);/**/
void init_menu_delete(AList_WS* list);/**/
void init_menu_sort(AList_WS* list);/**/

int main() {

	AList_WS* list = new_list();
	init_menu(list);

	return 0;
}

AList_WS* new_list() {
	return new_list_size(BEGIN);
}

AList_WS* new_list_size(size_t initial_size) {

	AList_WS* new_list = (AList_WS*)(malloc(sizeof(AList_WS)));
	assert(new_list != NULL /* ** OUT OF MEMORY ** */);

	size_t safe_size = get_new_size(initial_size);
	increase_size_to(new_list, safe_size);

	new_list->current_size = 1;

	return new_list;
}

AList_WS* new_list_data(double data) {
	AList_WS* new_list = new_list_size(1);
	insert_head(new_list, data);
	return new_list;
}

AList_WS* new_list_mult_data(int data_count, ...) {

	AList_WS* new_list = new_list_size((size_t)data_count);
	assert(new_list != NULL /* ** OUT OF MEMORY ** */);

	va_list data;
	va_start (data, data_count);          
  	for(int i=0;i<data_count;++i) {
  		double temp = va_arg(data, double);
  		insert_tail(new_list, temp);
  	}     
  	va_end(data);

  	return new_list;
}

void insert_head(AList_WS* list, double data) {
	insert_at_loc(list, get_prev(list, list_begin(list)), list_begin(list), data);
}

void insert_tail(AList_WS* list, double data) {
	insert_at_loc(list, list_end(list), get_next(list, list_end(list)), data);
}

void insert_next(AList_WS* list, size_t pos, double data) {
	insert_at_loc(list, inter_pos(list,pos), get_next(list,inter_pos(list,pos)), data);
}

void insert_prev(AList_WS* list, size_t pos, double data) {
	insert_at_loc(list, get_prev(list,inter_pos(list,pos)), inter_pos(list,pos), data);
}

void insert_at_loc(AList_WS* list, size_t prev, size_t next, double data) {
	if (list->current_size_limit == list->current_size)
		increase_size(list);

	size_t empty_cell = find_empty_location(list);
	list->data[empty_cell] = data;
	list->usage_data[empty_cell] = TRUE;

	list->next_data_addrs[empty_cell] = list->next_data_addrs[prev];
	list->next_data_addrs[prev] = empty_cell;

	list->current_size += 1;
}

void delete_head(AList_WS* list) {
	if (is_empty(list)) return;
	delete_data_loc(list, list_begin(list));
}

void delete_tail(AList_WS* list) {
	delete_data_loc(list, list_end(list));
}

void delete_data(AList_WS* list, double data) {
	size_t pos = find(list,data);
	assert(pos != NOT_FOUND /* ** DATA NOT FOUND ** */);
	delete_data_loc(list,pos);
}

void delete_data_at(AList_WS* list, size_t pos) {
	assert(pos < list->current_size /* ** INDEX OUT OF BOUNDS ** */);
	delete_data_loc(list, inter_pos(list,pos));
}

void delete_data_loc(AList_WS* list, size_t pos) {

	assert(pos > 0 && pos <= list->current_size_limit /* ** INDEX OUT OF BOUNDS ** */);

	size_t prev_pos = HEAD;
	while (list->next_data_addrs[prev_pos] != pos)
		prev_pos = list->next_data_addrs[prev_pos];

	list->next_data_addrs[prev_pos] = list->next_data_addrs[pos];

	list->usage_data[pos] = 0;
	list->next_data_addrs[pos] = 0;
	list->data[pos] = 0;

	if(list->current_size) list->current_size -= 1;
}

void swap(AList_WS* list, size_t a, size_t b) {
	double temp = list->data[a];
	list->data[a] = list->data[b];
	list->data[b] = temp;
}


void sort(AList_WS* list, cmp_func func) {
	for (size_t i = 0; i < list->current_size - 1; ++i) {
		for (size_t j = 0; j < list->current_size - 2; ++j) {
			if (!func(at(list, j), at(list, j+1))) {
				size_t x = inter_pos(list, j);
				size_t y = inter_pos(list, j+1);
				swap(list, x, y);
			}
		}
	}
}

int is_sorted(AList_WS* list, cmp_func func) {

	if (list->current_size <= 1) return TRUE;

	size_t pos = list->next_data_addrs[HEAD];
	for (int i = BEGIN; i < list->current_size - 1; ++i) {
		double a = list->data[pos];
		double b = list->data[list->next_data_addrs[pos]];
		if (func(a,b) != TRUE)
			return FALSE;
		pos = list->next_data_addrs[pos];
	}

	return TRUE;
}

void insert_sorted(AList_WS* list, double data, cmp_func func) {
	assert(is_sorted(list,func) && "** UNABLE TO INSERT DATA SORTED WATY IN AN UNSORTED LIST **");

	size_t pos = list->next_data_addrs[HEAD];
	for (int i = 0; i < list->current_size; ++i) {
		double a = list->data[pos];
		double b = data;
		if (!func(a,b)) {
			insert_at_loc(list, get_prev(list,pos), pos, data);
			return;
		}
			
		pos = list->next_data_addrs[pos];
	}

}

void increase_size(AList_WS* list) {
	assert(list->current_size_limit < SIZE_LIMIT /* **  SIZE LIMIT REACHED ** */);
	increase_size_to(list, get_new_size(list->current_size_limit));
}

void increase_size_to(AList_WS* list, size_t size) {
	assert(size > list->current_size_limit /* **  UNABLE TO DECREASE SIZE ***/);

	list->usage_data = (int*)(realloc(list->usage_data,size * sizeof(int)));
	assert(list->usage_data != NULL /* ** OUT OF MEMORY ** */);
	memset(list->usage_data + list->current_size_limit, 0, (size - list->current_size_limit - 1)*sizeof(int));

	list->next_data_addrs = (size_t*)(realloc(list->next_data_addrs,size * sizeof(size_t)));
	assert(list->next_data_addrs != NULL /* ** OUT OF MEMORY ** */);
	memset(list->next_data_addrs+ list->current_size_limit, 0, (size - list->current_size_limit - 1)*sizeof(size_t));
	
	list->data = (double*)(realloc(list->data, size * sizeof(double)));
	assert(list->data != NULL /* ** OUT OF MEMORY ** */);
	memset(list->data + list->current_size_limit, 0, (size - list->current_size_limit - 1)*sizeof(double));

	list->current_size_limit = size;
}

int is_empty(AList_WS* list) {
	return (list->current_size == 0);
}

size_t find(AList_WS* list, double data) {
	size_t pos = list->next_data_addrs[HEAD];
	for (size_t i = 0; i < list->current_size; ++i) {
		if (list->data[pos] == data)
			return pos;
		pos = list->next_data_addrs[pos];
	}

	return NOT_FOUND;
}

size_t inter_pos(AList_WS* list, size_t pos) {
	assert(pos <= list->current_size);

	size_t internal_pos = list->next_data_addrs[HEAD];
	for (size_t i = 0; i < pos; ++i)
		internal_pos = list->next_data_addrs[internal_pos];
	return internal_pos;
}

double	at(AList_WS* list,size_t pos) {
	assert(pos <= list->current_size_limit /* ** INDEX OUT OF BOUNDS ** */);

	size_t res_pos = list->next_data_addrs[HEAD];
	for (size_t i = 0; i < pos; ++i)
		res_pos = list->next_data_addrs[res_pos];
	return list->data[res_pos];
}

size_t 	get_prev(AList_WS* list, size_t pos) {
	assert(pos <= list->current_size_limit /* ** INDEX OUT OF BOUNDS ** */);

	size_t prev_pos = HEAD;
	while (list->next_data_addrs[prev_pos] != pos) {

		prev_pos = list->next_data_addrs[prev_pos];
	}
	return prev_pos;
}

size_t get_next(AList_WS* list, size_t pos) {
	assert(pos <= list->current_size_limit /* ** INDEX OUT OF BOUNDS ** */);
	return list->next_data_addrs[pos];
}

size_t list_begin(AList_WS* list) {
	return (list->next_data_addrs[HEAD]);
}

size_t list_end(AList_WS* list) {
	size_t res = list->next_data_addrs[HEAD];
	while (list->next_data_addrs[res] != 0)
		res = list->next_data_addrs[res];
	return res;
}

size_t find_empty_location(AList_WS* list) {
	for (size_t i = BEGIN; i < list->current_size_limit; ++i) {
		if (list->usage_data[i] == FALSE)
			return i;
	}

	return NOT_FOUND;
}

size_t get_new_size(size_t arg) {
	size_t new_size = 1;
	if (arg > SIZE_LIMIT / 2) 
		new_size = SIZE_LIMIT;
	else
		while (new_size <= (arg))
			new_size *= 2;
	return new_size;
}

int ascending(double a, double b) {
	return a <= b;
}

int descending(double a, double b) {
	return ascending(b,a);
}

void print_list(AList_WS* list) {
	size_t pos = HEAD;
	for (size_t i = 1; i < list->current_size; ++i) {
		pos = list->next_data_addrs[pos];
		printf("%g\t", list->data[pos]);
		if ((i % 15) == 0) printf("\n");
	}

	printf("\n");
}

void init_menu(AList_WS* list) {

	for (int i = 0; i < 8; ++i)
		printf("%s\n", MAIN_MENU[i]);

	printf("\vPLease enter option: ");

	char* input = (char*)(malloc(100));
	memset(input, '-', 100);
	scanf("%s", input);
	char ch = input[0];

	if (isdigit(input[0]) && isdigit(input[1]))
		ch = 'X';


	switch(ch) {

	case '1':
	case 'I':
	case 'i':
		init_menu_insert(list);
		init_menu(list);
		break;

	case '2':
	case 'D':
	case 'd':
		init_menu_delete(list);
		init_menu(list);
		break;

	case '3':
	case 'F':
	case 'f':
	{
		printf("Please enter the valur you want to find: ");
		double data;
		scanf("%lf", &data);
		size_t pos = find(list,data);
		if (pos == NOT_FOUND)
			printf("DATA NOT FOUND\n");
		else 
			printf("%g is found in position %lu", data, pos);
		init_menu(list);
		break;
	}	

	case '4':
	case 'S':
	case 's':
		init_menu_sort(list);
		init_menu(list);
		break;

	case '5':
	case 'P':
	case 'p':
		print_list(list);
		init_menu(list);
		break;

	case '6':
	case 'Q':
	case 'q':
		printf("Quitting Program");
		break;

	default:
		printf("Please enter a valid choice.\n\n");
		init_menu(list);
		break;
	}
}


void init_menu_insert(AList_WS* list) {
	for (int i = 0; i < 3; ++i)
		printf("%s\n", MAIN_MENU[i]);

	printf("\ta. Insert at Head\n");
	printf("\tb. Insert at Tail\n");
	printf("\tc. Insert at position Next to an index\n");
	printf("\td. Insert at position Prev to an index\n");
	printf("\te. Go Back\n");

	for (int i = 3; i < 8; ++i)
		printf("%s\n", MAIN_MENU[i]);

	printf("\vPLease enter option: ");

	char* input = (char*)(malloc(100));
	memset(input, '-', 100);
	scanf("%s", input);
	char ch = input[0];

	if (isdigit(input[0]) && isdigit(input[1]))
		ch = 'X';

	switch (ch) {

	case '1':
	case 'a':
	case 'H':
	{
		printf("Please enter the value you want to insert: ");
		double data;
		scanf("%lf", &data);
		insert_head(list, data);
		break;
	}

	case '2':
	case 'b':
	case 'T':
	{
		printf("Please enter the value you want to insert: ");
		double data;
		scanf("%lf", &data);
		insert_tail(list, data);
		break;
	}

	case '3':
	case 'c':
	case 'N':
	{
		printf("Please enter the value you want to insert: ");
		double data;
		scanf("%lf", &data);
		printf("Please enter the position");
		size_t pos;
		scanf("%lu", pos);
		insert_next(list,pos,data);
		break;
	}

	case '4':
	case 'd':
	case 'P':
	{
		printf("Please enter the value you want to insert: ");
		double data;
		scanf("%lf", &data);
		printf("Please enter the position");
		size_t pos;
		scanf("%lu", pos);
		insert_prev(list,pos,data);
		break;
	}

	case '5':
	case 'e':
	case 'B':
		break;

	default:
		printf("Please enter a valid choice.\n\n");
		init_menu_insert(list);
	}
}

void init_menu_delete(AList_WS* list) {
	for (int i = 0; i < 4; ++i)
		printf("%s\n", MAIN_MENU[i]);

	printf("\ta. Delete data at Head\n");
	printf("\tb. Delete data at Tail\n");
	printf("\tc. Delete data at an Index\n");
	printf("\td. Delete first occurrence of a given data\n");
	printf("\te. Delete first occurrence of a given data\n");
	printf("\tf. Go Back\n");

	for (int i = 4; i < 8; ++i)
		printf("%s\n", MAIN_MENU[i]);

	printf("\vPLease enter option: ");

	char* input = (char*)(malloc(100));
	memset(input, '-', 100);
	scanf("%s", input);
	char ch = input[0];

	if (isdigit(input[0]) && isdigit(input[1]))
		ch = 'X';

	switch (ch) {

	case '1':
	case 'a':
	case 'H':
	{
		delete_head(list);
		break;
	}

	case '2':
	case 'b':
	case 'T':
	{
		delete_tail(list);
		break;
	}

	case '3':
	case 'c':
	case 'I':
	{
		printf("Please enter the index");
		size_t pos;
		scanf("%lu", pos);
		delete_data_at(list, pos);
		break;
	}

	case '4':
	case 'd':
	case 'D':
	{
		printf("Please enter the value you want to delete: ");
		double data;
		scanf("%lf", &data);
		delete_data(list, data);
		break;
	}

	case '5':
	case 'e':
	case 'A':
	{
		printf("Please enter the value you want to delete: ");
		double data;
		scanf("%lf", &data);

		do {
			delete_data(list, data);
		}while (find(list,data) != NOT_FOUND);
		break;
	}

	case '6':
	case 'f':
	case 'B':
		break;

	default:
		printf("Please enter a valid choice.\n\n");
		init_menu_insert(list);
	}
}

void init_menu_sort(AList_WS* list) {
	for (int i = 0; i < 5; ++i)
		printf("%s\n", MAIN_MENU[i]);

	printf("\ta. Ascending\n");
	printf("\tb. Descendingl\n");
	printf("\tf. Go Back\n");

	for (int i = 5; i < 8; ++i)
		printf("%s\n", MAIN_MENU[i]);

	printf("\vPLease enter option: ");

	char* input = (char*)(malloc(100));
	memset(input, '-', 100);
	scanf("%s", input);
	char ch = input[0];

	if (isdigit(input[0]) && isdigit(input[1]))
		ch = 'X';

	switch (ch) {

	case '1':
	case 'A':
	case 'a':
		sort(list, ascending);

	case '2':
	case 'b':
	case 'D':
		sort(list, descending);

	case '3':
	case 'c':
	case 'B':
		break;

	default:
		printf("Please enter a valid choice.\n\n");
		init_menu_sort(list);
	}
}
