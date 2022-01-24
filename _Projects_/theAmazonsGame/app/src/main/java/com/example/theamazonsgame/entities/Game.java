package com.example.theamazonsgame.entities;

import com.example.theamazonsgame.shared.ResultEnum;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.RequiredArgsConstructor;

@Data
@Builder
@RequiredArgsConstructor
@AllArgsConstructor
public class Game {

    private String id;
    private String player1;
    private String player2;
    private String date;
    private String code;
    private ResultEnum result;
    private Board board;

}
