/*$ begin $*/
void unobservable(int& p)
{
	int undetermined = 40;
	undetermined += 2;
	
	p = i;
}

void observable(
	volatile int& p)
{
	p = 42;
}

/*$ observable $*/
int main()
{
	volatile int visible = 21;
	visible *= 2;
/*$ invisible $*/
	int invisible = 44;
	invisible -= 2;
/*$ not_yet_visible $*/
	int not_yet_vis = 84;
	not_yet_vis /= 2;
/*$ function_calls $*/
	observable(visible);
	unobservable(invisible);
	unobservable(not_yet_vis);
/*$ IO $*/
	std::cout << visible;
	std::cout << not_yet_vis;	// now visible!
}