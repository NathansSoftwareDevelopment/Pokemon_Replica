using UnityEngine;
using UnityEngine.InputSystem;

public class PlayerMovement : MonoBehaviour
{
    private @PlayerInputs playerInputs;
    Vector2 movementDirection;
    [SerializeField] private int movementSpeed = 4;
    private double movementTime = 0;
    private double movementCooldown = 0;
    private Rigidbody2D rb;

    private void Awake()
    {
        playerInputs = new @PlayerInputs();
        movementTime = 1.0/movementSpeed;
        rb = GetComponent<Rigidbody2D>();

        playerInputs.Player.Movement.started += OnMovementPerformed;
        playerInputs.Player.Movement.performed += OnMovementPerformed;
        playerInputs.Player.Movement.canceled += OnMovementPerformed;
    }

    private void OnValidate()
    {
        movementTime = 1.0 / movementSpeed;
    }

    private void OnEnable()
    {
        playerInputs.Enable();
    }

    private void OnDisable()
    {
        playerInputs.Disable();
    }

    public void OnMovementPerformed(InputAction.CallbackContext context)
    {
        if (context.phase.ToString() == "Performed")
        {
            movementDirection = context.ReadValue<Vector2>();
            Debug.Log($"Movement {context.control.displayName} {movementDirection}");
        } else
        {
            return;
        }

        if (MovementValid(context))
        {
            rb.MovePosition(rb.position + movementDirection);
            Debug.Log("Valid Movement!");
        }
        else
        {
            Debug.Log("Invalid Movement.");
        }
    }

    private bool MovementValid(InputAction.CallbackContext context)
    {
        if (movementCooldown < movementTime)
        {
            return false;
        } else
        {
            movementCooldown = 0;
            return true;
        }
    }

    private void Update()
    {
        if (movementCooldown < movementTime)
        {
            movementCooldown += Time.deltaTime;
        }
    }
}