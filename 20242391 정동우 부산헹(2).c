//20242391 정동우
//2-1 ~ 2-4 부산헹(2) 했습니다.



#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define LEN_MIN 15
#define LEN_MAX 50
#define STM_MIN 0 
#define STM_MAX 5
#define PROB_MIN 10
#define PROB_MAX 90
#define AGGRO_MIN 0 
#define AGGRO_MAX 5

// 마동석 이동 방향
#define MOVE_LEFT 1
#define MOVE_STAY 0

// 좀비의 공격 대상
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2

// 마동석 행동
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2


int c, m, m1, z, c1, z2, z1, p, trl, citizen, zombie, mas, mas2, mds_move, aggro_c, aggro_c2, aggro_m, aggro_m2, mds_action, mds_action_pull;
aggro_m = 1;
aggro_c = 1;
int train_length(void);
int train_length(void) {
	while (1) {
		printf("train length (%d~%d)>>", LEN_MIN, LEN_MAX);
		scanf_s("%d", &trl);
		if (trl >= LEN_MIN && trl <= LEN_MAX) {
			break;
		}
	}

	return trl;
}

int percentile_probability(void);
int percentile_probability(void) {
	while (1) {
		printf("percentile probability 'p' (%d~%d)>>", PROB_MIN, PROB_MAX);
		scanf_s("%d", &p);
		if (p >= PROB_MIN && p <= PROB_MAX) {
			break;
		}
	}

	return p;
}

int madongseok_stamina(void);
int madongseok_stamina(void) {
	while (1) {
		printf("madongseok stamina(%d~%d)>>", STM_MIN, STM_MAX);
		scanf_s("%d", &mas);
		if (mas >= STM_MIN && mas <= STM_MAX) {
			break;
		}
	}
	return mas;
}

void train(int trl);

void train(int trl) {
	c = trl - 6;
	m = trl - 2;
	z = trl - 3;
	for (int i = 0; i < trl; i++) {
		printf("#");
	}
	printf("\n");
	for (int i = 0; i < trl; i++) {
		if (i == c) {
			printf("C");
		}
		else if (i == z) {
			printf("Z");
		}
		else if (i == m) {
			printf("M");
		}
		else if (i == 0) {
			printf("#");
		}
		else if (i == trl - 1) {
			printf("#");
		}
		else {
			printf(" ");
		}
	}
	printf("\n");
	for (int i = 0; i < trl; i++) {
		printf("#");
	}

}
void getrandom();

void getrandom() {
	srand((unsigned int)time(NULL));
	citizen = rand() % 100;
	zombie = rand() % 100;
	z2++;
	if (citizen < 100 - p) {
		c1 = c;
		c = c - 1;
		aggro_c2 = aggro_c;
		aggro_c++;
		if (aggro_c == 6) {
			aggro_c = AGGRO_MAX;
		}
	}
	else if (citizen > 100 - p) {
		c = c;
		c1 = c;
		aggro_c2 = aggro_c;
		aggro_c--;
		if (aggro_c == -1) {
			aggro_c = AGGRO_MIN;
		}
	}
	if (z2 % 2 == 0) {
		z1 = z;
		z = z;
	}
	else if (aggro_c == aggro_m) {
		z1 = z;
		z = z - 1;
	}
	else if (aggro_c > aggro_m) {
		if (z - 1 == c) {
			z1 = z;
			z = z;
		}
		else {
			z1 = z;
			z = z - 1;
		}
	}
	else if (aggro_m > aggro_c) {
		if (z + 1 == m) {
			z1 = z;
			z = z;
		}
		else {
			z1 = z;
			z = z + 1;
		}
	}

}

void train_situation();

void train_situation() {
	for (int i = 0; i < trl; i++) {
		printf("#");
	}
	printf("\n");

	for (int i = 0; i < trl; i++) {
		if (i == c) {
			printf("C");
		}
		else if (i == z) {
			printf("Z");
		}
		else if (i == m) {
			printf("M");
		}
		else if (i == 0 || i == trl - 1) {
			printf("#");
		}
		else {
			printf(" ");
		}
	}
	printf("\n");

	for (int i = 0; i < trl; i++) {
		printf("#");
	}
	printf("\n\n");
}

void getrandom2();

void getrandom2() {
	if (citizen < 100 - p) {
		printf("Citizen: %d -> %d (aggro:%d->%d)\n\n", c1, c, aggro_c2, aggro_c);
	}
	else if (citizen > 100 - p) {
		printf("Citizen: stay %d (aggro:%d->%d)\n\n", c, aggro_c2, aggro_c);
	}


	if (z2 % 2 == 0) {
		printf("Zombie: stay %d (cannot move)\n\n", z1);
	}
	else if (aggro_c == aggro_m) {
		printf("Zombie: %d -> %d\n\n", z1, z);
	}
	else if (aggro_c > aggro_m) {
		if (z - 1 == c) {
			printf("Zombie: stay %d \n\n", z1);
		}
		else {
			printf("Zombie: %d -> %d\n\n", z1, z);
		}
	}
	else if (aggro_m > aggro_c) {
		if (z + 1 == m) {
			printf("Zombie: stay %d \n\n", z1);
		}
		else {
			printf("Zombie: %d -> %d\n\n", z1, z);
		}

	}
}
void madongseok_move();

void madongseok_move() {
	while (1) {
		printf("madongseok move(%d:stay, %d:left)>>", MOVE_STAY, MOVE_LEFT);
		scanf_s("%d", &mds_move);
		if (mds_move == 0) {
			m1 = m;
			aggro_m2 = aggro_m;
			aggro_m--;
			if (aggro_m <= -1) {
				aggro_m = AGGRO_MIN;
			}
		}
		else if (mds_move == 1) {
			m1 = m;
			m = m - 1;
			aggro_m2 = aggro_m;
			aggro_m++;
			if (aggro_m >= 6) {
				aggro_m = AGGRO_MAX;
			}
		}
		if (mds_move == 0 || mds_move == 1) {
			break;
		}
	}
}
void madongseok_move_now();

void madongseok_move_now() {
	if (mds_move == 0) {
		printf("madongseok: stay %d (aggro: %d->%d)\n\n", m, aggro_m2, aggro_m);
	}
	else if (mds_move == 1) {
		printf("madongseok: %d->%d (aggro: %d->%d)\n\n", m1, m, aggro_m2, aggro_m);
	}
}

void citizen_action();

void citizen_action() {
	if (c == 1) {
		printf("YOU WIN!");
		exit(0);
	}
	else {
		printf("citizen does nothing.\n\n");
	}
}

void zombie_action();

void zombie_action() {
	if (z - 1 == c) {
		printf("GAME OVER! Citizen dead...");
		exit(0);
	}
	else if (z + 1 == m) {
		mas2 = mas;
		mas--;
		printf("zombie attacked madongseok (madongseok stamina %d->%d)\n\n", mas2, mas);
	}
	else if (z + 1 == m && z - 1 == c) {
		if (aggro_c > aggro_m) {
			printf("GAME OVER! Citizen dead...");
			exit(0);
		}
		else if (aggro_c < aggro_m) {
			mas2 = mas;
			mas--;
			printf("zombie attacked madongseok (aggro: %d vs %d madongseok stamina %d->%d)\n\n", aggro_c, aggro_m, mas2, mas);
		}
		else if (aggro_c == aggro_m) {
			mas2 = mas;
			mas--;
			printf("zombie attacked madongseok (aggro: %d vs %d madongseok stamina %d->%d)\n\n", aggro_c, aggro_m, mas2, mas);
		}
	}
	else {
		printf("zombie attacked nobody.\n\n");
	}
	if (mas == STM_MIN) {
		printf("GAME OVER! Madongseok dead...\n\n");
		exit(0);
	}
}

void madongseok_action();

void madongseok_action() {
	mds_action_pull = rand() % 100;
	if (m - 1 == z) {
		printf("madongseok action(0.rest, 1.provoke, 2. pull)>>");
		scanf_s("%d", &mds_action);
		if (mds_action == ACTION_REST) {
			aggro_m2 = aggro_m;
			aggro_m--;
			mas2 = mas;
			mas++;
			printf("madongseok rests...\n\n");
			printf("madongseok: 7 (aggro: %d -> %d, stamina: %d -> %d\n\n)", aggro_m2, aggro_m, mas2, mas);
		}
		else if (mds_action == ACTION_PROVOKE) {
			aggro_m2 = aggro_m;
			aggro_m = AGGRO_MAX;
			printf("madongseok provoked zombie...\n\n");
			printf("madongseok: 7 (aggro: %d -> %d, stamina: %d\n\n)", aggro_m2, aggro_m, mas);
		}
		else if (mds_action == ACTION_PULL) {
			aggro_m2 = aggro_m;
			aggro_m = aggro_m + 2;
			mas2 = mas;
			mas--;
			if (100 - p > mds_action_pull) {
				if (z2 % 2 == 0) {
					z2++;
				}
				else {
					z2 = z2 + 2;
				}
				printf("madongseok pulled zombie... Next turn, it can't move\n\n");
				printf("madongseok: 7 (aggro: %d -> %d, stamina: %d -> %d)\n\n", aggro_m2, aggro_m, mas2, mas);
			}
			else if (100 - p < mds_action_pull) {
				printf("madongseok failed to pull zombie\n\n");
				printf("madongseok: 7 (aggro: %d -> %d, stamina: %d -> %d)\n\n", aggro_m2, aggro_m, mas2, mas);
			}
		}
	}
	else {
		if (mds_action == ACTION_REST) {
			aggro_m2 = aggro_m;
			aggro_m--;
			mas2 = mas;
			mas++;
			printf("madongseok rests...\n\n");
			printf("madongseok: 7 (aggro: %d -> %d, stamina: %d -> %d\n\n)", aggro_m2, aggro_m, mas2, mas);
		}
		else if (mds_action == ACTION_PROVOKE) {
			aggro_m2 = aggro_m;
			aggro_m = AGGRO_MAX;
			printf("madongseok provoked zombie...\n\n");
			printf("madongseok: 7 (aggro: %d -> %d, stamina: %d\n\n)", aggro_m2, aggro_m, mas);

		}
	}
}



int main(void) {
	srand((unsigned int)time(NULL));
	int t, m, p, g;
	t = train_length();
	m = madongseok_stamina();
	p = percentile_probability();
	train(t);
	printf("\n\n");
	while (1) {
		getrandom();
		train_situation();
		getrandom2();
		madongseok_move();
		train_situation();
		madongseok_move_now();
		citizen_action();
		zombie_action();
		madongseok_action();
	}

	return 0;
}
