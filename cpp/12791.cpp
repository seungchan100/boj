#include <stdio.h>

int cnt[2020];
int sum[2020];
typedef struct _Data {
	char *str;
	_Data *next;
	_Data(char *nstr) {
		str = nstr;
		next = 0;
	}
	_Data() { next = 0; str = 0; }
} Data;
Data data[2020];

inline void add(int year, char *str) {
	cnt[year]++;
	Data *t = &data[year];
	while (t->next) t = t->next;
	t->next = new _Data(str);
}


inline void inputData() {
	add(1967, "DavidBowie");
	add(1969, "SpaceOddity");
	add(1970, "TheManWhoSoldTheWorld");
	add(1971, "HunkyDory");
	add(1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars");
	add(1973, "AladdinSane");
	add(1973, "PinUps");
	add(1974, "DiamondDogs");
	add(1975, "YoungAmericans");
	add(1976, "StationToStation");
	add(1977, "Low");
	add(1977, "Heroes");
	add(1979, "Lodger");
	add(1980, "ScaryMonstersAndSuperCreeps");
	add(1983, "LetsDance");
	add(1984, "Tonight");
	add(1987, "NeverLetMeDown");
	add(1993, "BlackTieWhiteNoise");
	add(1995, "1.Outside");
	add(1997, "Earthling");
	add(1999, "Hours");
	add(2002, "Heathen");
	add(2003, "Reality");
	add(2013, "TheNextDay");
	add(2016, "BlackStar");
}

inline void initSum() {
	for (register int i = 1; i < 2020; i++) {
		sum[i] += sum[i-1] + cnt[i];
	}
}

int main() {
	register int n, i, s, e;
	Data *t;
	inputData();
	initSum();
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &s, &e);
		printf("%d\n", sum[e] - sum[s-1]);
		for (i = s; i <= e; i++) {
			t = &data[i];
			for (t = data[i].next; t; t = t->next) {
				printf("%d %s\n", i, t->str);
			}
		}
	}
	return 0;
}
