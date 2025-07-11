using System;
using UnityEngine;
using UnityEngine.InputSystem;

public class PlayerMovement : MonoBehaviour
{
    private @PlayerInputs playerInputs;

    Vector2 movementDirection;
    private bool playerCanMove = true;
    private bool playerIsMoving = false;
    private double movementTime = 0;
    private double movementCooldown = 0;
    [SerializeField] private int movementSpeed = 4;
    private Rigidbody2D rb;


    private void Awake()
    {
        playerInputs = new @PlayerInputs();
        movementTime = 1.0 / movementSpeed;
        rb = GetComponent<Rigidbody2D>();

        playerInputs.Player.Movement.started += OnMovementInput;
        playerInputs.Player.Movement.performed += OnMovementInput;
        playerInputs.Player.Movement.canceled += OnMovementInput;
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

    public void OnMovementInput(InputAction.CallbackContext context)
    {
        if (playerCanMove && context.phase.ToString() == "Performed")
        {
            movementDirection = context.ReadValue<Vector2>();
            playerIsMoving = true;
        }
        else if (context.phase.ToString() == "Canceled")
        {
            playerIsMoving = false;
        }
    }

    private void FixedUpdate()
    {
        AccrueTime(Time.fixedDeltaTime);
        CheckIfPlayerCanMove();
        if (playerIsMoving)
        {
            AttemptToMovePlayer();
        }
    }

    private void AccrueTime(double timePassed)
    {
        AddToCooldown(timePassed, ref movementCooldown, movementTime);
    }

    private void AddToCooldown(double timeToAdd, ref double cooldown, double maximum = Double.MaxValue)
    {
        if (cooldown < maximum)
        {
            cooldown += timeToAdd;
        }
    }

    private void CheckIfPlayerCanMove()
    {
        playerCanMove = movementCooldown >= movementTime;
    }

    private void AttemptToMovePlayer()
    {
        if (playerCanMove)
        {
            Debug.Log($"Valid Movement!   {movementDirection}");
            MovePlayer();
        }
        else
        {
            Debug.Log($"Invalid Movement. {movementDirection}");
        }
    }

    private void MovePlayer()
    {
        rb.MovePosition(rb.position + movementDirection);
        movementCooldown = 0;
    }
}