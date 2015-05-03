# Problem 1

(a)

	void LotteryMachine::initialize() {
		tokenCount = outcomeCount = 0;
		tokens = outcomes = NULL;
	}
	
	void LotteryMachine::release() {
		delete[] tokens;
		delete[] outcomes;
	}

(b)

	void LotteryMachine::initialize(int n, int t[]) {
		tokenCount = n;
		outcomeCount = 0;
		tokens = new int[n];
		for(int i = 0; i < n; ++i)
			tokens[i] = t[i];
		outcomes = NULL;
	}

(c)

	bool LotteryMachine::draw(int m) {
		if(m < 0 || m > tokenCount)
			return false;
		if(outcomes != NULL)
			delete[] outcomes;
		outcomeCount = m;
		outcomes = new int[outcomeCount];
		int* pop = new int[tokenCount];
		for(int i = 0; i < tokenCount; ++i)
			pop[i] = tokens[i];
		int size = tokenCount;
		int tmp;
		int it = 0;
		srand(time(0));
		do {
			tmp = rand()%(size--);
			outcomes[it++] = pop[tmp];
			pop[tmp] = pop[size];
		} while(it < m);
		delete[] pop;
		return true;
	}


(d)

	class LotteryMachine {
		private:
			int tokenCount;
			int* tokens;
			void initialize();
			void initialize(int n, int t[]);
			void release();
		public:
			int outcomeCount;
			int* outcomes;
			bool draw(int m);
			LotteryMachine() {
				initialize();
			}
			LotteryMachine(int n, int t[]) {
				initialize(n, t);
			}
			~LotteryMachine() {
				release();
			}
	};
