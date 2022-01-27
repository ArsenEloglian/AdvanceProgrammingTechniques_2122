package com.example.theamazonsgame.entities;

import com.example.theamazonsgame.shared.FieldStateEnum;

import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.RequiredArgsConstructor;

@Data
@Builder
@RequiredArgsConstructor
@AllArgsConstructor
public class Board {
    FieldStateEnum A1;
    FieldStateEnum A2;
    FieldStateEnum A3;
    FieldStateEnum A4;
    FieldStateEnum A5;
    FieldStateEnum B1;
    FieldStateEnum B2;
    FieldStateEnum B3;
    FieldStateEnum B4;
    FieldStateEnum B5;
    FieldStateEnum C1;
    FieldStateEnum C2;
    FieldStateEnum C3;
    FieldStateEnum C4;
    FieldStateEnum C5;
    FieldStateEnum D1;
    FieldStateEnum D2;
    FieldStateEnum D3;
    FieldStateEnum D4;
    FieldStateEnum D5;
    FieldStateEnum E1;
    FieldStateEnum E2;
    FieldStateEnum E3;
    FieldStateEnum E4;
    FieldStateEnum E5;

    public static Board createNewBoard(){
        return Board.builder()
                .A1(FieldStateEnum.firstPlayerPawn)
                .A2(FieldStateEnum.empty)
                .A3(FieldStateEnum.empty)
                .A4(FieldStateEnum.empty)
                .A5(FieldStateEnum.secondPlayerPawn)
                .B1(FieldStateEnum.empty)
                .B2(FieldStateEnum.empty)
                .B3(FieldStateEnum.empty)
                .B4(FieldStateEnum.empty)
                .B5(FieldStateEnum.empty)
                .C1(FieldStateEnum.firstPlayerPawn)
                .C2(FieldStateEnum.empty)
                .C3(FieldStateEnum.empty)
                .C4(FieldStateEnum.empty)
                .C5(FieldStateEnum.secondPlayerPawn)
                .D1(FieldStateEnum.empty)
                .D2(FieldStateEnum.empty)
                .D3(FieldStateEnum.empty)
                .D4(FieldStateEnum.empty)
                .D5(FieldStateEnum.empty)
                .E1(FieldStateEnum.firstPlayerPawn)
                .E2(FieldStateEnum.empty)
                .E3(FieldStateEnum.empty)
                .E4(FieldStateEnum.empty)
                .E5(FieldStateEnum.secondPlayerPawn)
                .build();

    }
}
