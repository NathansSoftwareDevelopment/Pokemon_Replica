using UnityEngine;
using UnityEngine.InputSystem;

public class PlayerMovement : MonoBehaviour
{
    [SerializeField] private int movementSpeed = 4;
    private Vector2 movementDirection;
    private Rigidbody2D rb;

    private void Awake()
    {
        rb = GetComponent<Rigidbody2D>();
    }

    private void OnMovement(InputValue keystroke)
    {
        movementDirection = keystroke.Get<Vector2>();
        Debug.Log("Moved");
    }

    private void FixedUpdate()
    {
        rb.MovePosition(rb.position + movementDirection);
    }
}
