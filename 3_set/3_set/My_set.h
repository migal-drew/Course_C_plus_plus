template <class T>
class My_set
{
	public:
		My_set();
		~My_set();

		int getSize() const;
		My_set minus(My_set s);

	private:
		T *pElem;
};

template <class T>
int My_set<T>::getSize() const
{
}