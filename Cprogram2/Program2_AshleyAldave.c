#include <stdio.h>

int scoring_combos(score){
//function that determines all possible combinations of scoring plays given user input
	for (int td_conv =0; td_conv <= score / 8; td_conv++) {
		for (int td_fg = 0; td_fg <= (score - 8 * td_conv) / 7; ++td_fg){
			for (int td = 0; td <= (score - 7 * td_conv) / 6; ++td){
				for (int fg = 0; fg <= (score - 6 * td_conv) / 3; ++fg) {
					for (int s = 0; s <= (score - 3 * td_conv) / 2; ++s){
						if (td_conv * 8 + td_fg * 7 + td * 6 + fg * 3 + s * 2 == score) {
							//for each for loop iteration all possible combinations of scoring plays is printed
							printf("%d TD + 2 pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_conv, td_fg, td, fg, s);
						}else {
							continue;
						}
					}
				}
			}
		}
	}
	return 0;
}

//main function, calls possible_scores function that determines all possible 
//combinations of scoring plays given user input, collects user input then runs function
int main() {
	int c = 2;
	
	//while loops only runs while value is greater than 1
	while(c > 1){
		int user_score;
		
		//asks user for integer, or score
		printf("Enter 0 or 1 to Stop\n");
		printf("Enter the NFL score: ");
		//reads and stores user input
		scanf("%d", &user_score);
		
		if (user_score <=1){
			//if score entered by user is less than 1, program ends
			break;
		} else {
			//if score is greater than one, integer entered by user is passed through possible_scores function
			//and determines all possible combinations of scoring plays based on what the user inputed
			scoring_combos(user_score);
		}
	}
	return 0;
}