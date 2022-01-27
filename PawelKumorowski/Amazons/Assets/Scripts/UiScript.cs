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
    public Button quickRestartBtn;
    public Sprite[] playerSprites;

    private void Start()
    {
        startBtn.onClick.AddListener(startGame);
        quickRestartBtn.onClick.AddListener(startGame);
        endScreen.SetActive(false);
    }

    private void startGame()
    {
        endScreen.SetActive(false);
        boardScript.SetUpBoard();
    }

    public void setWinner(bool player)
    {
        if (player)
            gameResultTxt.text = "PLAYER B WINS";
        else
            gameResultTxt.text = "PLAYER A WINS";

        endScreen.SetActive(true);
    }

    public void setRound(bool player)
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