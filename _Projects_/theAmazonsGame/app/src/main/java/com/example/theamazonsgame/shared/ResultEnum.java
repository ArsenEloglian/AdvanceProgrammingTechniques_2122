package com.example.theamazonsgame.shared;

import lombok.RequiredArgsConstructor;

@RequiredArgsConstructor
public enum ResultEnum {
    inProgress("inProgress"),
    ended("ended"),
    firstMove("firstMove"),
    secondMove("secondMove"),
    waitingForPlayer("waitingForPlayer"),
    aborted("aborted");

    public final String value;
}
