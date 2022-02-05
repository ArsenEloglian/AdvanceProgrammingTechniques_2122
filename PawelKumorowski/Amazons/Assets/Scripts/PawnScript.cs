using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PawnScript : MonoBehaviour
{
    public GameObject possibleActionPrefab;
    [HideInInspector]
    public BoardScript boardScript;
    [HideInInspector]
    public List<Vector2Int> legalMoves;
    [HideInInspector]
    public bool player;
    [HideInInspector]
    public bool isBlocked;
    List<GameObject> actionsList;


    public void GenerateLegalMoves()
    {
        if (!isBlocked)
        {
            Vector2Int tempPos, pawnPos = boardScript.GetBoardPosition(transform.position);
            legalMoves = new List<Vector2Int>();
            tempPos = pawnPos;
            while (boardScript.IsActionLegal(new Vector2Int(++tempPos.x, tempPos.y)))
                legalMoves.Add(tempPos);

            tempPos = pawnPos;
            while (boardScript.IsActionLegal(new Vector2Int(--tempPos.x, tempPos.y)))
                legalMoves.Add(tempPos);

            tempPos = pawnPos;
            while (boardScript.IsActionLegal(new Vector2Int(tempPos.x, ++tempPos.y)))
                legalMoves.Add(tempPos);

            tempPos = pawnPos;
            while (boardScript.IsActionLegal(new Vector2Int(tempPos.x, --tempPos.y)))
                legalMoves.Add(tempPos);

            tempPos = pawnPos;
            while (boardScript.IsActionLegal(new Vector2Int(++tempPos.x, ++tempPos.y)))
                legalMoves.Add(tempPos);

            tempPos = pawnPos;
            while (boardScript.IsActionLegal(new Vector2Int(--tempPos.x, ++tempPos.y)))
                legalMoves.Add(tempPos);

            tempPos = pawnPos;
            while (boardScript.IsActionLegal(new Vector2Int(++tempPos.x, --tempPos.y)))
                legalMoves.Add(tempPos);

            tempPos = pawnPos;
            while (boardScript.IsActionLegal(new Vector2Int(--tempPos.x, --tempPos.y)))
                legalMoves.Add(tempPos);

            if (legalMoves.Count == 0)
                isBlocked = true;
        }
        else
        {
            legalMoves = new List<Vector2Int>();
        }
    }

    public void ShowLegalMoves()
    {
        actionsList = new List<GameObject>();
        foreach (Vector2Int field in legalMoves)
        {
            actionsList.Add(Instantiate(possibleActionPrefab, boardScript.GetScenePosition(field), Quaternion.identity));
        }
    }

    public void HideLegalMoves()
    {
        if(actionsList != null)
            foreach (GameObject legalMove in actionsList)
                Destroy(legalMove);
    }

    public void MovePawn(Vector2 newPosition)
    {
        transform.position = newPosition;
        HideLegalMoves();
        GenerateLegalMoves();
        ShowLegalMoves();
    }
}
