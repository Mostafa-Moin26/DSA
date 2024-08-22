// Problem link ------>
https://www.naukri.com/code360/problems/-print-n-times_8380707?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube

// Solutions ------>
vector<string> printNTimes(int n) {
	// Write your code here.
	vector<string> a;

	if (n == 1) {
		a.push_back("Coding Ninjas ");
		return a;
	}

	a = printNTimes(n - 1);
	a.push_back("Coding Ninjas ");
}