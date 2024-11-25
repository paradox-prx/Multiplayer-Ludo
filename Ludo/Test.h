#pragma once
#ifndef TEST_H
#define TEST_H

class Test {
public:
    void runTests();
private:
    void testPlayerMovement();
    void testDiceRoll();
    void testWinCondition();
    void testNetworkConnection();
    void testBotAI();
};

#endif // TEST_H
