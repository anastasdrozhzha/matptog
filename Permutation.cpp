#include "Combi.h"
#include "Sale.h"
#include <algorithm>
#define NINF  ((short)0x8000)
namespace combi
{

permutation::permutation(short w)
{
    this->w = w;
    this->sset = new short[w];
    this->dart = new bool[w];
    this->reset();
};
void  permutation::reset()
{
    this->getfirst();
};
__int64  permutation::getfirst()
{
    this->np = 0;
    for (int i = 0; i < this->w; i++)
    {
        this->sset[i] = i; this->dart[i] = L;
    };
    return  (this->w > 0) ? this->np : -1;
};
__int64  permutation::getnext()   // 
{
    __int64 rc = -1;
    short maxm = NINF, idx = -1;
    for (int i = 0; i < this->w; i++)
    {
        if (i > 0 &&
            this->dart[i] == L &&
            this->sset[i] > this->sset[i - 1] &&
            maxm < this->sset[i])  maxm = this->sset[idx = i];
        if (i < (this->w - 1) &&
            this->dart[i] == R &&
            this->sset[i] > this->sset[i + 1] &&
            maxm < this->sset[i])  maxm = this->sset[idx = i];
    };
    if (idx >= 0)
    {
        std::swap(this->sset[idx],
            this->sset[idx + (this->dart[idx] == L ? -1 : 1)]);
        std::swap(this->dart[idx],
            this->dart[idx + (this->dart[idx] == L ? -1 : 1)]);
        for (int i = 0; i < this->w; i++)
            if (this->sset[i] > maxm) this->dart[i] = !this->dart[i];
        rc = ++this->np;
    }
    return rc;
};
short permutation::ntx(short i) { return  this->sset[i]; };
unsigned __int64 fact2(unsigned __int64 x) { return (x == 0) ? 1 : (x * fact2(x - 1)); };
unsigned __int64 permutation::count() const { return fact2(this->w); };
}