#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("inpu.txt", "r", stdin);
	freopen("out3.txt", "w", stdout);
#endif

	double grossincome;
	cin >> grossincome;
	double taxpayable = 0;
	if (grossincome <= 400000)
	{taxpayable = 0; goto end;}
	if (grossincome >= 0 and grossincome <= 150000)
	{taxpayable += 0;}
	if (grossincome >= 150001 and grossincome <= 300000)
	{
		double diff = grossincome - 150000;
		taxpayable += ( (diff * 2.5) / (double)(100.0));
	}
	if (grossincome >= 150001 and grossincome <= 800000 and grossincome >= 300001)
	{
		double diff1 = 150000;
		double diff2 = grossincome - 300000;
		taxpayable += ((diff1 * 2.5) / (double)(100.0));
		taxpayable += ((diff2 * 10) / (double)(100.0));


	}
	if (grossincome >= 150001 and grossincome <= 10000000 and grossincome >= 800001)
	{
		double diff1 = 150000;
		double diff2 = 500000;
		double diff3 = grossincome - 800000;

		taxpayable += ((diff1 * 2.5) / (double)(100.0));
		taxpayable += ((diff2 * 10) / (double)(100.0));
		taxpayable += ((diff3 * 25) / (double)(100.0));
	}
	if (grossincome >= 150001 and grossincome >= 10000001)
	{
		double diff1 = 150000;
		double diff2 = 500000;
		double diff3 = 9200000;
		double diff4 = grossincome - 10000000;

		taxpayable += ((diff1 * 2.5) / (double)(100.0));
		taxpayable += ((diff2 * 10) / (double)(100.0));
		taxpayable += ((diff3 * 25) / (double)(100.0));
		taxpayable += ((diff4 * 30) / (double)(100.0));
	}

end:;
	cout << taxpayable << "\n";

	return 0;

}