using System.Collections.Generic;
using UnityEngine;

public class Nature
{
    // Automatic Properties
    public string Name { get; }
    public Dictionary<string, double> StatMultipliers { get; } = new Dictionary<string, double>
    {
        {"Attack", 1.0},
        {"Defense", 1.0},
        {"Speed", 1.0},
        {"SpecialAttack", 1.0},
        {"SpecialDefense", 1.0}
    };

    // Constructor
    Nature(string inputNatureName, string inputMultiplier, string inputDivisor)
    {
        Name = inputNatureName;
        if (inputMultiplier != inputDivisor)
        {
            StatMultipliers[inputMultiplier] = 1.1;
            StatMultipliers[inputDivisor] = 0.9;
        }
    }

    // Establish Natures
    public static Dictionary<string, Nature> NatureMap { get; }

    static Nature()
    {
        NatureMap = new Dictionary<string, Nature>
        {
            {"Hardy", new Nature("Hardy", "Attack", "Attack")},
            {"Lonely", new Nature("Lonely", "Attack", "Defense")},
            {"Brave", new Nature("Brave", "Attack", "Speed")},
            {"Adamant", new Nature("Adamant", "Attack", "SpecialAttack")},
            {"Naughty", new Nature("Naughty", "Attack", "SpecialDefense")},
            {"Bold", new Nature("Bold", "Defense", "Attack")},
            {"Docile", new Nature("Docile", "Defense", "Defense")},
            {"Relaxed", new Nature("Relaxed", "Defense", "Speed")},
            {"Impish", new Nature("Impish", "Defense", "SpecialAttack")},
            {"Lax", new Nature("Lax", "Defense", "SpecialDefense")},
            {"Timid", new Nature("Timid", "Speed", "Attack")},
            {"Hasty", new Nature("Hasty", "Speed", "Defense")},
            {"Serious", new Nature("Serious", "Speed", "Speed")},
            {"Jolly", new Nature("Jolly", "Speed", "SpecialAttack")},
            {"Naive", new Nature("Naive", "Speed", "SpecialDefense")},
            {"Modest", new Nature("Modest", "SpecialAttack", "Attack")},
            {"Mild", new Nature("Mild", "SpecialAttack", "Defense")},
            {"Quiet", new Nature("Quiet", "SpecialAttack", "Speed")},
            {"Bashful", new Nature("Bashful", "SpecialAttack", "SpecialAttack")},
            {"Rash", new Nature("Rash", "SpecialAttack", "SpecialDefense")},
            {"Calm", new Nature("Calm", "SpecialDefense", "Attack")},
            {"Gentle", new Nature("Gentle", "SpecialDefense", "Defense")},
            {"Sassy", new Nature("Sassy", "SpecialDefense", "Speed")},
            {"Careful", new Nature("Careful", "SpecialDefense", "SpecialAttack")},
            {"Quirky", new Nature("Quirky", "SpecialDefense", "SpecialDefense")}
        };
    }
}
