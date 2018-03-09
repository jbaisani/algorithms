int hammingDistance(int x, int y){
	int count = 0;
	int xorValue = x ^ y;
	while(xorValue){
		xorValue &= (xorValue - 1);
		count++;
	}
	return count;
}




