using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BoardScript : MonoBehaviour
{
    enum Fields
    {
        Empty,
        PawnA,
        PawnB,
        Arrow
    }
    public List<GameObject> pawnPrefabs;
    public GameObject arrowPrefab;
    public List<Vector2Int> startCoords;
    public UiScript uiScript;
    public MouseScript mouseScript;
    GameObject[] pawns;
    List<GameObject> arrows;
    Fields[,] board;
    [HideInInspector]
    bool round;
    bool playerAHasMoves;
    bool playerBHasMoves;


    void Start()
    {
        SetUpBoard();
    }

    public void SetUpBoard()
    {
        if(pawns != null)
        {
            for (int i = 0; i < pawns.Length; i++)
            {
                pawns[i].GetComponent<PawnScript>().HideLegalMoves();
                Destroy(pawns[i]);
            }        
        }
        
        if(arrows != null)
        {
            for (int i = 0; i < arrows.Count; i++)
            {
                Destroy(arrows[i]);
            }
        }
        round = false;
        board = new Fields[10, 10];
        arrows = new List<GameObject>();
        pawns = new GameObject[8];
        for (int i = 0; i < 8; i++)
        {
            pawns[i] = Instantiate(i < 4 ? pawnPrefabs[0] : pawnPrefabs[1],
            GetScenePosition(startCoords[i]), Quaternion.identity);
            pawns[i].GetComponent<PawnScript>().boardScript = this;

            board[startCoords[i].x, startCoords[i].y] = i < 4 ? Fields.PawnA : Fields.PawnB;
        }

        mouseScript.Restart();
        uiScript.setRound(!round);

        GenerateAllLegalMoves();
    }

    void GenerateAllLegalMoves()
    {
        playerAHasMoves = playerBHasMoves = false;

        for (int i = 0; i < 8; i++)
        {
            PawnScript pawnScript = pawns[i].GetComponent<PawnScript>();
            pawnScript.GenerateLegalMoves();

            if (!pawnScript.isBlocked && i < 4)
                playerAHasMoves = true;
            else if (!pawnScript.isBlocked && i >= 4)
                playerBHasMoves = true;
        }

        if (!playerAHasMoves)
            uiScript.setWinner(true);
        else if (!playerBHasMoves)
            uiScript.setWinner(false);
    }

    public bool IsActionLegal(Vector2Int position)
    {
        if (position.x >= 0 && position.x < 10
        && position.y >= 0 && position.y < 10
        && board[position.x, position.y] == Fields.Empty)
            return true;

        return false;
    }

    public Vector2 GetScenePosition(Vector2 boardPos)
    {
        return new Vector2((int)(boardPos.x - 5) + 0.5f, (int)(boardPos.y - 5) + 0.5f);
    }

    public Vector2Int GetBoardPosition(Vector2 position)
    {
        return new Vector2Int((int)(position.x + 5), (int)(position.y + 5));
    }

    public void MovePawn(GameObject pawn, Vector2 destinationScenePos)
    {
        PawnScript pawnScript = pawn.GetComponent<PawnScript>();
        Vector2Int currentPos = GetBoardPosition(pawn.transform.position);
        Vector2Int destinationPos = GetBoardPosition(destinationScenePos);
        board[currentPos.x, currentPos.y] = Fields.Empty;
        board[destinationPos.x, destinationPos.y] = pawnScript.player ? Fields.PawnB : Fields.PawnA;
        pawnScript.MovePawn(destinationScenePos);
    }

    public void Shoot(GameObject pawn, Vector2 coords)
    {
        Vector2Int arrowPos = GetBoardPosition(coords);
        board[arrowPos.x, arrowPos.y] = Fields.Arrow;
        GameObject arrow = Instantiate(arrowPrefab, GetScenePosition(arrowPos), Quaternion.identity);
        arrows.Add(arrow);
        pawn.GetComponent<PawnScript>().HideLegalMoves();
        round = !round;

        GenerateAllLegalMoves();
        uiScript.setRound(!round);
    }

    public bool GetRound()
    {
        return round;
    }
}
