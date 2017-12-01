#include "Random1.h"
#include "simpleMC.h"
#include<cmath>
double simpleMonteCarlo(const double& Spot, 
				const double& r,
				const double& Vol,
				const double& Expiry, 
				const double& Strike, 
				const char& optionType,
				const unsigned int& NumberofPaths)
{
	double variance = Vol*Vol*Expiry;	
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5 * variance;
	
	double movedSpot = Spot * exp(r*Expiry + itoCorrection);
    double thisSpot, thisPayoff;
    double runningSum = 0;
	switch (optionType)
    {
        case 'c' :
			for (unsigned long i=0; i<NumberofPaths;i++)
			{
				double thisGaussian = GetOneGaussianByBoxMuller();
				thisSpot = movedSpot*exp(rootVariance*thisGaussian);
				thisPayoff = thisSpot - Strike;
				thisPayoff = thisPayoff >0 ? thisPayoff : 0;
				runningSum += thisPayoff;
			}
			break;
        case 'p' ://只需将上面的case中的thisPayoff = thisSpot - Strike改动
			for (unsigned long i=0; i<NumberofPaths;i++)
			{
				double thisGaussian = GetOneGaussianByBoxMuller();
				thisSpot = movedSpot*exp(rootVariance*thisGaussian);
				thisPayoff = Strike - thisSpot;
				thisPayoff = thisPayoff >0 ? thisPayoff : 0;
				runningSum += thisPayoff;
			}
			break;
    }
    double mean = runningSum / NumberofPaths;
    mean *= exp(-r*Expiry);
    return mean;
}