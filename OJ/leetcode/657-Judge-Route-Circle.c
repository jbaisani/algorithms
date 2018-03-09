bool judgeCircle(char* moves){
	int a[2] = {0};
	while(*moves != NULL){
		switch(*moves){
			case 'U':a[0]++;break;
			case 'D':a[0]--;break;
			case 'L':a[1]++;break;
			case 'R':a[1]--;break;
			default:break;
		}
        moves++;
	}

	if(a[0]==0&&a[1]==0)
		return true;
	else
		return false;
}

