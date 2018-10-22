#define _CRT_SECURE_NO_WARNINGS 1
#include <windows.h>
#include <iostream>
#include <io.h>
#include <process.h>
#include <vector>
using namespace std;

CHAR question[] = "@_wmliang_";
BYTE RANDOM_PAD = 0;





SIZE_T read_line(CHAR *msg, SIZE_T len)
{
	SIZE_T count = 0;
	CHAR tmp;

	if (msg && len) {
		for (count = 0; count < len; count++) {
			if (_read(0, &tmp, 1) <= 0) {
				break;
			}

			if (tmp == '\n') {
				msg[count] = '\0';
				break;
			}
			// add character to our message
			msg[count] = tmp;
		}
	}

	return count;
}

SIZE_T read_num()
{
	CHAR buf[0x100] = { 0 };
	read_line(buf, sizeof(buf));
	return atoi(buf);
}

void usage() {
	printf("Usage:\n"
		" create\n"
		" list\n"
		" edit\n"
		" delete\n"
		" exit\n");
}






class Human
{
	CHAR name[9];
	SIZE_T age;
public:
	Human() {
	}
	~Human() {
	}
	Human(SIZE_T age, CONST CHAR* name) : age(age) {
		set_name(name);
	}
	Human(const Human &h2) : age(h2.age) {
		set_name(h2.name);
	}
	SIZE_T get_age() { return age; }
	CHAR* get_name() { return name; }
	void set_name(CONST CHAR* name_) { memcpy(name, name_, sizeof(name) - 1); } /* BUG: leak without NULL */
};

const CHAR* college_name[] = { "NTU", "NCTU", "NCU", "NTUST" };

class Teacher : public Human {
	CONST CHAR* college;
	CHAR subject[0x10];
public:
	Teacher() {
	}
	~Teacher() {
	}
	Teacher(Human h, SIZE_T college_id, CHAR* sub) : Human(h), college(college_name[college_id]) {
		set_subject(sub);
	}
	Teacher(const Teacher &t2) : Human(t2), college(t2.college) {
		set_subject((CHAR*)(t2).subject);
	}
	CONST CHAR* get_college() { return college; }
	CHAR* get_subject() { return subject; }
	void set_subject(CHAR* subject_) { memcpy(subject, subject_, sizeof(subject) - 1); }
};

const CHAR* engineer_title[] = { "Engineer", "Sr. Engineer", "Staff", "Sr. Staff", "Architect" };

class Engineer : public Human {
	CHAR* language;
	CONST CHAR* title;
	SIZE_T salary;
public:
	Engineer() {
	}
	~Engineer() {
		if (language) free(language);
	}
	Engineer(Human h, SIZE_T title_id, SIZE_T salary_, CHAR* lang) : Human(h), salary(salary_), title(engineer_title[title_id]), language(NULL) {
		set_language(lang);
	}
	Engineer(const Engineer &e2) : Human(e2), salary(e2.salary), title(e2.title), language(e2.language) {
		set_language((CHAR*)(e2).language);
	}
	SIZE_T get_salary() { return salary; }
	CONST CHAR* get_title() { return title; }
	CHAR* get_language() { return language; }
	void set_language(CHAR* lang_) {
		if (lang_ && strcmp(lang_, "")) {
			dup_language(lang_);
		}
	}
	void edit_language(CHAR* lang_) {
		if (lang_ && strcmp(lang_, "")) {
			if (language) {
				memcpy(language, lang_, 0x18 - 1);
			}
			else {
				dup_language(lang_);
			}
			return;
		}
		if (language) {
			free(language); /* BUG: UAF/double free */
		}
	}
	void dup_language(CHAR* lang_) {
		language = (CHAR*)malloc(0x200+RANDOM_PAD);
		memcpy(language, lang_, 0x18 - 1);
	}
};

class Doctor : public Human {
	SIZE_T sleep;
	CHAR hospital[0x10];
public:
	Doctor() {
	}
	~Doctor() {
	}
	Doctor(Human h, CHAR* hospital_, SIZE_T sleep_) : Human(h), sleep(sleep_) {
		set_hospital(hospital_);
	}
	Doctor(const Doctor &d2) : Human(d2), sleep(d2.sleep) {
		set_hospital((CHAR*)d2.hospital);
	}
	SIZE_T get_sleep() { return sleep; }
	CHAR* get_hospital() { return hospital; }
	void set_hospital(CHAR* hospital_) { memcpy(hospital, hospital_, sizeof(hospital) - 1); }
};


CONST CHAR* country_list[] = { "Taiwan", "Japan", "Korea" };
class Athlete : public Human {
	CONST CHAR* country;
	CHAR sport[0x10];
public:
	Athlete() {
	}
	~Athlete() {
	}
	Athlete(Human h, SIZE_T country_id, CHAR* sport) : Human(h), country(country_list[country_id]) {
		set_sport(sport);
	}
	Athlete(const Athlete &a2) : Human(a2), country(a2.country) {
		set_sport((CHAR*)(a2).sport);
	}
	CONST CHAR* get_country() { return country; }
	CHAR* get_sport() { return sport; }
	void set_sport(CHAR* sport_) { memcpy(sport, sport_, sizeof(sport) - 1); }
};


const CHAR* animal_kind[] = { "Happy Pig", "Lazy Pig", "Extraordinary Pig" };

class Pig : public Human {
	CONST CHAR* kind;
	SIZE_T weight;
	SIZE_T height;
public:
	Pig() {
	}
	~Pig() {
	}
	Pig(Human h, SIZE_T kind_id, SIZE_T weight_, SIZE_T height_) : Human(h), weight(weight_), height(height_), kind(animal_kind[kind_id]) {
	}
	Pig(const Pig &p2) : Human(p2), weight(p2.weight), height(p2.height), kind(p2.kind) {
	}
	SIZE_T get_weight() { return weight; }
	SIZE_T get_height() { return height; }
	CONST CHAR* get_kind() { return kind; }
};








vector<Teacher> t;
vector<Engineer> e;
vector<Doctor> d;
vector<Athlete> a;
vector<Pig> p;

SIZE_T which_kind() {
	printf("1) Teacher\n"
		"2) Engineer\n"
		"3) Doctor\n"
		"4) Athlete\n"
		"5) Pig\n"
		"What kind of human> ");
	return read_num();
}

#define CREATE__(list, id, msg) { \
	for (int i = 0; i < sizeof(list) / sizeof(CHAR*); i++) { \
		printf("%d) %s\n", i+1, list[i]); \
	} \
	printf(msg); \
	id = read_num() - 1; \
	SIZE_T limit = sizeof(list) / sizeof(CHAR*) - 1; \
	if (id > limit) id = limit; \
}


void create_() {
	CHAR buf[0x100] = { 0 };
	CHAR name[0x100] = { 0 };

	printf("age> ");
	SIZE_T age = read_num();
	printf("name> ");
	SIZE_T n = read_line(name, sizeof(name));
	Human h(age, name);

	switch (which_kind()) {
	case 1:
	{
		SIZE_T cid = 0;
		CREATE__(college_name, cid, "Which college> ")
		printf("What subject> ");
		read_line(buf, sizeof(buf));
		Teacher tt(h, cid, buf);
		t.push_back(tt);
	}
	break;

	case 2:
	{
		printf("What salary> ");
		SIZE_T s = read_num();
		SIZE_T tid = 0;
		CREATE__(engineer_title, tid, "Which title> ")
		printf("What language> ");
		read_line(buf, sizeof(buf));
		Engineer ee(h, tid, s, buf);
		e.push_back(ee);
	}
	break;

	case 3:
	{
		printf("How long> ");
		SIZE_T sleep = read_num();
		printf("Which hospital> ");
		read_line(buf, sizeof(buf));
		Doctor dd(h, buf, sleep);
		d.push_back(dd);
	}
	break;

	case 4:
	{
		SIZE_T cid = 0;
		CREATE__(country_list, cid, "Which country> ")
		printf("What sport> ");
		read_line(buf, sizeof(buf));
		Athlete aa(h, cid, buf);
		a.push_back(aa);
	}
	break;

	case 5:
	{
		printf("How heavy> ");
		SIZE_T weight = read_num();
		printf("How tall> ");
		SIZE_T height = read_num();

		SIZE_T kid = 0;
		CREATE__(animal_kind, kid, "Which kind> ")
		Pig pp(h, kid, weight, height);
		p.push_back(pp);
	}
	break;

	default:
	{
		printf("Error\n");
	}
	break;
	}
}

void list_() {
	for (SIZE_T i = 0; i < t.size(); ++i) {
		printf("Teacher %s(%d) worked at %s, he teaches %s\n", t[i].get_name(), t[i].get_age(), t[i].get_college(), t[i].get_subject());
	}
	for (SIZE_T i = 0; i < e.size(); ++i) {
		printf("Engineer %s(%d) was promoted as %s, his salary is around %d\n", e[i].get_name(), e[i].get_age(), e[i].get_title(), e[i].get_salary());
	}
	for (SIZE_T i = 0; i < d.size(); ++i) {
		printf("Doctor %s(%d) worked at %s hospital, he only sleeps %d everyday\n", d[i].get_name(), d[i].get_age(), d[i].get_hospital(), d[i].get_sleep());
	}
	for (SIZE_T i = 0; i < a.size(); ++i) {
		printf("Athlete %s(%d) is from %s and plays %s\n", a[i].get_name(), a[i].get_age(), a[i].get_country(), a[i].get_sport());
	}
	for (SIZE_T i = 0; i < p.size(); ++i) {
		printf("Pig %s(%d) is too fat, his BMI is around %d, he wants to become a %s\n", p[i].get_name(), p[i].get_age(), p[i].get_weight() / p[i].get_height() * p[i].get_height(), p[i].get_kind());
	}
}

#define DELETE__(type) { \
	for (SIZE_T i = 0; i < type.size(); ++i) { \
		if (!strcmp((type[i]).get_name(), buf)) { \
			type.erase(type.begin() + i); \
			printf("delete succeed\n"); \
			return; \
						} \
			} \
	printf("delete failed\n"); \
}

void delete_() {
	CHAR buf[0x100] = { 0 };
	SIZE_T kind = which_kind();
	printf("name> ");
	read_line(buf, sizeof(buf));
	switch (kind) {
	case 1:	DELETE__(t)	break;
	case 2: DELETE__(e) break;
	case 3: DELETE__(d) break;
	case 4: DELETE__(a) break;
	case 5: DELETE__(p) break;
	default: printf("Error\n"); break;
	}
}

#define EDIT__(v, msg, func) { \
	for (SIZE_T i = 0; i < v.size(); ++i) { \
		if (!strcmp(v[i].get_name(), buf)) { \
			printf(msg); \
			memset(buf, 0, sizeof(buf)); \
			read_line(buf, sizeof(buf)); \
			v[i].func(buf); \
			printf("edit succeed\n"); \
			return; \
		} \
	} \
	printf("edit failed\n"); \
}

void edit_() {
	CHAR buf[0x100] = { 0 };
	SIZE_T kind = which_kind();
	printf("name> ");
	read_line(buf, sizeof(buf));
	switch (kind) {
	case 1:	EDIT__(t, "What subject> ", set_subject) break;
	case 2:	EDIT__(e, "What language> ", edit_language) break;
	case 3:	EDIT__(d, "Which hospital> ", set_hospital) break;
	case 4:	EDIT__(a, "What sport> ", set_sport) break;
	case 5: printf("Sorry, you are not allowed\n"); break;
	default: printf("Error\n"); break;
	}
}


void motd() {
	SIZE_T i = strlen(question);
	printf(
		"__        ___           _                   _                    _\n"
		"\\ \\      / (_)_ __   __| | _____      _____| |    __ _ _ __   __| |\n"
		" \\ \\ /\\ / /| | '_ \\ / _` |/ _ \\ \\ /\\ / / __| |   / _` | '_ \\ / _` |\n"
		"  \\ V  V / | | | | | (_| | (_) \\ V  V /\\__ \\ |__| (_| | | | | (_| |\n"
		"   \\_/\\_/  |_|_| |_|\\__,_|\\___/ \\_/\\_/ |___/_____\\__,_|_| |_|\\__,_|\n\n");
}

BYTE random_byte() {
	HCRYPTPROV hCryptProv;
	BYTE pbData[1];

	if (!CryptAcquireContext(&hCryptProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT)) goto ERR;
	if (!CryptGenRandom(hCryptProv, sizeof(pbData), pbData)) goto ERR;
	if (!CryptReleaseContext(hCryptProv, 0)) goto ERR;
	return pbData[0];
ERR:
	printf("Error %x\n", GetLastError());
	return 0;
}
void init() {
	RANDOM_PAD = random_byte();
	RANDOM_PAD &= 0xF0;
}





int main(int argc, char* argv[])
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	CHAR cmd[0x180];
	motd();
	init();
	for (;;) {
		memset(cmd, 0, sizeof(cmd));
		printf(">> ");
		read_line(cmd, sizeof(cmd));
		if (!strcmp(cmd, "exit"))			break;
		else if (!strcmp(cmd, "create"))	create_();
		else if (!strcmp(cmd, "list"))		list_();
		else if (!strcmp(cmd, "edit"))		edit_();
		else if (!strcmp(cmd, "delete"))	delete_();
		else {
			usage();
			break;
		}
	}

	printf("Bye!\n");
	Sleep(100);
	return 0;
}

