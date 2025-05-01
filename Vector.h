#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>
#include <cmath>

class Vector
{
private:
    double* data = nullptr;
    unsigned int sizeVec = 0;
public:
	//Эти не менять
	Vector(){}
	Vector(int n)
	{
        sizeVec = n;
        data = new double[sizeVec];
        for (unsigned int i = 0; i < sizeVec; i++)
            data[i] = 0.0;
	}
    double& operator[](int index)
    {
        return data[index];
    }
    double operator[](int index) const
    {
        return data[index];
    }
	//Эти не менять
    void obnulenie(int n)
    {
        sizeVec = n;
        data = new double[sizeVec];
        for (unsigned int i = 0; i < sizeVec; i++)
            data[i] = 0.0;
    }
    void print() const
    {
        for (int i = 0; i < sizeVec; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    //RULE OF THREE
    Vector(const Vector& copy)
    {
        sizeVec = copy.sizeVec;
        data = new double[sizeVec];
        for (unsigned int i = 0; i < sizeVec; i++)
            data[i] = copy.data[i];
    }
    Vector& operator=(const Vector& v)
    {
        if (&v != this) {
            delete[] data;
            sizeVec = v.sizeVec;
            data = new double[sizeVec];
            for (unsigned int i = 0; i < sizeVec; i++)
                data[i] = v.data[i];
        }
        return *this;
    }
    ~Vector()
    {
        delete[] data;
    }
};

#endif