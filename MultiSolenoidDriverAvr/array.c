template <typename T>
class TArray{
	public:
		/*
		*	Constructor
		*/
		TArray(){
			// Untag by default
			for (int i=0; i<SIZE_OF_ARRAY; i++){
				_untag[i] = true;
				_maxValue[i] = 4294967295;
			}

		}

		/*
		*	Returns the element of given index.
		*/
		T get(int index){
			return _data[index];
		}

		/*
		*	Sets element at given index to passed value
		*	limited in size my _maxValue
		*/
		bool set(T data, int index){
			if (data > _maxValue[index]){
				_data[index] = _maxValue[index];
				return false;
			}
			_data[index] = data;
			return true; 
		}

		/*
		*	Sets the atribute to self tag after a given
		*	number of calls to the set method
		*/
		bool selfTagOnDiff(int index, int numOfCalls){
			_numOfCalls[index] = numOfCalls;
			return true;
		}

		/*
		*	Should be called with every call of set. 
		*	Tags the tag after certain number of calls.
		*/
		bool selfTagOnDiff(int index){
			static unsigned int numOfCalls[SIZE_OF_ARRAY];

			numOfCalls[index]++; // Increment counter

			if (numOfCalls[index] > _numOfCalls[index]){
				numOfCalls[index] = 0; // Reset counter
				tag(true, index);
			}

			return true;

		}

		/*
		*	Sets the tag for reporting
		*/
		bool tag(int index, bool tag){
			_tag[index] = tag;

			return true;
		}

		/*
		*	Returns the state of the tag
		*/
		bool tagged(int index){
			bool old = _tag[index];
			if (_untag[index])
				_tag[index] = false;
			return old;
		}

		/*
		*	Increments the data of given index by one
		*/
		bool increment(int index){
			_data[index]++;
			return true;
		}

		/*
		*	Decrements the data of given index by one
		*/
		bool decrement(int index){
			_data[index]--;
			return true;
		}

		/*
		*	Sets the maximum admissible value to be stored
		*/
		bool setMaxValue(T value, int index){
			_maxValue[index] = value;
			return true;
		}


	private:
		

};
