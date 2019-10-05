#ifndef FFT_NOTIFIER_H
#define FFT_NOTIFIER_H

class FFTNotifier
{
    public:
        virtual void notify(const double *fftout, size_t size) = 0;
};

#endif

