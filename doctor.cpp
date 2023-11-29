#include "doctor.h"

Doctor::Doctor(int recovery, QObject *parent) : QObject{parent}
{
    recovery_ = recovery;
}

void Doctor::OnRecoveryButtonClicked() { emit MakeRecovery(recovery_); }
