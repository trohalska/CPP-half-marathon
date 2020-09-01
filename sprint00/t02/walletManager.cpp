#include "walletManager.h"

Wallet* createWallet(int sept) {
    Wallet* wallet = new Wallet();
    wallet->septims = sept;
    return wallet;
}

void destroyWallet(Wallet *wallet) {
    delete wallet;
}

Wallet* createWallets(int amount) {
    return new Wallet[amount];
}

void destroyWallets(Wallet *wallets) {
    delete[] wallets;
}