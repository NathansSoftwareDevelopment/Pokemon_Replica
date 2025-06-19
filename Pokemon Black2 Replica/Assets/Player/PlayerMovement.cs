using System;
using System.Runtime.InteropServices.WindowsRuntime;
using UnityEngine;
using UnityEngine.InputSystem;

public class PlayerMovement : MonoBehaviour
{
    private @PlayerInputs playerInputs;
    Vector2 movementDirection;
    private bool playerCanMove = true;
    [SerializeField] private int movementSpeed = 4;
    private double movementTime = 0;
    private DateTime movedTime = DateTime.Now;
    private DateTime currentTime = DateTime.Now;
    private Rigidbody2D rb;

    private void Awake()
    {
        playerInputs = new @PlayerInputs();
        movementTime = 1.0 / movementSpeed;
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
        if (context.phase.ToString() != "Performed") { }
        else if (playerCanMove)
        {
            movementDirection = context.ReadValue<Vector2>();
            Debug.Log($"Valid Movement! {context.control.displayName} {movementDirection}");
            MovePlayer();
        }
        else
        {
            Debug.Log("Invalid Movement.");
            return;
        }
    }

    private void MovePlayer()
    {
        rb.MovePosition(rb.position + movementDirection);
        movedTime = currentTime;
    }

    private void CheckIfPlayerCanMove()
    {
        currentTime = DateTime.Now;
        playerCanMove = (currentTime - movedTime).TotalSeconds >= movementTime;
    }

    private void Update()
    {
        CheckIfPlayerCanMove();
    }

    private void FixedUpdate()
    {
    }
}