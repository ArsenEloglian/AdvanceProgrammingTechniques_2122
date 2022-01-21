package com.example.theamazonsgame.shared;

import lombok.RequiredArgsConstructor;

@RequiredArgsConstructor
public enum BoardFieldEnum {
    A1("A","1"),
    A2("A","2"),
    A3("A","3"),
    A4("A","4"),
    A5("A","5"),
    B1("B","1"),
    B2("B","2"),
    B3("B","3"),
    B4("B","4"),
    B5("B","5"),
    C1("C","1"),
    C2("C","2"),
    C3("C","3"),
    C4("C","4"),
    C5("C","5"),
    D1("D","1"),
    D2("D","2"),
    D3("D","3"),
    D4("D","4"),
    D5("D","5"),
    E1("E","1"),
    E2("E","2"),
    E3("E","3"),
    E4("E","4"),
    E5("E","5");

    public final String firstValue;
    public final String secondValue;
}
