#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>
#include <cmath>

class Vector
{
private:
    double* data = nullptr;
    int sizeVec = 0;
public:
	//Эти не менять
	Vector(){}
	Vector(int n)
	{
        sizeVec = n;
        data = new double[sizeVec];
        for (int i = 0; i < sizeVec; i++)
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
        for (int i = 0; i < sizeVec; i++)
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
    void clear()
    {
        delete[] data;
        data = nullptr;
        sizeVec = 0;
    }
    void resize(int count)
    {
        if (count == 0) { this->clear(); }
        else if (count == sizeVec) {}
        else
        {
            double* dop = new double[count];
            int min = std::min(sizeVec, count);
            for (int i = 0; i < min; i++)
            {
                dop[i] = data[i];
            }
            delete[] data;
            sizeVec = count;
            data = dop;
            for (int i = min; i < sizeVec; i++)
            {
                data[i] = 0.0;
            }
        }
    }
    void SortOfResize(int count)
    {
        if (count == 0) { this->clear(); }
        else if (count == sizeVec) {}
        else
        {
            delete[] data;
            sizeVec = count;
            data = new double[count];
        }
    }
    //RULE OF THREE
    Vector(const Vector& copy)
    {
        sizeVec = copy.sizeVec;
        data = new double[sizeVec];
        for (int i = 0; i < sizeVec; i++)
            data[i] = copy.data[i];
    }
    Vector& operator=(const Vector& v)
    {
        if (&v != this) {
            delete[] data;
            sizeVec = v.sizeVec;
            data = new double[sizeVec];
            for (int i = 0; i < sizeVec; i++)
                data[i] = v.data[i];
        }
        return *this;
    }
    ~Vector()
    {
        delete[] data;
    }
    void insert(int pos, double dou)
    {
        if (pos <= sizeVec)
        {
            this->resize(sizeVec+1);
            for (int i = sizeVec - 1; i > pos; i--)
                data[i] = data[i - 1];
            data[pos] = dou;
        }
        else
        {
            std::cout << "Error#Insert: Out-of-bounds" << "\n";
        }
    }
};

#endif