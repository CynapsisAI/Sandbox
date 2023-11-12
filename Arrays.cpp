
//I followed a youtube tutorial Lmao - Behrad 11-12 2023

template <typename T> 

class Array
{

private:

    //maximum dimension 
    unsigned cap;
    unsigned numEls;

    //a pointer to a pointer
    T **arr;

public:
   
    int size;

    Array();
    ~Array();

    void init(unsigned from =0);
    void expand();
    void add(const T &obj);
    int getsize();

    T& operator[](const int index);

};

template <typename T> 
Array<T>::Array(){
    this->cap =5;
    this->numEls =0;
    this->arr = new T*[this->cap];
    this->init();
}


template <typename T> 
Array<T>::~Array(){
    
}


template <typename T> 
void Array<T>::init(unsigned from =0){

    for (size_t i = from; i < this->cap; i++)
    {
        this->arr[i] = nullptr;
    }
    
}


//adder for two arrays 
template <typename T> 
void Array<T>::add(const T &obj){

    //if the number of elements is larger than the capacity of an array
    if(this->numEls >=this->cap)
        this->expand();


    this->arr[this->numEls++] = new T(obj);
}


//getter for size, returns the number of elements 
template <typename T> 
int Array<T>::getsize(){
    return this->numEls;
}

//Operator 
template <typename T> 
T& Array<T>::operator[]( const int index){
    if(index<0 || index>= this->numEls)
        throw "Index out of bounds";

    return *this->arr[index];
}

template <typename T> 
void Array<T>::expand(){
   
    this-> cap+=5;

    T **tmpArr = new T*[this->cap];

    for (size_t i = 0; i < this->numEls; i++)
    {
        tmpArr[i] = new T(*this->arr[i]);

    }

    for (size_t i = 0; i < this->numEls; i++)
    {

        delete this->arr[i];

    }
    delete this->arr;
    
    this->arr = tempArr;

    this->init(this->numEls);
    
}