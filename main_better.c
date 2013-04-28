#include <string.h>
#include <stdio.h>

struct person {
	char* firstname;
	char* lastname;
	int age;
	struct person* next;
};

struct persons {
	struct person* start;
	struct person* last;
};

void persons_add(struct persons *list, struct person *p) {
	if(!list->start) {
		list->start = p;
		return;
	}

	list->last->next = p;
	list->last = p;
}

main() {
	struct persons personen;
	struct person firstname1 = {"firstname1", "lastname1", 11};
	struct person firstname2 = {"firstname2", "lastname2", 22};
	struct person firstname3 = {"firstname3", "lastname3", 33};

	persons_add(&personen, &firstname1);
	persons_add(&personen, &firstname2);
	persons_add(&personen, &firstname3);

	// now lets iterate
	struct person* tmpP = personen.start;

	do {
		printf("firstname: %s, lastname: %s, age: %d\n", tmpP->firstname, tmpP->lastname, tmpP->age);
	} while(tmpP = tmpP->next);

}