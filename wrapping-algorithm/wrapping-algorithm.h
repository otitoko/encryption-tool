#ifndef WRAPPING_ALGORITHM_H
#define WRAPPING_ALGORITHM_H

void wrap_algorithm_reverse(int *ascii,int shift, int lower_limit,int upper_limit){	
	int scale;
	
	if(*ascii - shift < lower_limit){
		scale = (*ascii - lower_limit)+1;	
		shift-=scale;
		*ascii = upper_limit;
		wrap_algorithm_reverse(ascii,shift,lower_limit,upper_limit);

	}
	else{
		*ascii -= shift;
	}
}
void wrap_algorithm(int *ascii, int shift, int lower_limit, int upper_limit){
	//ascii in question, how much it goes forward
	//check if ascii and shift goes past the limit: go to the limit(122) ? break
	//take into account how much shift is left
	//go to the beginning (97), take one away from shift because z=>a is 1
	//start again
	int scale;
	if (*ascii + shift > upper_limit){
		//either do the original ie. go to upper limit=>lower limit=>check again
		//or go to lower limit immediately=>check again
		scale = (upper_limit - *ascii)+1;	//get the length until the upper limit to take away from the shift
		shift-=scale;
		*ascii = lower_limit;
		wrap_algorithm(ascii,shift,lower_limit,upper_limit);
		
	}
	else{
	*ascii += shift;
	}
}

#endif // WRAPPING_ALGORITHM_H
