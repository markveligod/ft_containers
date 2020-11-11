template<class T>
    class VecIterator
    {
        private:
            T *it_data;
        public:
		
            VecIterator() {this->it_data = NULL;}
            VecIterator(T *data) {this->it_data = data;}
            VecIterator(VecIterator<T> const &other) {*this = other;}
            ~VecIterator() {}
            VecIterator<T> &operator=(VecIterator<T> const &other)
            {
                this->it_data = other.it_data;
                return (*this);
            }

            T &operator*() {return(*this->it_data);}
            T &operator[](int i) {return (*(this->it_data + i));}

            VecIterator<T> operator++(int) 
            {
		        VecIterator<T> tmp(*this);
		        ++this->it_data;
		        return (tmp);
	        }
	
            VecIterator<T> &operator++() 
            {
		        ++this->it_data;
		        return (*this);
	        }

	        VecIterator<T> operator--(int) 
            {
		        VecIterator<T> tmp(*this);
		        --this->it_data;
		        return (tmp);
	        }

	        VecIterator<T> &operator--() 
            {
		        --this->it_data;
		        return (*this);
	        }
            
            VecIterator<T> &operator+=(int value) 
            {
		        this->it_data += value;
		        return (*this);
	        }

	        VecIterator<T> operator+(int value) const 
            {
		        VecIterator<T> tmp(*this);
		        return (tmp += value);
	        }

	        VecIterator<T> &operator-=(int value) 
            {
		        this->it_data -= value;
	        	return (*this);
	        }
	
            VecIterator<T> operator-(int value) const 
            {
		        VecIterator<T> temp(*this);
		        return (temp -= value);
	        }

			T *getData() const { return (this->it_data);}

	        bool operator==(VecIterator<T> const &other) const { return (this->it_data == other.it_data);}
	        bool operator!=(VecIterator<T> const &other) const { return (this->it_data != other.it_data);}

    };

    template<class T>
    class VecRevIterator
    {
        private:
            T *it_data;
        public:
            VecRevIterator() {this->it_data = NULL;}
            VecRevIterator(T *data) {this->it_data = data;}
            VecRevIterator(VecRevIterator<T> const &other) {*this = other;}
            ~VecRevIterator() {}
            VecRevIterator<T> &operator=(VecRevIterator<T> const &other)
            {
                this->it_data = other.it_data;
                return (*this);
            }

            T &operator*() {return(*this->it_data);}
            T &operator[](int i) {return (*(this->it_data + i));}

            VecRevIterator<T> operator++(int) 
            {
		        VecRevIterator<T> tmp(*this);
		        --this->it_data;
		        return (tmp);
	        }
	
            VecRevIterator<T> &operator++() 
            {
		        --this->it_data;
		        return (*this);
	        }

	        VecRevIterator<T> operator--(int) 
            {
		        VecRevIterator<T> tmp(*this);
		        ++this->it_data;
		        return (tmp);
	        }

	        VecRevIterator<T> &operator--() 
            {
		        ++this->it_data;
		        return (*this);
	        }
            
            VecRevIterator<T> &operator+=(int value) 
            {
		        this->it_data -= value;
		        return (*this);
	        }

	        VecRevIterator<T> operator+(int value) const 
            {
		        VecRevIterator<T> tmp(*this);
		        return (tmp -= value);
	        }

	        VecRevIterator<T> &operator-=(int value) 
            {
		        this->it_data += value;
	        	return (*this);
	        }
	
            VecRevIterator<T> operator-(int value) const 
            {
		        VecRevIterator<T> temp(*this);
		        return (temp += value);
	        }

	        bool operator==(VecRevIterator<T> const &other) const { return (this->it_data == other.it_data);}
	        bool operator!=(VecRevIterator<T> const &other) const { return (this->it_data != other.it_data);}
    };