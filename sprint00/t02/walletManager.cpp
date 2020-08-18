#include "walletManager.h"

Wallet* createWallet(int sept) {
    if (!sept)
        return NULL;
    Wallet* wallet = new Wallet();
    wallet->septims = sept;
    return wallet;
}

void destroyWallet(Wallet *wallet) {
    if (!wallet)
        return;
    delete wallet;
    wallet = NULL;
}

Wallet* createWallets(int amount) {
    return new Wallet[amount];
}

void destroyWallets(Wallet *wallets) {
    if (!wallets)
        return;
    delete wallets;
    wallets = NULL;
}