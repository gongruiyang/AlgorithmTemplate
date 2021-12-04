
double Sqrt(double target)
{
	double le = 0, ri = max(target, 1.0);
	while (ri - le > 1e-8)
	{
		double mid = (le + ri) / 2;
		if (mid * mid >= target)
			ri = mid;
		else
			le = mid;
	}
	return le;
}
