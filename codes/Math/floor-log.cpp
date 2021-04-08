// Find floor(log(x))
// O(n)
int logv[MAXN];
void make_log(){
	logv[1] = 0;
	for(int i = 2; i <= MAXN; i++)
		logv[i] = logv[i/2]+1;
}