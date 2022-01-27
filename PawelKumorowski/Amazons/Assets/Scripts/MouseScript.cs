using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MouseScript : MonoBehaviour
{
    public BoardScript boardScript;
    GameObject previousPawn;
    PawnScript pawnScript;
    bool hasMoved;

    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            Vector3 mousePos = Camera.main.ScreenToWorldPoint(Input.mousePosition);
            Vector2 mousePos2D = new Vector2(mousePos.x, mousePos.y);

            RaycastHit2D hit = Physics2D.Raycast(mousePos2D, Vector2.zero);
            if (hit.collider != null)
            {
                if (!hasMoved)
                {
                    if (boardScript.GetRound() && hit.collider.gameObject.tag == "PlayerB"
                    || !boardScript.GetRound() && hit.collider.gameObject.tag == "PlayerA")
                    {
                        if (previousPawn != null)
                            pawnScript.HideLegalMoves();

                        previousPawn = hit.collider.gameObject;
                        pawnScript = previousPawn.GetComponent<PawnScript>();

                        if (!pawnScript.isBlocked)
                            pawnScript.ShowLegalMoves();
                    }
                    else if (hit.collider.gameObject.tag == "LegalField")
                    {
                        boardScript.MovePawn(previousPawn, hit.collider.gameObject.transform.position);
                        hasMoved = true;
                    }
                }
                else
                {
                    if (hit.collider.gameObject.tag == "LegalField")
                    {
                        boardScript.Shoot(previousPawn, hit.collider.gameObject.transform.position);
                        hasMoved = false;
                    }
                }
            }
        }
    }

    public void Restart()
    {
        hasMoved = false;
    }
}

