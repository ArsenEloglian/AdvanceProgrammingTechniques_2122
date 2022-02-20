using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UiScript : MonoBehaviour
{
    public BoardScript boardScript;
    public Text gameResultTxt;
    public GameObject endScreen;
    public Image roundImg;
    public Button startBtn;
    public Button undoBtn;
    public Sprite[] playerSprites;

    private void Start()
    {
        startBtn.onClick.AddListener(StartGame);
        undoBtn.onClick.AddListener(UndoMove);
        endScreen.SetActive(false);
    }

    private void StartGame()
    {
        endScreen.SetActive(false);
        boardScript.SetUpBoard();
    }

    private void UndoMove()
    {
        boardScript.UndoMove();
    }

    public void SetWinner(bool player)
    {
        if (player)
            gameResultTxt.text = "PLAYER B WINS";
        else
            gameResultTxt.text = "PLAYER A WINS";

        endScreen.SetActive(true);
    }

    public void SetRound(bool player)
    {
        if (player)
        {
            roundImg.sprite = playerSprites[0];
        }
        else
        {
            roundImg.sprite = playerSprites[1];
        }
    }
}