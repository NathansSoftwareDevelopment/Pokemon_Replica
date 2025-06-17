using UnityEngine;

public class PlayerScript : MonoBehaviour
{
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        Debug.Log(Type.TypeMap["Steel"].AttackingTypeMap["Fighting"]);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
