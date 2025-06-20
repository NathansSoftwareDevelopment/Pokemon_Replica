using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Pokemon : MonoBehaviour
{
    // Automatic Properties
    // Most types are not yet implemented and have been substituted with strings
    public string Trainer { get; private set; }

    public string Name { get; private set; }
    public string Species { get; private set; }

    public int Level { get; private set; }
    public int Experience { get; private set; }

    public string Nature { get; private set; }

    public string Ability { get; private set; }

    public string Item { get; set; }

    public Type Type1 { get; set; }
    public Type Type2 { get; set; }

    public Dictionary<int, string> Moves { get; private set; }

    public string Condition { get; set; }

    public Dictionary<string, int> IndividualValues { get; private set; } = new Dictionary<string, int>
    {
        {"HitPoints", 0},
        {"Attack", 0},
        {"Defense", 0},
        {"SpecialAttack", 0},
        {"SpecialDefense", 0},
        {"Speed", 0}
    };
    public Dictionary<string, int> EffortValues { get; set; } = new Dictionary<string, int>
    {
        {"HitPoints", 0},
        {"Attack", 0},
        {"Defense", 0},
        {"SpecialAttack", 0},
        {"SpecialDefense", 0},
        {"Speed", 0}
    };

    public Dictionary<string, int> MaxStats { get; private set; } = new Dictionary<string, int>
    {
        {"HitPoints", 1},
        {"Attack", 1},
        {"Defense", 1},
        {"SpecialAttack", 1},
        {"SpecialDefense", 1},
        {"Speed", 1}
    };
    public Dictionary<string, int> CurrentStats { get; private set; } = new Dictionary<string, int>
    {
        {"HitPoints", 1},
        {"Attack", 1},
        {"Defense", 1},
        {"SpecialAttack", 1},
        {"SpecialDefense", 1},
        {"Speed", 1}
    };
    public Dictionary<string, int> CurrentStages { get; private set; } = new Dictionary<string, int>
    {
        {"Attack", 0},
        {"Defense", 0},
        {"SpecialAttack", 0},
        {"SpecialDefense", 0},
        {"Speed", 0},
        {"Accuracy", 0},
        {"Evasion", 0}
    };

    public uint PersonalityValue { get; private set; }

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
