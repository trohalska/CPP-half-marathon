#pragma once
#include <iostream>

struct Wallet {
    int septims;
};

Wallet* createWallet(int sept);
Wallet* createWallets(int amount);
void destroyWallet(Wallet *wallet);
void destroyWallets(Wallet *wallets);
