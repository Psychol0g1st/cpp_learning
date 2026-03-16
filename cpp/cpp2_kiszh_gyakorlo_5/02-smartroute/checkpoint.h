#ifndef CHECKPOINT_H
#define CHECKPOINT_H

class Checkpoint
{
    double distanceKm;
    int durationMin;
public:
    Checkpoint();
    Checkpoint(double distanceKm,
               int durationMin);

    double getDistanceKm() const;
    int getDurationMin() const;

    void print() const;
};

#endif // CHECKPOINT_H
