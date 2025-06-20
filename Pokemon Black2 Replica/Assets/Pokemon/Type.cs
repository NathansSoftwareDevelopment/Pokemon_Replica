using System.Collections.Generic;
using UnityEngine;

[System.Serializable]
public class Type
{
    public string Name { get; }
    public Dictionary<string, double> AttackingTypeMap { get; }

    public Type(string typeInputName, Dictionary<string, double> inputAttackingTypeMap)
    {
        Name = typeInputName;
        AttackingTypeMap = inputAttackingTypeMap;
    }

    public static Dictionary<string, Type> TypeMap { get; }

    static Type()
    {
        TypeMap = new Dictionary<string, Type>
        {
            {"Normal", new Type(
                "Normal", new Dictionary<string, double>{
                        {"Normal", 1.0}, {"Fire", 1.0}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 1.0},
                        {"Ice", 1.0}, {"Fighting", 1.0}, {"Poison", 1.0}, {"Ground", 1.0}, {"Flying", 1.0},
                        {"Psychic", 1.0}, {"Bug", 1.0}, {"Rock", 0.5}, {"Ghost", 0.0}, {"Dragon", 1.0},
                        {"Dark", 1.0}, {"Steel", 0.5}, {"None", 1.0}
                    }
                )
            },
            {"Fire", new Type(
                "Fire", new Dictionary<string, double>{
                        {"Normal", 1.0}, {"Fire", 0.5}, {"Water", 0.5}, {"Electric", 1.0}, {"Grass", 2.0},
                        {"Ice", 2.0}, {"Fighting", 1.0}, {"Poison", 1.0}, {"Ground", 1.0}, {"Flying", 1.0},
                        {"Psychic", 1.0}, {"Bug", 2.0}, {"Rock", 0.5}, {"Ghost", 1.0}, {"Dragon", 0.5},
                        {"Dark", 1.0}, {"Steel", 2.0}, {"None", 1.0}
                    }
                )
            },
            {"Water", new Type(
                "Water", new Dictionary<string, double>{
                        {"Normal", 1.0}, {"Fire", 2.0}, {"Water", 0.5}, {"Electric", 1.0}, {"Grass", 0.5},
                        {"Ice", 1.0}, {"Fighting", 1.0}, {"Poison", 1.0}, {"Ground", 2.0}, {"Flying", 1.0},
                        {"Psychic", 1.0}, {"Bug", 1.0}, {"Rock", 2.0}, {"Ghost", 1.0}, {"Dragon", 0.5},
                        {"Dark", 1.0}, {"Steel", 1.0}, {"None", 1.0}
                    }
                )
            },
            {"Electric", new Type(
                "Electric", new Dictionary<string, double>{
                        {"Normal", 1.0}, {"Fire", 1.0}, {"Water", 2.0}, {"Electric", 0.5}, {"Grass", 0.5},
                        {"Ice", 1.0}, {"Fighting", 1.0}, {"Poison", 1.0}, {"Ground", 0.0}, {"Flying", 2.0},
                        {"Psychic", 1.0}, {"Bug", 1.0}, {"Rock", 1.0}, {"Ghost", 1.0}, {"Dragon", 0.5},
                        {"Dark", 1.0}, {"Steel", 1.0}, {"None", 1.0}
                    }
                )
            },
            {"Grass", new Type(
                "Grass", new Dictionary<string, double>{
                        {"Normal", 1.0}, {"Fire", 0.5}, {"Water", 2.0}, {"Electric", 1.0}, {"Grass", 0.5},
                        {"Ice", 1.0}, {"Fighting", 1.0}, {"Poison", 0.5}, {"Ground", 2.0}, {"Flying", 0.5},
                        {"Psychic", 1.0}, {"Bug", 0.5}, {"Rock", 2.0}, {"Ghost", 1.0}, {"Dragon", 0.5},
                        {"Dark", 1.0}, {"Steel", 0.5}, {"None", 1.0}
                    }
                )
            },
            {"Ice", new Type(
                "Ice", new Dictionary<string, double>{
                        {"Normal", 1.0}, {"Fire", 0.5}, {"Water", 0.5}, {"Electric", 1.0}, {"Grass", 2.0},
                        {"Ice", 0.5}, {"Fighting", 1.0}, {"Poison", 1.0}, {"Ground", 2.0}, {"Flying", 2.0},
                        {"Psychic", 1.0}, {"Bug", 1.0}, {"Rock", 1.0}, {"Ghost", 1.0}, {"Dragon", 2.0},
                        {"Dark", 1.0}, {"Steel", 0.5}, {"None", 1.0}
                    }
                )
            },
            {"Fighting", new Type(
                "Fighting", new Dictionary<string, double>{
                        {"Normal", 2.0}, {"Fire", 1.0}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 1.0},
                        {"Ice", 2.0}, {"Fighting", 1.0}, {"Poison", 0.5}, {"Ground", 1.0}, {"Flying", 0.5},
                        {"Psychic", 0.5}, {"Bug", 0.5}, {"Rock", 2.0}, {"Ghost", 0.0}, {"Dragon", 1.0},
                        {"Dark", 2.0}, {"Steel", 2.0}, {"None", 1.0}
                    }
                )
            },
            {"Poison", new Type(
                "Poison", new Dictionary<string, double>{
                        {"Normal", 1.0}, {"Fire", 1.0}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 2.0},
                        {"Ice", 1.0}, {"Fighting", 1.0}, {"Poison", 0.5}, {"Ground", 0.5}, {"Flying", 1.0},
                        {"Psychic", 1.0}, {"Bug", 1.0}, {"Rock", 0.5}, {"Ghost", 0.5}, {"Dragon", 1.0},
                        {"Dark", 1.0}, {"Steel", 0.0}, {"None", 1.0}
                    }
                )
            },
            {"Ground", new Type(
                "Ground", new Dictionary<string, double>{
                        {"Normal", 1.0}, {"Fire", 2.0}, {"Water", 1.0}, {"Electric", 2.0}, {"Grass", 0.5},
                        {"Ice", 1.0}, {"Fighting", 1.0}, {"Poison", 2.0}, {"Ground", 1.0}, {"Flying", 0.0},
                        {"Psychic", 1.0}, {"Bug", 0.5}, {"Rock", 2.0}, {"Ghost", 1.0}, {"Dragon", 1.0},
                        {"Dark", 1.0}, {"Steel", 2.0}, {"None", 1.0}
                    }
                )
            },
            {"Flying", new Type(
                "Flying", new Dictionary<string, double>{
                        {"Normal", 1.0}, {"Fire", 1.0}, {"Water", 1.0}, {"Electric", 0.5}, {"Grass", 2.0},
                        {"Ice", 1.0}, {"Fighting", 2.0}, {"Poison", 1.0}, {"Ground", 1.0}, {"Flying", 1.0},
                        {"Psychic", 1.0}, {"Bug", 2.0}, {"Rock", 0.5}, {"Ghost", 1.0}, {"Dragon", 1.0},
                        {"Dark", 1.0}, {"Steel", 0.5}, {"None", 1.0}
                    }
                )
            },
            {"Psychic", new Type(
                "Psychic", new Dictionary<string, double>{
                        {"Normal", 1.0}, {"Fire", 1.0}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 1.0},
                        {"Ice", 1.0}, {"Fighting", 2.0}, {"Poison", 2.0}, {"Ground", 1.0}, {"Flying", 1.0},
                        {"Psychic", 0.5}, {"Bug", 1.0}, {"Rock", 1.0}, {"Ghost", 1.0}, {"Dragon", 1.0},
                        {"Dark", 0.0}, {"Steel", 0.5}, {"None", 1.0}
                    }
                )
            },
            {"Bug", new Type(
                "Bug", new Dictionary<string, double>{
                        {"Normal", 1.0}, {"Fire", 0.5}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 2.0},
                        {"Ice", 1.0}, {"Fighting", 0.5}, {"Poison", 0.5}, {"Ground", 1.0}, {"Flying", 0.5},
                        {"Psychic", 2.0}, {"Bug", 1.0}, {"Rock", 1.0}, {"Ghost", 0.5}, {"Dragon", 1.0},
                        {"Dark", 2.0}, {"Steel", 0.5}, {"None", 1.0}
                    }
                )
            },
            {"Rock", new Type(
                "Rock", new Dictionary<string, double>{
                        {"Normal", 1.0}, {"Fire", 2.0}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 1.0},
                        {"Ice", 2.0}, {"Fighting", 0.5}, {"Poison", 1.0}, {"Ground", 0.5}, {"Flying", 2.0},
                        {"Psychic", 1.0}, {"Bug", 2.0}, {"Rock", 1.0}, {"Ghost", 1.0}, {"Dragon", 1.0},
                        {"Dark", 1.0}, {"Steel", 0.5}, {"None", 1.0}
                    }
                )
            },
            {"Ghost", new Type(
                "Ghost", new Dictionary<string, double>{
                        {"Normal", 0.0}, {"Fire", 1.0}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 1.0},
                        {"Ice", 1.0}, {"Fighting", 1.0}, {"Poison", 1.0}, {"Ground", 1.0}, {"Flying", 1.0},
                        {"Psychic", 2.0}, {"Bug", 1.0}, {"Rock", 1.0}, {"Ghost", 2.0}, {"Dragon", 1.0},
                        {"Dark", 0.5}, {"Steel", 0.5}, {"None", 1.0}
                    }
                )
            },
            {"Dragon", new Type(
                "Dragon", new Dictionary<string, double>{
                        {"Normal", 1.0}, {"Fire", 1.0}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 1.0},
                        {"Ice", 1.0}, {"Fighting", 1.0}, {"Poison", 1.0}, {"Ground", 1.0}, {"Flying", 1.0},
                        {"Psychic", 1.0}, {"Bug", 1.0}, {"Rock", 1.0}, {"Ghost", 1.0}, {"Dragon", 2.0},
                        {"Dark", 1.0}, {"Steel", 0.5}, {"None", 1.0}
                    }
                )
            },
            {"Dark", new Type(
                "Dark", new Dictionary<string, double>{
                        {"Normal", 1.0}, {"Fire", 1.0}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 1.0},
                        {"Ice", 1.0}, {"Fighting", 0.5}, {"Poison", 1.0}, {"Ground", 1.0}, {"Flying", 1.0},
                        {"Psychic", 2.0}, {"Bug", 1.0}, {"Rock", 1.0}, {"Ghost", 2.0}, {"Dragon", 1.0},
                        {"Dark", 0.5}, {"Steel", 0.5}, {"None", 1.0}
                    }
                )
            },
            {"Steel", new Type(
                "Steel", new Dictionary<string, double>{
                        {"Normal", 1.0}, {"Fire", 0.5}, {"Water", 0.5}, {"Electric", 0.5}, {"Grass", 1.0},
                        {"Ice", 2.0}, {"Fighting", 1.0}, {"Poison", 1.0}, {"Ground", 1.0}, {"Flying", 1.0},
                        {"Psychic", 1.0}, {"Bug", 1.0}, {"Rock", 2.0}, {"Ghost", 1.0}, {"Dragon", 1.0},
                        {"Dark", 1.0}, {"Steel", 0.5}, {"None", 1.0}
                    }
                )
            },
            {"None", new Type(
                "None", new Dictionary<string, double>{
                        {"Normal", 1.0}, {"Fire", 1.0}, {"Water", 1.0}, {"Electric", 1.0}, {"Grass", 1.0},
                        {"Ice", 1.0}, {"Fighting", 1.0}, {"Poison", 1.0}, {"Ground", 1.0}, {"Flying", 1.0},
                        {"Psychic", 1.0}, {"Bug", 1.0}, {"Rock", 1.0}, {"Ghost", 1.0}, {"Dragon", 1.0},
                        {"Dark", 1.0}, {"Steel", 1.0}, {"None", 1.0}
                    }
                )
            }
        };
    }
}