#pragma one

#include "function.h"


int main (int argc, char* argv[])
{

	if (strcmp(argv[1], "-a") == 0) {

		// command 2 : a.exe -a heap-sort 50 -rand -time
		if (argc == 6) AlgorithmMode_2(argv);
		else {

			string copy_argv3 = argv[3];
			char find_txt[5] = ".txt";

			// command 1 : a.exe -a heap-sort input.txt -both
			if (strstr(copy_argv3.c_str(), find_txt) != NULL) AlgorithmMode_1(argv);

			// command 3 : a.exe -a heap-sort 700 -comp
			else AlgorithmMode_3(argv);

		}
	}
	else if (strcmp(argv[1], "-c") == 0)
	{
		// command 4 : a.exe -c heap-sort merge-sort input.txt
		if (argc == 5) CompareMode_4(argv);

		// command 5 : a.exe -c quick-sort merge-sort 1000 -nsorted
		else CompareMode_5(argv);
	}
	else {
		cout << "Input syntax error!\n";
	}

    return 0;
}